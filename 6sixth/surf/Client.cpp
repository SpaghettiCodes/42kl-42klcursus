#include "Client.hpp"
#include "Handler.hpp"

namespace HDE
{
	// can change
	int	Client::buffer_size = 1000000;

	Client::Client()
	{}

	Client::Client(Client &other)
	{
		*(this) = other;
	}

	Client::Client(int prov_sock) : client_socket(prov_sock)
	{}

	Client::~Client()
	{}

	Client	&Client::operator=(Client &other)
	{
		if (&other != this)
		{
			this->client_socket = other.client_socket;
			this->content = other.content;
		}
		return (*(this));
	}

	// reads data from the socket
	// expect that socket has data to read

	// update, read doesnt work for some reason
	// once fd close it just epicly infinitely loop like theres no tomorrow
	// w e l p
	int	Client::c_read()
	{
		int		len;
		char	buff[Client::buffer_size + 1];

		// clean buffer
		memset(buff, 0, (Client::buffer_size + 1));

		len = recv(this->client_socket, buff, Client::buffer_size, 0);
		cout << GREEN << "Received " << len << " data" << endl;
		// client closed connection :P
		if (len == 0)
		{
			cout << "Nothing to read, returning..." << endl;
			return 0;
		}
		if (len < 0)
		{
			cerr << RED << "big oopsie" << endl;
			return 0;
		}

		buff[len] = '\0';
		this->content.append(buff);
		cout << RESET << endl;
		return (len);
	}

	int	Client::c_process()
	{
		std::stringstream	combiner;
		cout << RESET << endl;
		cout << "----------------------------------------------------" << endl;
		cout << BLUE << "In Client " << client_socket << endl;
		cout << RESET << "----------------------------------------------------" << endl;
		cout << content << endl;
		cout << "----------------------------------------------------" << endl;
		cout << endl;

		// temp
		// content
		Handler	*handle = Handler::dispatcher(*this, content);
		handle->GenerateContent();
		handle->GenerateHeader();

		// combine both header and content
		combiner << handle->GetHeader();
		combiner << handle->GetContent();

		delete handle;
		// temp end

		to_send = combiner.str();
		content.clear();
		return (1);
	}

	int	Client::c_write()
	{
		int	ret;

		cout << GREEN << "Sending response -- " << RESET << endl << to_send << endl;
		ret = send(this->client_socket, to_send.c_str(), (to_send.length() - 1), 0);

		if (ret == -1)
		{
			cout << RED << "Something Went Wrong" << endl;
			return (1);
		}
		cout << GREEN << "Content Sent!, Sent " << ret << " bytes!" << RESET << endl << endl;
		to_send.clear();
		return (0);
	}

	int	Client::get_Socket()
	{
		return (client_socket);
	}

	string	&Client::get_Content()
	{
		return (content);
	}
}