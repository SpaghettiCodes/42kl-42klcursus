#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : time_vec(0), time_list(0)
{
}

void	PmergeMe::print_val()
{
	print_vct(hard_copy);
}

void	PmergeMe::print_sorted()
{
	std::vector<int>	copy(hard_copy);
	std::sort(copy.begin(), copy.end());

	print_vct(copy);
}

bool	PmergeMe::is_numeric(char *stuff)
{
	std::string	stuff_s(stuff);

	if (stuff_s[0] == '+')
		stuff_s.replace(0, 1, "");
	return (stuff_s.find_first_not_of("0123456789") == stuff_s.npos);
}

void	PmergeMe::get_values(int ac, char **av)
{
	int			val;
	std::string	contents;

	for (int i = 1; i < ac; ++i)
	{
		if (!is_numeric(av[i]))
			throw (PmergeMe::NotAPositiveDigit());

		val = std::atoi(av[i]);
		hard_copy.push_back(val);
	}
}

// wow clock, cock suck my cock
// void	PmergeMe::start_sort()
// {
// 	clock start;
// 	clock stop;
// 	ms duration;

// 	start = std::chrono::high_resolution_clock::now();
// 	std::sort(contain_1.begin(), contain_1.end());
// 	stop = std::chrono::high_resolution_clock::now();
	
// 	duration = std::chrono::duration_cast<ms>(stop - start);
// 	std::cout << "Time take to sort for std::vector = " << duration.count() << " us" << std::endl;

// 	start = std::chrono::high_resolution_clock::now();
// 	std::sort(contain_2.begin(), contain_2.end());
// 	stop = std::chrono::high_resolution_clock::now();

// 	duration = std::chrono::duration_cast<ms>(stop - start);
// 	std::cout << "Time take to sort for std::list = " << duration.count() << " us" << std::endl;
// }

// temp
void	PmergeMe::print_vct(vct stuff)
{
	vct_iter start;
	for (start = stuff.begin(); start != stuff.end(); ++start)
	{
		std::cout << *(start) << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::vector_runner()
{
	std::cout << "Transferring Data" << std::endl;

	// pov you forgot your ft_containers

	// reserve ALLOCATES MEMORY FOR THE VECTOR
	// resize ALLOWS YOU TO JAM IN MORE VARIABLE IN THE VECTOR
	vec.reserve(hard_copy.size());
	vec.resize(hard_copy.size());

	std::copy(hard_copy.begin(), hard_copy.end(), vec.begin());

	std::cout << "Transfer done!" << std::endl;

	print_vct(vec);
	std::cout << std::endl;

	vct_sort();
}

// merge insertion sort -> split - insert - merge - repeat
void	PmergeMe::vct_sort(Group_Iter begin, Group_Iter end)
{
	bool	has_leftovers;
	// Group the elements of into n/2 pairs of elements, 
	// arbitrarily, leaving one element unpaired 
	// if there is an odd number of elements.

	for (Group_Iter start = begin; start != end; start)
	{
		if ((start + 1) >= end) {
			has_leftovers = 1;
			break;
		}

		// Perform n/2 comparisons, one per pair, 
		// to determine the larger of the two elements
		// in each pair.

		if ((start).get_start() > (start + 1).get_start())
			start.chunk_swap(start + 1);
	}

	// Recursively sort n/2 larger elements from each pair,
	// creating a sorted sequence of
	// n/2 of the input elements, in ascending order.

	// wtf how do i do this wts

	// Insert the remaining n/2 elements of N into S, one at a time, with a 
	// specially chosen insertion ordering described below. Use binary search in subsequences of 
	// S (as described below) to determine the position at which each element should be inserted

	// ??? what
}

void	PmergeMe::runner(int ac, char **av)
{
	get_values(ac, av);
	std::cout << "Unsorted values = ";
	print_val();

	std::cout << "Sorted Values = ";
	print_sorted();

	std::cout << std::endl;
	vector_runner();
}