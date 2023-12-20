#include "WebServer.hpp"

// time before the server removes itself ig
// timeout should be in milliseconds
// the number below is 3 minutes
// int	WebServer::timeout = (3 * 60 * 1000);

// 1 minute
int	WebServer::timeout = (10 * 60 * 1000);

WebServer::WebServer(): client_num(0), server_num(0)
{ }

void	WebServer::RunServer()
{
	bool	stop_server = false;

	if (!server_num)
	{
		cerr << RED << "ERROR: No Servers connected to any Port!\nSet Up Some Servers First!!!" << endl;
		return;
	}

	/*
	POLLING

	long story short, poll loops thru all fds and if a event that we are interested in occured (usually read/write operations), poll() will then return

	When poll() return, we need to figure out in which fd did the event occur
	*/

	fd_list	used_fd;
	int		temp_client, temp_server, total_fd, test_val;
	while (true)
	{
		used_fd = fds;
		temp_client = client_num;
		temp_server = server_num;
		total_fd = temp_client + temp_server;

		cout << RESET << endl;
		cout << CYAN << "Server Stats" << endl;
		cout << CYAN << "No. Server: " << temp_server << endl;
		cout << BLUE << "No. Client: " << temp_client << endl;

		test_val = poll(&used_fd[0], total_fd, WebServer::timeout);
		if (test_val < 0)
		{
			cerr << RED << "Something went wrong" << endl;
			break;
		}
		else if (test_val == 0)
		{
			cout << YELLOW << "Poll timed out, exiting..." << endl;
			break;
		}
		else
		{
			for (int i = 0; i < total_fd; i++)
			{
				// cout << "FD: " << used_fd[i].fd << " revent: " << std::hex << used_fd[i].revents << std::dec << endl << endl;
				// nothing happened
				if (used_fd[i].revents == 0)
					continue;
				// servers
				if (i < server_num)
				{
					// unexpected result (most likely error)
					// since we set socket's interest as POLLIN (and in theory, will never change it)
					if (used_fd[i].revents != POLLIN)
					{
						cerr << RED << "Error at Server Socket with file descriptor " << used_fd[i].fd << endl;
						stop_server = true;
						break;
					}
					// revent is POLLIN
					// accept the incoming request for connection

					// this will only connect one client at a time
					else
					{
						Server	*connecting_server = servers[used_fd[i].fd];
						ConnectClient(*(connecting_server));

						(*Find_Fd(used_fd[i])).events = POLLIN;
					}
				}
				// connected clients
				else
				{
					if (used_fd[i].revents & POLLIN)
					{
						cout << BLUE << "Client At FD " << used_fd[i].fd  << " Has incoming message" << endl; 
						Client	*reading_server = clients[used_fd[i].fd];
						test_val = reading_server->c_read();
						if (test_val > 0)
						{
							(*Find_Fd(used_fd[i])).events = POLLOUT;
						}
						else
						{
							cout << RED << "Server Cant Hear From This FD Anymore! (" 
								<< (*Find_Fd(used_fd[i])).fd << ")" << endl << endl;
							RemoveClient(used_fd[i]);
						}
						cout << RESET << endl;
					}
					// output stuff
					else if (used_fd[i].revents & POLLOUT)
					{
						Client	*writing_server = clients[used_fd[i].fd];
						writing_server->c_process();
						writing_server->c_write();
						(*Find_Fd(used_fd[i])).events = POLLIN;
					}
					else
					{
						cerr << RED << "Error at Client Socket with file descriptor " << used_fd[i].fd << endl;
						if (used_fd[i].revents & POLLHUP)
							cerr << RED << "Client Has Hung Up on Server" << endl;
						cerr << "Removing Client..." << RESET << endl;
						RemoveClient(used_fd[i]);
					}
				}
			}
		}

		if (stop_server)
			break;
	}
}

WebServer::fd_listiter	WebServer::Find_Fd(fd_container tofind)
{
	fd_listiter	ret;

	for (ret = fds.begin(); ret != fds.end(); ++ret)
	{
		if ((*ret).fd == tofind.fd)
			break;
	}
	return (ret);
}

void	WebServer::ConnectServer(int port)
{
	cout << YELLOW << "Connecting a Server to port..." << endl;
	Server	*temp = new Server(port);
	if (!temp->SetUp_Socket())
	{
		delete temp;
		cerr << RED << "Failed to Connect to port! :(" << endl;
		return ;
	}
	
	fd_container	temp2;

	temp2.fd = temp->get_Socket().s_get_fd();
	temp2.events = POLLIN;

	servers.insert(server_node(temp2.fd, temp));
	fds.push_back(temp2);

	++server_num;
	temp->get_Socket().s_test();
}

void	WebServer::ConnectServer(int port, char *ip)
{
	cout << YELLOW << "Connecting a Server..." << endl;
	Server			*temp = new Server(port, ip);
	if (!temp->SetUp_Socket())
	{
		delete temp;
		cerr << RED << "Failed to Connect to port! :(" << endl;
		return ;
	}
	
	fd_container	temp2;

	temp2.fd = temp->get_Socket().s_get_fd();
	temp2.events = POLLIN;

	servers.insert(server_node(temp2.fd, temp));
	fds.push_back(temp2);

	++server_num;
}

// Connects a Client to a specific Server using .accept()
void	WebServer::ConnectClient(Server &server)
{
	cout << YELLOW << "Connecting a Client..." << endl;

	int				fd = server.CreateClient();
	fd_container	temp2;
	Client 			*temp = new Client(fd);

	temp2.fd = fd;
	temp2.events = POLLIN;

	clients.insert(client_node(fd, temp));
	fds.push_back(temp2);

	++client_num;
}

void	WebServer::RemoveClient(fd_container client_fd)
{
	cout << YELLOW << "Removing Client..." << endl;
	if (client_fd.fd < 0)
		return;

	delete clients[client_fd.fd];
	clients.erase(client_fd.fd);

	fd_listiter	to_delete = Find_Fd(client_fd);
	if (to_delete == fds.end())
		return ;
	fds.erase(to_delete);

	close(client_fd.fd);
	--client_num;
}

void	WebServer::for_each_server(server_node &node)
{
	node.second->get_Socket().s_close(); 
	delete node.second;
}

void	WebServer::for_each_client(client_node &node)
{
	if (node.second->get_Socket() > -1)
		close(node.second->get_Socket());
	delete node.second;
}

WebServer::~WebServer()
{
	cout << RED << "Deleting WebServer Instance\nCleaning opened fds" << endl;

	for_each(servers.begin(), servers.end(), for_each_server);
	for_each(clients.begin(), clients.end(), for_each_client);
}