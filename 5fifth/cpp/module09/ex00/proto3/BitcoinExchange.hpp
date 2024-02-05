# pragma once
# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cctype>
# include <limits>
# include <fstream>
# include <map>
# include <iostream>
# include <string>
# include <iomanip>

// decide to stick to Date class since i feel better
class Date
{
	public:
		Date(std::size_t year, std::size_t month, std::size_t day);
		Date(std::string date, char sep);
		Date(bool error);
		~Date();

		bool		getError() const;
		std::string	getString() const;
		float		getYear() const;
		float		getMonth() const;
		float		getDay() const;

		bool	operator==(const Date &other) const;
		bool	operator<(const Date &other) const;
		bool	operator>(const Date &other) const;
		bool	operator>=(const Date &other) const;
		bool	operator<=(const Date &other) const;

	private:
		std::size_t		value[3];
		bool			error_flag;
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
		void	make_calc(std::string file);

		//temp
		map_type	data;

	private:

		pair_type	make_new_pair(std::string in);

		bool		process_line(std::string line);
		Date		process_date(std::string date_chunk);
		float		process_value(std::string value_chunk);
		void		calculate(Date date, float value);
		
		bool		spewerror(std::string msg, std::string aspect);

		bool		date_check(const char *raw);
};

#endif