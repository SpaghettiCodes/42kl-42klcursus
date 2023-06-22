#pragma once

#ifndef DATE_HPP
#define DATE_HPP

#include <string>
#include <iomanip>


// you know the good thing about having a date class is 
// - cleaner
// - easy to manage
// - expendable

// unfortunately imlazy
class Date
{
	public:
		Date(float year, float month, float day);
		Date(std::string date, char sep);
		Date(bool error);
		~Date();

		bool	get_Error() const;
		float	getYear() const;
		float	getMonth() const;
		float	getDay() const;

		bool	operator==(const Date &other) const;
		bool	operator<(const Date &other) const;
		bool	operator>(const Date &other) const;
		bool	operator>=(const Date &other) const;
		bool	operator<=(const Date &other) const;
	private:
		int		value[3];
		bool	error_val;
};

std::ostream &operator<<(std::ostream &out, const Date &ref);

#endif