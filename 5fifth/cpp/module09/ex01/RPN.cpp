#include "RPN.hpp"

RPN::RPN()
{ }

RPN::RPN(const RPN &ref) : numbers(ref.numbers)
{ }

RPN::~RPN()
{ }

int			RPN::ret_value()
{
	if (numbers.size() > 0)
		return(numbers.top());
	return (spewerror("No Numbers Keyed In!"));
}

bool		RPN::spewerror(std::string msg)
{
	std::cerr << msg << std::endl;
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
	numbers.top() /= scndval;
	return (true);
}

bool		RPN::multi(int scndval)
{
	numbers.top() *= scndval;
	return (true);
}

// here we observe, clownary
// typedef int (*RPN_operation) (void);

// bool	(RPN::*funcptr[4])() = {
// 	&plus,
// 	&minus,
// 	&division,
// 	&multi
// };

bool	RPN::partofoperand(char input)
{
	return (std::string("+-/*").find(input) != std::string::npos);
}

bool	RPN::operand(char input)
{
	if (!partofoperand(input))
		return (spewerror("Invalid Token Detected!"));
	if (numbers.size() < 2)
		return (spewerror("Not Enough Number to Proceed With Operation!"));
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
	// you know theoretically this WONT be called?
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
	for (int i = 0; input[i]; ++i)
	{
		if (input[i] == ' ')
			continue;
		else
		{
			if (!process_token(input[i]))
				return (false);
		}
	}
	return (true);
}

void	RPN::run(std::string input)
{
	if (get_input(input))
		std::cout << ret_value() << std::endl;
}