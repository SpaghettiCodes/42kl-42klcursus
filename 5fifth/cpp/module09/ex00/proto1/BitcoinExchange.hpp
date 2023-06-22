#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cctype>
#include <limits>
#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>

class Date
{
	public:
		Date(float year, float month, float day) : error_val(false)
		{
			value[0] = year;
			value[1] = month;
			value[2] = day;
		};

		// pre-req , must have 2 sep seperating the year, month and day
		Date(std::string date, char sep)
		{
			std::string::iterator	begin = date.begin();
			std::string::iterator	end = date.end();
			std::string::iterator	first = begin + date.find(sep);
			std::string::iterator	second = begin + date.find_last_of(sep);

			value[0] = std::stoi(std::string(begin, first));
			value[1] = std::stoi(std::string(first + 1, second));
			value[2] = std::stoi(std::string(second + 1, end));
		};

		Date(bool error) : error_val(error)
		{ };

		~Date()
		{ };

		bool	get_Error() const
		{ return (error_val); };
		
		float	getYear() const
		{ return(value[0]); };

		float	getMonth() const
		{ return(value[1]); };

		float	getDay() const
		{ return(value[2]); };

		bool	operator==(const Date &other) const
		{
			for (int i = 0; i < 3; ++i)
				if (other.value[i] != this->value[i])
					return false;
			return true;
		}

		// a is earlier than b  a < b
		bool	operator<(const Date &other) const
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

		bool	operator>(const Date &other) const
		{
			if (other == *(this))
				return false;
			return (other < *(this));
		}

		bool	operator>=(const Date &other) const
		{
			if (other == *(this))
				return true;
			return (*(this) > other);
		}

		bool	operator<=(const Date &other) const
		{
			if (other == *(this))
				return true;
			return (*(this) < other);
		}

	private:
		int		value[3];
		bool	error_val;
};

std::ostream &operator<<(std::ostream &out, const Date &ref);

// mf this is just a parser fest :(((
class BitCoinExchange
{
	public:
		typedef	std::map<Date, float>			map_type;
		typedef std::pair<Date, float>			pair_type;	
		typedef std::string::iterator			str_iter;

		bool	generate_dictionary();
		void	print_dictionary();
		void	make_calc(std::string file);

		//temp
		map_type	data;
	private:

		pair_type	make_new_pair(std::string in);

		void		process_line(std::string line);
		Date		process_date(std::string date_chunk);
		float		process_value(std::string value_chunk);
		void		calculate(Date date, float value);
		
		bool		spewerror(std::string msg, std::string aspect);

		bool		date_check(const char *raw);
		bool		digit_check(const char *raw);
};

#endif