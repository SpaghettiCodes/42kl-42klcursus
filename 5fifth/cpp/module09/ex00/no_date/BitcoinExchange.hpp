#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>

// mf this is just a parser fest :(((
class BitCoinExchange
{
	public:
		typedef	std::map<std::string, float>			map_type;
		typedef std::pair<std::string, float>			pair_type;	
		typedef std::string::iterator			str_iter;

		bool	generate_dictionary();
		void	print_dictionary();
		void	make_calc(std::string file);

	private:
		map_type	data;
		bool		error;

		pair_type	make_new_pair(std::string in);

		void		process_line(std::string line);
		std::string	process_date(std::string date_chunk);
		float		process_value(std::string value_chunk);
		void		calculate(std::string, float value);
		
		bool		spewerror(std::string msg, std::string aspect);

		bool		digit_check(std::string raw);
		bool		date_check(std::string raw);

		class InvalidInput : public std::exception
		{
			const char *what() const throw() {
				return ("Invalid Date Input");
			}
		};
};

#endif