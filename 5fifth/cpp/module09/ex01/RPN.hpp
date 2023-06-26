# pragma once

# ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <cctype>
#include <string>
#include <iostream>

class RPN
{
	public:
		RPN();
		RPN(const RPN &ref);
		~RPN();

		void	run(std::string input);
		int		ret_value();

	private:
		// thou shalnt use stack (and deque) in future projects
		std::stack<int>	numbers;

		// token processing
		bool	get_input(std::string input);
		bool	process_token(char in);

		// operands
		bool	operand(char input);
		bool	partofoperand(char input);

		int		remove_top_value();

		bool	plus(int scndval);
		bool	minus(int scndval); 
		bool	division(int scndval);
		bool	multi(int scndval);

		// angry error messages
		bool 	spewerror(std::string msg);
};

# endif