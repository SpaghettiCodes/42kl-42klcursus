#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

void	read_and_replace(std::ifstream &in, std::ofstream &out, std::string &toreplace, std::string &replacewith)
{
	std::string content;

	for (std::string buff; getline(in , buff); )
		content.append(buff.append("\n"));

	for (
			std::size_t start = 0, found = content.find(toreplace, start);
			start < content.length();
			found = content.find(toreplace, start + 1)
		)
	{
		if (found == std::string::npos)
		{
			out << content.substr(start, (content.length() - start));
			break;
		}
		out << content.substr(start, (found - start));
		out << replacewith;
		start = found + toreplace.length();
	}
}

// av[1] = filename
// av[2] = toreplace
// av[3] = replace with
int main(int ac, char **av)
{
	if (ac < 4)
	{
		std::cerr << "Not enough arguments \n\nUsage : \n./test <file name> <phrase to replace> <phrase to replace with>" << std::endl;
		return (4);
	}

	std::ifstream	infile;
	std::ofstream	outfile;

	std::string		filename = av[1];
	std::string		toreplace = av[2];
	std::string		replacewith = av[3];

	infile.open(av[1], std::ios::in);
	if (!infile)
	{
		std::cerr << "File cant be opened" << std::endl;
		return (-1);
	}
	filename.append(".replace");
	outfile.open(filename.c_str(), std::ios::out | std::ios::trunc);
	read_and_replace(infile, outfile, toreplace, replacewith);
	return (0);
}