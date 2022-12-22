#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>

class Span
{
	public:
		Span();
		Span(Span const &ori);
		Span(unsigned int const tab_size);
		~Span();

		Span &operator=(Span const &ori);

		void	addNumber(int const to_add);

		int	shortestSpan();
		unsigned int	longestSpan();

		unsigned int	size();
		unsigned int	stored();

	private:

		std::vector<int>	_tab;
		unsigned int		_size;
		unsigned int		_stored;

		class MaxCapacity : public std::exception
		{
			virtual const char* what() const throw() { return ("Max Capacity of storage reached!"); };
		};

		class NotEnoughNum : public std::exception
		{
			virtual const char* what() const throw() { return ("Not Enough Numbers to calculate Span!"); };
		};
};

#endif