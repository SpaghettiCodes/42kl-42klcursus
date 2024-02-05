# include "BitcoinExchange.hpp"
# include <algorithm>

static
std::string	strstrip(std::string &base, char to_strip)
{
	if (!base.length())
		return "";

	size_t start = base.find_first_not_of(to_strip);
	size_t end = base.find_last_not_of(to_strip) + 1;

	if (start == std::string::npos)
		start = base.length();
	if (end == std::string::npos)
		end = base.length();

	return base.substr(start, (end - start));
}

Date::Date(std::size_t year, std::size_t month, std::size_t day) : error_flag(false)
{
	value[0] = year;
	value[1] = month;
	value[2] = day;
}

// pre-req , must have 2 sep seperating the year, month and day
Date::Date(std::string date, char sep) : error_flag(false)
{
	date = strstrip(date, ' ');

	if (std::count(date.begin(), date.end(), '-') > 2)
	{
		error_flag = true;
		return ;
	}

	std::string::iterator	begin = date.begin();
	std::string::iterator	end = date.end();
	std::string::iterator	first = begin + date.find(sep);
	std::string::iterator	second = begin + date.find_last_of(sep);

	try
	{
		value[0] = std::stoi(std::string(begin, first));
		value[1] = std::stoi(std::string(first + 1, second));
		value[2] = std::stoi(std::string(second + 1, end));
	}
	catch(const std::exception& e)
	{
		error_flag = true;
	}
};

Date::~Date()
{
};

std::string	Date::getString() const
{
	std::stringstream	out;
	out << value[0] << "-" << value[1] << "-" << value[2];
	return (std::string(out.str()));
}

bool	Date::getError() const
{
	return (error_flag);
};

float	Date::getYear() const
{
	return(value[0]);
};

float	Date::getMonth() const
{
	return(value[1]);
};

float	Date::getDay() const
{
	return(value[2]);
};

bool	Date::operator==(const Date &other) const
{
	for (int i = 0; i < 3; ++i)
		if (other.value[i] != this->value[i])
			return false;
	return true;
}

// a is earlier than b  a < b
bool	Date::operator<(const Date &other) const
{
	for (int i = 0; i < 3; ++i)
	{
		if (this->value[i] < other.value[i])
			return true;
		else if (this->value[i] > other.value[i])
			return false;
	}
	return (false);
}

bool	Date::operator>(const Date &other) const
{
	if (other == *(this))
		return false;
	return (other < *(this));
}

bool	Date::operator>=(const Date &other) const
{
	if (other == *(this))
		return true;
	return (*(this) > other);
}

bool	Date::operator<=(const Date &other) const
{
	if (other == *(this))
		return true;
	return (*(this) < other);
}

BitCoinExchange::pair_type	BitCoinExchange::make_new_pair(std::string line_read)
{
	str_iter	start = line_read.begin();
	str_iter	comma = line_read.begin() + line_read.find(',');
	str_iter	end = line_read.end();

	Date	date(std::string(start, comma), '-');
	float	val = std::stof(std::string(comma + 1, end));

	return (BitCoinExchange::pair_type(date, val));
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
	std::cerr << "Error: " << msg << ( aspect.size() ? " => " : "" ) << aspect << std::endl;
	return (false);
}

Date	BitCoinExchange::process_date(std::string date_chunk)
{
	return (Date(date_chunk, '-'));
}

float	BitCoinExchange::process_value(std::string strfloat)
{
	float	val;
	strfloat = strstrip(strfloat, ' ');

	if (!strfloat.length()) {
		spewerror("value not given", "");
		return (-1);
	}

	try {
		val = std::stof(strfloat);
	}
	catch (const std::exception& e) {
		spewerror("bad input", strfloat);
		return (-1);
	}
	
	if (val < 0) {
		spewerror("Not a positive number", strfloat);
		return (-1);
	}
	if (val > 1000) {
		spewerror("Number is too large", strfloat);
		return (-1);
	}
	return (val);
}

bool	BitCoinExchange::process_line(std::string line)
{
	if (line.find('|') == std::string::npos)
		return spewerror("Bad input", line);

	str_iter	begin = line.begin();
	str_iter	sep = line.begin() + line.find('|');
	str_iter	end = line.end();

	if (begin == sep)
		return spewerror("Date not given", line);

	// space before the |
	Date	date = process_date(std::string(begin, sep));
	if (date.getError())
		return spewerror("Bad input", std::string(begin, sep));

	// space after the |
	float	value = process_value(std::string(sep + 1, end));
	if (value == -1)
		return false;

	calculate(date, value);
	return true;
}

void	BitCoinExchange::make_calc(std::string in)
{
	std::ifstream in_file;
	int		i = 0;

	in_file.open(in, std::ifstream::in);
	if (!in_file)
	{
		spewerror("Invalid File Name!", in);
		return ;
	}

	for (std::string line; std::getline(in_file, line); ++i)
	{
		if (!i)
			continue;
		process_line(line);
	}
	std::cout << "\n" << (i - 1) << " Entries generated!" << std::endl;
}

void	BitCoinExchange::calculate(Date date, float value)
{
	// The lower_bound() method in C++ is used to return an iterator pointing to the first element in the range
	// which has a value not less than val.

	// function returns an iterator pointing to the next smallest
	// number just greater than or equal to that number.

	float	rate;
	if (data.find(date) != data.end())
		rate = data.find(date)->second;
	else
	{
		map_type::reverse_iterator	closest(data.lower_bound(date));
		if (closest == data.rend()) {
			spewerror("Date out of range", date.getString());
			return ;
		}
		rate = closest->second;
	}

	std::cout << date << " => " << std::fixed << std::setprecision(2) << value << " = ";
	std::cout << value * rate << std::endl;
	std::cout << std::resetiosflags(std::_S_floatfield) << std::setprecision(6);
}

// what the hell is a one definition rule???
// https://stackoverflow.com/questions/12802536/c-multiple-definitions-of-operator
std::ostream &operator<<(std::ostream &out, const Date &ref)
{
	out << std::setfill('0') << std::setw(4) << ref.getYear() << "-";
	out << std::setfill('0') << std::setw(2) << ref.getMonth() << "-";
	out << std::setfill('0') << std::setw(2) << ref.getDay();
	return (out);
}