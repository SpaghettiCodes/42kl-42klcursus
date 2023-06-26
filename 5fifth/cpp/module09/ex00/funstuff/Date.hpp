#pragma once

#ifndef DATE_HPP
#define DATE_HPP

#include <string>
#include <iomanip>
#include <sstream>


// you know the good thing about having a date class is 
// - cleaner
// - easy to manage
// - expendable

// unfortunately imlazy
class Date
{
	public:
		Date();
		Date(float year, float month, float day);
		Date(std::string date, char sep);
		~Date();

		static bool	date_check(std::string raw, char sep);
		float		getYear() const;
		float		getMonth() const;
		float		getDay() const;
		std::string	convt_string(char sep) const;

		bool	operator==(const Date &other) const;
		bool	operator<(const Date &other) const;
		bool	operator>(const Date &other) const;
		bool	operator>=(const Date &other) const;
		bool	operator<=(const Date &other) const;
	private:
		int		value[3];

		class InvalidInput : public std::exception
		{
			const char *what() const throw() {
				return ("Invalid Input");
			}
		};
};

std::ostream &operator<<(std::ostream &out, const Date &ref);

#endif