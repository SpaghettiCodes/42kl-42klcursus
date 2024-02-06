# pragma once

# ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <cctype>
# include <string>
# include <iostream>
# include <exception>

class RPN
{
	public:
		RPN();
		RPN(const RPN &ref);
		~RPN();

		void	run(std::string input);

	private:
		std::stack<int>	numbers;

		void	print_answer();

		bool	get_input(std::string input);
		bool	process_token(char in);

		bool	operand(char input);
		bool	partofoperand(char input);

		int		remove_top_value();

		bool	plus(int scndval);
		bool	minus(int scndval); 
		bool	division(int scndval);
		bool	multi(int scndval);

		bool 	spewerror(std::string msg);
};

# endif