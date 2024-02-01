# include "pmergeme.hpp"
# include <math.h>
# include <string>
# include <iostream>
# include <algorithm>
# include <sys/time.h>

static double
to_microsec(timeval *to_convert)
{
	return ((to_convert->tv_sec * 1000000) + to_convert->tv_usec);
}

static int
timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y)
{
  /* Perform the carry for the later subtraction by updating y. */
  if (x->tv_usec < y->tv_usec) {
    int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
    y->tv_usec -= 1000000 * nsec;
    y->tv_sec += nsec;
  }
  if (x->tv_usec - y->tv_usec > 1000000) {
    int nsec = (x->tv_usec - y->tv_usec) / 1000000;
    y->tv_usec += 1000000 * nsec;
    y->tv_sec -= nsec;
  }

  /* Compute the time remaining to wait.
     tv_usec is certainly positive. */
  result->tv_sec = x->tv_sec - y->tv_sec;
  result->tv_usec = x->tv_usec - y->tv_usec;

  /* Return 1 if result is negative. */
  return x->tv_sec < y->tv_sec;
}

PmergeMe::PmergeMe() : ac(0)
{
}

PmergeMe::PmergeMe(int ac, char **av) : ac(ac), av(av)
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

// temp
void	PmergeMe::print_vct(std::vector<int> stuff)
{
	std::vector<int>::iterator start;
	for (start = stuff.begin(); start != stuff.end(); ++start)
	{
		std::cout << *(start) << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::vector_fordjohn()
{
	vec_ford_johnson(vec, 2, vec.size());
}

void	PmergeMe::vector_runner()
{
	timeval	start;
	timeval	end;

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

	std::cout << "Sorting now ..." << std::endl;
	gettimeofday(&start, NULL);
	vector_fordjohn();
	gettimeofday(&end, NULL);
	std::cout << "Algorithm Completed!" << std::endl;
	std::cout << "Is vector sorted: " << (std::is_sorted(vec.begin(), vec.end()) ? "Yes" : "No") << std::endl;

	timeval_subtract(&time_vec, &end, &start);
	std::cout << "Time taken in microseconds: " << to_microsec(&time_vec) << " µs" << std::endl;
}

void	PmergeMe::run()
{
	get_values(ac, av);
	std::cout << "Unsorted values = ";
	print_val();

	std::cout << "Sorted Values = ";
	print_sorted();

	std::cout << std::endl;

	vector_runner();
}

int	PmergeMe::jacobsthal_num_gen(int n)
{
	return ((pow(2, n) - pow(-1, n)) / 3);
}