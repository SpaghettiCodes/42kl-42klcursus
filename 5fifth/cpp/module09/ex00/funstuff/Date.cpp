#include "Date.hpp"

Date::Date()
{
	value[0] = 69;
	value[1] = 69;
	value[2] = 69;
}

Date::Date(float year, float month, float day)
{
	value[0] = year;
	value[1] = month;
	value[2] = day;
};

// pre-req - must have 2 sep seperating the year, month and day
Date::Date(std::string date, char sep)
{
	if (!Date::date_check(date, sep))
		throw (Date::InvalidInput());

	std::string::iterator	begin = date.begin();
	std::string::iterator	end = date.end();
	std::string::iterator	first = begin + date.find(sep);
	std::string::iterator	second = begin + date.find_last_of(sep);

	value[0] = std::atoi(std::string(begin, first).c_str());
	value[1] = std::atoi(std::string(first + 1, second).c_str());
	value[2] = std::atoi(std::string(second + 1, end).c_str());
};

Date::~Date()
{ };

bool		Date::date_check(std::string raw, char sep)
{
	raw.replace(raw.find(sep), 1, "");
	raw.replace(raw.find(sep), 1, "");
	return (raw.find_first_not_of("0123456789") == raw.npos);
}

float	Date::getYear() const
{ return(value[0]); };

float	Date::getMonth() const
{ return(value[1]); };

float	Date::getDay() const
{ return(value[2]); };

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

std::string	Date::convt_string(char sep) const
{
	std::stringstream	stream;
	std::string			ret;

	stream << value[0] << sep ;
	stream << std::setfill('0') << std::setw(2) << value[1] << sep;
	stream << std::setfill('0') << std::setw(2) << value[2];
	stream >> ret;
	return (ret);
}

// one definition rule???
// https://stackoverflow.com/questions/12802536/c-multiple-definitions-of-operator
std::ostream &operator<<(std::ostream &out, const Date &ref)
{
	out << ref.getYear() << "-";
	out << std::setfill('0') << std::setw(2) << ref.getMonth() << "-";
	out << std::setfill('0') << std::setw(2) << ref.getDay();
	return (out);
}