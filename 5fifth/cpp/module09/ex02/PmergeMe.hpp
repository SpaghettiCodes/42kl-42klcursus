# ifndef PMERGEME_HPP
# define PMERGEME_HPP

// i have been holding off using vector FOR THIS, MOMENT, YES, PERFECT
#include <vector>
// NO IDEA WHAT DEQUE DOES
#include <deque>

#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>


class PmergeMe
{
	public:
		typedef std::chrono::_V2::system_clock::time_point		clock;
		typedef std::chrono::microseconds						ms;


		void	get_values(int ac, char **av);

		void	start_sort();

	private:
		std::vector<int>	contain_1;
		std::deque<int>		contain_2;

};

# endif