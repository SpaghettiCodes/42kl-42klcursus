#include "Date.hpp"

Date::Date(float year, float month, float day) : error_val(false)
{
	value[0] = year;
	value[1] = month;
	value[2] = day;
};

// pre-req - must have 2 sep seperating the year, month and day
Date::Date(std::string date, char sep)
{
	std::string::iterator	begin = date.begin();
	std::string::iterator	end = date.end();
	std::string::iterator	first = begin + date.find(sep);
	std::string::iterator	second = begin + date.find_last_of(sep);

	value[0] = std::stoi(std::string(begin, first));
	value[1] = std::stoi(std::string(first + 1, second));
	value[2] = std::stoi(std::string(second + 1, end));
};

// for error handling, like a throwaway object
Date::Date(bool error) : error_val(error)
{ };

Date::~Date()
{ };

bool	Date::get_Error() const
{ return (error_val); };

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

// one definition rule???
// https://stackoverflow.com/questions/12802536/c-multiple-definitions-of-operator
std::ostream &operator<<(std::ostream &out, const Date &ref)
{
	out << ref.getYear() << "-";
	out << std::setfill('0') << std::setw(2) << ref.getMonth() << "-";
	out << std::setfill('0') << std::setw(2) << ref.getDay();
	return (out);
}