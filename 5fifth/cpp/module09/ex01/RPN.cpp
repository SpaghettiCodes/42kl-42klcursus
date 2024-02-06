# include "RPN.hpp"


RPN::RPN()
{ }

RPN::RPN(const RPN &ref) : numbers(ref.numbers)
{ }

RPN::~RPN()
{ }

void			RPN::print_answer()
{
	if (numbers.size() > 0)
	{
		if (numbers.size() > 1)
			std::cout << "Warning: more than one number in stack, displaying number at top of the stack!" << std::endl;
		std::cout << numbers.top() << std::endl;
	}
	else
		spewerror("No Numbers Keyed In!");
}

bool		RPN::spewerror(std::string msg)
{
	// yes, this is weird, but pdf wants your error to go to standard output
	std::cout << msg << std::endl;
	return (false);
}

int			RPN::remove_top_value()
{
	int	scndval = numbers.top();
	numbers.pop();
	return (scndval);
}

bool		RPN::plus(int scndval)
{
	numbers.top() += scndval;
	return (true);
}

bool		RPN::minus(int scndval)
{
	numbers.top() -= scndval;
	return (true);
}

bool		RPN::division(int scndval)
{
	if (scndval == 0)
		throw std::logic_error("Division With Zero Attempted");
	numbers.top() /= scndval;
	return (true);
}

bool		RPN::multi(int scndval)
{
	numbers.top() *= scndval;
	return (true);
}

bool	RPN::partofoperand(char input)
{
	return (std::string("+-/*").find(input) != std::string::npos);
}

bool	RPN::operand(char input)
{
	if (!partofoperand(input))
		throw std::logic_error("Invalid Token");
	if (numbers.size() < 2)
		throw std::logic_error("Not enough numbers to proceed with operation");
	switch (input)
	{
		case '+':
			return (plus(remove_top_value()));
		case '-':
			return (minus(remove_top_value()));
		case '*':
			return (multi(remove_top_value()));
		case '/':
			return (division(remove_top_value()));
	}
	return (false);
}

bool	RPN::process_token(char input)
{
	if (isdigit(input))
	{
		numbers.push(input - '0');
		return (true);
	}
	else
		return (operand(input));
}

bool	RPN::get_input(std::string input)
{
	for (std::string::iterator start = input.begin(); start < input.end(); ++start)
	{
		if (*start == ' ')
			continue;
		else
		{
			if (!process_token(*start))
				return (false);
		}
	}
	return (true);
}

void	RPN::run(std::string input)
{
	if (get_input(input))
		print_answer();
}