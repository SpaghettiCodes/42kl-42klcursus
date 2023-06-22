#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>

#include "Date.hpp"

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

	private:
		map_type	data;

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