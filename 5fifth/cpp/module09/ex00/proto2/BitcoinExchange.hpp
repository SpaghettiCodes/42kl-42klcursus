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

// here is a very cool fact
// you dont need a Date class ;D
// well i mean date class would BE better buuuut 
// haha funny strings go brr
class BitCoinExchange
{
	public:
		// thou shan'lt use map in future projects
		typedef	std::map<std::string, float>			map_type;
		// okay you basically need this for map to work
		typedef std::pair<std::string, float>			pair_type;	
		typedef std::string::iterator					str_iter;

		bool	generate_dictionary();
		void	print_dictionary();
		void	make_calc(std::string file);

		//temp
		map_type	data;
	private:

		pair_type	make_new_pair(std::string in);

		void		process_line(std::string line);
		std::string	process_date(std::string date_chunk);
		float		process_value(std::string value_chunk);
		void		calculate(std::string date, float value);
		
		bool		spewerror(std::string msg, std::string aspect);

		bool		date_check(const char *raw);
		bool		digit_check(const char *raw);
};

#endif