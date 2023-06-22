#include "PmergeMe.hpp"

void	PmergeMe::get_values(int ac, char **av)
{
	int			val;
	std::string	contents;

	for (int i = 1; i < ac; ++i)
	{
		
	}
}

void	PmergeMe::start_sort()
{
	clock start;
	clock stop;
	ms duration;

	start = std::chrono::high_resolution_clock::now();
	std::sort(contain_1.begin(), contain_1.end());
	stop = std::chrono::high_resolution_clock::now();
	
	duration = std::chrono::duration_cast<ms>(stop - start);
	std::cout << "Time take to sort for std::vector = " << duration.count() << " us" << std::endl;

	start = std::chrono::high_resolution_clock::now();
	std::sort(contain_2.begin(), contain_2.end());
	stop = std::chrono::high_resolution_clock::now();

	duration = std::chrono::duration_cast<ms>(stop - start);
	std::cout << "Time take to sort for std::vector = " << duration.count() << " us" << std::endl;
}