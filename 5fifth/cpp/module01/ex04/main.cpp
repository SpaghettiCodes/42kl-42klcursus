#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

// class	ReplaceFile
// {
// 	public:
// 		// constructor
// 		ReplaceFile();
// 		ReplaceFile(std::string filename);
// 		// destructor
// 		~ReplaceFile();

// 		replace(std::string s1, std::string s2);
// 	private:
// 		void	read_and_replace(std::ifstream &in, std::ofstream &out, std::string &toreplace, std::string &replacewith);
// 		int		find(std::string &content, std::string &toreplace, int start);
// 		std::string content;
// 		std::string toreplace;
// 		std::string start;
// };

// I WAS PROUD WITH THIS FUNCTION :(((((((
// int		find(std::string &content, std::string &toreplace, int start)
// {
// 	if (!toreplace.length())
// 		return (-1);

// 	int i, loc, temp;
// 	int next, current;

// 	loc = start - 1;
// 	while (loc < ((int) content.length()))
// 	{
// 		i = 0;
// 		loc = content.find_first_of(toreplace[i], loc + 1);
// 		if (loc == -1)
// 			break ;
	
// 		temp = loc;
// 		while (i < ((int) toreplace.length() - 1))
// 		{
// 			next = content.find_first_of(toreplace[i+1], temp + 1);
// 			current = content.find_first_of(toreplace[i], temp);

// 			if (next - current != 1)
// 				break;

// 			i++;
// 			temp++;
// 		}
		
// 		if (i == ((int) toreplace.length() - 1))
// 			return (loc);
// 	}
// 	return (-1);
// }

void	read_and_replace(std::ifstream &in, std::ofstream &out, std::string &toreplace, std::string &replacewith)
{
	std::string content;

	for (std::string buff; getline(in , buff); )
		content.append(buff.append("\n"));

	for (int i = 0, found = content.find(toreplace); i < (int) content.length(); ) {
		if (i == found)
		{
			out << replacewith;
			i += toreplace.length();
			found = content.find(toreplace, i + 1);
		}
		else
		{
			out << content[i];
			++i;
		}
	}
}

void	copy_to(std::ifstream &infile, std::ofstream &outfile)
{; 
	std::cerr << "Warning: Replacing Nothing" << std::endl;
	for (std::string buff; getline(infile, buff); )
		outfile << buff << "\n";
	return ;
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
	// if (!toreplace.size())
	// 	copy_to(infile, outfile);
	// else
		read_and_replace(infile, outfile, toreplace, replacewith);
	return (0);
}