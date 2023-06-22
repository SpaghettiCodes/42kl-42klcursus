#include "BitcoinExchange.hpp"

BitCoinExchange::pair_type	BitCoinExchange::make_new_pair(std::string line_read)
{
	str_iter	start = line_read.begin();
	str_iter	comma = line_read.begin() + line_read.find(',');
	str_iter	end = line_read.end();

	std::string	date(std::string(start, comma));
	float		val = std::stof(std::string(comma + 1, end));

	return (BitCoinExchange::pair_type(date, val));
}

void	BitCoinExchange::print_dictionary()
{
	for (map_type::iterator start = data.begin(); start != data.end(); ++start)
	{
		std::cout << "Date : \'" << start->first << "\' Value : " << start->second << std::endl; 
	}
}

bool	BitCoinExchange::generate_dictionary()
{
	int				i = 0;
	std::ifstream	file;

	file.open("data.csv", std::fstream::in);
	if (!file)
	{
		spewerror("How am i suppose to check anything without the data.csv source file??", "");
		return (false);
	}

	for (std::string line; std::getline(file, line); ++i)
	{
		if (i == 0)
			continue;
		data.insert(make_new_pair(line));
	}
	std::cout << "Dictionary Generated! " << i << " Entries Generated!\n" << std::endl;
	return (true);
}

bool	BitCoinExchange::spewerror(std::string msg, std::string aspect)
{
	std::cerr << "Error: " << msg << aspect << std::endl;
	return (false);
}

bool		BitCoinExchange::date_check(const char *raw)
{
	int	dashes = 0;

	for (int i = 0; raw[i]; ++i)
	{
		if (raw[i] == '-')
			++dashes;
		else
			if (!isdigit(raw[i])) return (false);
	}
	return (dashes == 2);
}

std::string	BitCoinExchange::process_date(std::string date_chunk)
{
	if (!date_check(date_chunk.c_str()))
		return (std::string("error"));
	return (date_chunk);
}

bool	BitCoinExchange::digit_check(const char *raw)
{
	int	dots = 0;

	for (int i = (raw[0] == '+' || raw[0] == '-'); raw[i]; ++i)
	{
		if (raw[i] == '.')
			++dots;
		else
			if (!isdigit(raw[i])) return false;
	}
	return (dots <= 1);
}

float	BitCoinExchange::process_value(std::string value_chunk)
{
	if (!digit_check(value_chunk.c_str()))
	{
		spewerror("bad input => ", value_chunk);
		return (-1);
	}

	float	val = std::stof(value_chunk);
	if (val < 0) {
		spewerror("Not a positive number", "");
		return (-1);
	}
	if (val > 1000) {
		spewerror("too large a number :(", "");
		return (-1);
	}
	return (val);
}

void	BitCoinExchange::process_line(std::string line)
{
	if (line.find('|') == std::string::npos)
	{
		spewerror("Bad input => ", line);
		return;
	}

	str_iter	begin = line.begin();
	str_iter	sep = line.begin() + line.find('|');
	str_iter	end = line.end();

	// space before the |
	std::string	date = process_date(std::string(begin, sep - 1));
	if (!date.compare("error"))
		return ;

	// space after the |
	float	value = process_value(std::string(sep + 2, end));
	if (value == -1)
		return ;
	calculate(date, value);
}

void	BitCoinExchange::make_calc(std::string in)
{
	std::ifstream in_file;
	int		i = 0;

	in_file.open(in, std::ifstream::in);
	if (!in_file)
	{
		spewerror("Invalid File Name! =>", in);
		return ;
	}

	for (std::string line; std::getline(in_file, line); ++i)
	{
		if (!i)
			continue;
		process_line(line);
	}
	std::cout << "\n" << i << " Entries generated!" << std::endl;
}

void	BitCoinExchange::calculate(std::string date, float value)
{
	// the lower_bound works by using thoughts and prayers

	// aaand also the fact that data.csv will not have duplicate keys ANNDD the ordering is actually really consistent
	map_type::iterator	rate = (data.find(date) != data.end()) ? data.find(date) : --data.lower_bound(date);

	std::cout << date << " => " << value << " = ";
	std::cout << value * rate->second << std::endl;
}
