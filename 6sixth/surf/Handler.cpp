#include "Handler.hpp"

namespace HDE
{
	Handler	*Handler::dispatcher(Client &client, string request_msg)
	{
		std::stringstream reader(request_msg);
		// std::size_t first_line = request_msg.find_first_of("\r\n");
		std::string	command;
		std::string directory;

		// first one is the command
		reader >> command;
		// second one is the dir
		reader >> directory;

		// thats all we need actually :P
		if (command == "GET")
			return new GetMethod(client, directory);
		else if (command == "POST")
			return new PostMethod(client, directory);
		else if (command == "DELETE")
			return new DeleteMethod(client, directory);
		else
			return nullptr;
	}

	void	Handler::ErrorDisplay(int error_code)
	{
		std::stringstream	toopen;
		std::fstream		fd;
		std::string			content;

		this->code = error_code;
		toopen << "./error/" << error_code << ".html";
		fd.open(toopen.str(), std::ios::in);
		if (!fd)
		{
			cerr << RED << "HOW DID WE MESS THIS UP SO BADLY???" << endl;
			return;
		}
		this->ext = ".html";

		// Extraction
		string	buffer;
		while (std::getline(fd, buffer))
			content.append(buffer).append("\n");

		this->content = content;
	}

	string	Handler::get_ContentType()
	{
		std::map<string, string> mime_type{
			{".jpeg", "image/jpeg"},
			{".jpg", "image/jpeg"},
			{".png", "image/png"},
			{".css", "text/css"},
			{".html", "text/html"},
			{".mp4", "video/mp4"},
			{".ico", "image/vnd.microsoft.icon"}
		};

		if (mime_type.find(this->ext) != mime_type.end())
			return mime_type[this->ext];
		return "";
	}

	Handler::Handler(Client &client, string dir): client(client)
	{
		this->dir = dir;
		code = 0;
	}

	bool	Handler::is_regularFile(const char *path)
	{
		// check if a path is a regular file
		struct stat path_stat;

		stat(path, &path_stat);
		return S_ISREG(path_stat.st_mode);
	}

	bool	Handler::path_Exist(const char *path)
	{
		return access(path, F_OK) == 0;
	}

	// note that this will break if
		// - path has no extension
		// - file has no extension, but for some reason, the folder has one
	// sooo uhh, dont do that :P
	void	Handler::set_Extension(string path)
	{
		std::size_t dot_loc = path.find_last_of(".");
		this->ext = path.substr(dot_loc);
	}

	string	Handler::GenerateHeader()
	{
		std::stringstream	header;

		// HTTP Status
		std::map<int, string>	status_code{
			{200, "OK"},
			{404, "Bad Request"}
		};
		header << "HTTP/1.1 " << this->code << " " << status_code[this->code] << "\r\n";

		// Content-Type
		// Ignore if the type is cgi (i have no idea how to deal with that [ebic])
		header << "Content-Type: " << get_ContentType() << "\r\n";

		// Connection: close if there is nothing else to send
		header << "Connection: keep-alive\r\n";

		// Content-Length
		// Ignore if the type is cgi (i have no idea how to deal with that [ebic])
		// remove 4 as there is /r/n in the front and /r/n at the back
		// those 2 are not counted
		header << "Content-Length: " << this->content.length() - 4 << "\r\n";

		this->header = header.str();
		return this->header;
	}

	string	&Handler::GetHeader()
	{
		return header;
	}

	string	&Handler::GetContent()
	{
		return content;
	}

	GetMethod::GetMethod(Client &client, string dir): Handler(client, dir)
	{
	}

	/*
	If a request ends with a slash, NGINX treats it as a request for 
	a directory and tries to find an index file in the directory. 
	The index directive defines the index file’s name 
	(the default value is index.html)

	Else, just use the directory given
	Yes.

	This handles the \r\n after the header, so dont add an extra one
	*/
	void	GetMethod::GenerateContent()
	{
		string			content("\r\n");
		string			to_open = ".";
		std::fstream	fd;
		bool			is_folder;

		to_open.append(this->dir);

		// check if path exist
		// if it doesnt, immediately 404
		if (!path_Exist(to_open.c_str()))
		{
			cerr << RED << "ERROR: File requested not available!" << endl;
			return ErrorDisplay(404);
		}

		// if it isnt a regular file, its probably a directory
		// if it isnt a regular directory, we can actually go cry d
		if (!is_regularFile(to_open.c_str()))
		{
			if (*(to_open.rbegin()) != '/')
				to_open.append("/");
			to_open.append("index.html");
			// if path does not exist, 404
			if (!path_Exist(to_open.c_str()))
			{
				cerr << RED << "ERROR: File requested not available!" << endl;
				return ErrorDisplay(404);
			}
		}

		cout << "File to Open --\n" << to_open << endl;
		fd.open(to_open, std::ios::in);
		set_Extension(to_open);

		// Extraction
		string	buffer;
		while (std::getline(fd, buffer))
			content.append(buffer).append("\n");
		content.append("\r\n");
		this->code = 200;

		this->content = content;
	}

	DeleteMethod::DeleteMethod(Client &client, string dir) : Handler(client, dir)
	{
	}

	void	DeleteMethod::GenerateContent()
	{
	}

	PostMethod::PostMethod(Client &client, string dir) : Handler(client, dir)
	{
	}

	void	PostMethod::GenerateContent()
	{
	}
}