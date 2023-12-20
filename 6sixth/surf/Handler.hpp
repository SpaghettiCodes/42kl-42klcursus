#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <string>
#include <sstream>
#include "Client.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <sys/types.h>
#include <sys/stat.h>

using std::string;

namespace HDE
{
	class Handler
	{
		protected:
			string	dir;
			string	ext;

			string	header;
			string	content;

			Client	&client;

			bool	done;
			bool	chunking;
			int		code;

			bool	is_regularFile(const char *path);
			bool	path_Exist(const char *path);
			string	get_ContentType();
			void	set_Extension(string path);

			void	ErrorDisplay(int error_code);

		public:
			Handler(Client &client, string dir);

			string			GenerateHeader();
			virtual	void	GenerateContent() = 0;
			string			&GetHeader();
			string			&GetContent();

			static	Handler	*dispatcher(Client &client, string request_msg);
	};

	class GetMethod: public Handler
	{
		public:
			GetMethod(Client &client, string dir);
			void	GenerateContent();
	};

	class DeleteMethod: public Handler
	{
		public:
			DeleteMethod(Client &client, string dir);
			void	GenerateContent();

	};

	class PostMethod: public Handler
	{
		public:
			PostMethod(Client &client, string dir);
			void	GenerateContent();
	};
}

#endif