# include "PmergeMe.hpp"
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

void	PmergeMe::print_sorted()
{
	vector_sorted_copy = hard_copy;
	std::copy(hard_copy.begin(), hard_copy.end(), std::back_inserter(list_sorted_copy));

	std::sort(vector_sorted_copy.begin(), vector_sorted_copy.end());
	list_sorted_copy.sort();

	std::cout << "Vector Container: ";
	print_container(vector_sorted_copy);
	std::cout << "List Container: ";
	print_container(list_sorted_copy);
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
	std::cout << "Is vector sorted: " << (std::is_sorted(vec.begin(), vec.end()) ? "Yes" : "No") << std::endl;
	std::cout << "Sorting now ..." << std::endl;
	gettimeofday(&start, NULL);
	ford_johnson(vec);
	gettimeofday(&end, NULL);
	std::cout << "Algorithm Completed!" << std::endl;
	std::cout << "Is vector sorted: " << (std::is_sorted(vec.begin(), vec.end()) ? "Yes" : "No") << std::endl;
	std::cout << "Is vector correct: " << ((vec == vector_sorted_copy) ? "Yes" : "No") << std::endl;

	timeval_subtract(&time_vec, &end, &start);
	std::cout << "Time taken in microseconds: " << to_microsec(&time_vec) << " µs" << std::endl;
	std::cout << "Time taken in milliseconds: " << to_microsec(&time_vec) / 1000 << " ms" << std::endl;
	std::cout << "Time taken in seconds: " << to_microsec(&time_vec) / 1000000 << " s" << std::endl;
}

void	PmergeMe::list_runner()
{
	timeval	start;
	timeval	end;

	std::cout << "Transferring Data" << std::endl;

	// pov you forgot your ft_containers

	// reserve ALLOCATES MEMORY FOR THE VECTOR
	// resize ALLOWS YOU TO JAM IN MORE VARIABLE IN THE VECTOR
	lst.resize(hard_copy.size());

	std::copy(hard_copy.begin(), hard_copy.end(), lst.begin());

	std::cout << "Transfer done!" << std::endl;
	std::cout << "Is list sorted: " << (std::is_sorted(lst.begin(), lst.end()) ? "Yes" : "No") << std::endl;
	std::cout << "Sorting now ..." << std::endl;
	gettimeofday(&start, NULL);
	ford_johnson(lst);
	gettimeofday(&end, NULL);
	std::cout << "Algorithm Completed!" << std::endl;
	std::cout << "Is list sorted: " << (std::is_sorted(lst.begin(), lst.end()) ? "Yes" : "No") << std::endl;
	std::cout << "Is list correct: " << ((lst == list_sorted_copy) ? "Yes" : "No") << std::endl;

	timeval_subtract(&time_list, &end, &start);
	std::cout << "Time taken in microseconds: " << to_microsec(&time_list) << " µs" << std::endl;
	std::cout << "Time taken in milliseconds: " << to_microsec(&time_list) / 1000 << " ms" << std::endl;
	std::cout << "Time taken in seconds: " << to_microsec(&time_list) / 1000000 << " s" << std::endl;
}

void	PmergeMe::run()
{
	get_values(ac, av);
	std::cout << "Unsorted values = ";
	print_container(hard_copy);

	std::cout << "Sorted Values = ";
	print_sorted();

	std::cout << std::endl;

	std::cout << "--- Vector ---" << std::endl;
	vector_runner();
	std::cout << std::endl;
	std::cout << "--- List ---" << std::endl;
	list_runner();
}

/* Jacobsthal Number */

int	PmergeMe::jacobsthal_num_gen(int n)
{
	return ((pow(2, n) - pow(-1, n)) / 3);
}

/* Vector Sorting */

PmergeMe::vector_intgroup::vector_intgroup() : ptr(), groupsize()
{
}

PmergeMe::vector_intgroup::vector_intgroup(vector_iter start, size_t groupsize) : ptr(start), groupsize(groupsize)
{
}

PmergeMe::vector_intgroup::vector_intgroup(vector_intgroup const &other)
{
	*(this) = other;
}

PmergeMe::vector_intgroup::~vector_intgroup()
{
}

PmergeMe::vector_intgroup	&PmergeMe::vector_intgroup::operator=(vector_intgroup const &other)
{
	if (&other == this)
		return *this;

	this->ptr = other.ptr;
	this->groupsize = other.groupsize;
	return (*this);
}

PmergeMe::vector_intgroup	&PmergeMe::vector_intgroup::operator++()
{
	std::advance(ptr, groupsize);
	return (*(this));
}

PmergeMe::vector_intgroup	PmergeMe::vector_intgroup::operator++(int)
{
	vector_intgroup	save((*this));

	std::advance(ptr, groupsize);
	return (save);
}

PmergeMe::vector_intgroup	&PmergeMe::vector_intgroup::operator--()
{
	std::advance(ptr, -groupsize);
	return (*(this));
}

PmergeMe::vector_intgroup	PmergeMe::vector_intgroup::operator--(int)
{
	vector_intgroup	save((*this));

	std::advance(ptr, -groupsize);
	return (save);
}

PmergeMe::vector_intgroup	&PmergeMe::vector_intgroup::operator+=(std::ptrdiff_t skip)
{
	std::advance(this->ptr, (skip * groupsize));
	return (*this);
}

PmergeMe::vector_intgroup	&PmergeMe::vector_intgroup::operator-=(std::ptrdiff_t skip)
{
	std::advance(this->ptr, -(skip * groupsize));
	return (*this);
}

PmergeMe::vector_intgroup	PmergeMe::vector_intgroup::operator+(std::ptrdiff_t skip)
{
	vector_intgroup	save(*this);

	std::advance(save.ptr, (skip * groupsize));
	return (save);
}

PmergeMe::vector_intgroup	PmergeMe::vector_intgroup::operator-(std::ptrdiff_t skip)
{
	vector_intgroup	save(*this);

	std::advance(save.ptr, -(skip * groupsize));
	return (save);
}

size_t	PmergeMe::vector_intgroup::operator-(PmergeMe::vector_intgroup &another)
{
	return (this->distance(another));
}

bool	PmergeMe::vector_intgroup::operator<(PmergeMe::vector_intgroup &other)
{
	return this->ptr < other.ptr;
}

bool	PmergeMe::vector_intgroup::operator<=(PmergeMe::vector_intgroup &other)
{
	return this->ptr <= other.ptr;
}

bool	PmergeMe::vector_intgroup::operator==(PmergeMe::vector_intgroup &other)
{
	return this->ptr == other.ptr;
}

bool	PmergeMe::vector_intgroup::operator>(PmergeMe::vector_intgroup &other)
{
	return this->ptr > other.ptr;
}

bool	PmergeMe::vector_intgroup::operator>=(PmergeMe::vector_intgroup &other)
{
	return this->ptr >= other.ptr;
}

int	PmergeMe::vector_intgroup::operator*()
{
	vector_iter	last_val = ptr;
	std::advance(last_val, (groupsize - 1));
	return *(last_val);
}

PmergeMe::vector_intgroup::vector_iter	PmergeMe::vector_intgroup::getStart()
{
	return ptr;
}

PmergeMe::vector_intgroup::vector_iter	PmergeMe::vector_intgroup::getEnd()
{
	vector_iter	end_ptr = ptr;
	std::advance(end_ptr, groupsize);
	return end_ptr;
}

size_t	PmergeMe::vector_intgroup::distance(PmergeMe::vector_intgroup &other)
{
	size_t	ptr_distance;

	if (this->ptr < other.ptr)
		ptr_distance = std::distance(ptr, other.ptr);
	else
		ptr_distance = std::distance(other.ptr, ptr);

	return (ptr_distance / groupsize);
}

size_t	PmergeMe::vector_intgroup::getSize()
{
	return groupsize;
}

void	PmergeMe::vector_inArrayInsert(std::vector<int> &in, PmergeMe::vector_intgroup which, PmergeMe::vector_intgroup where)
{
	PmergeMe::vector_intgroup neg_ones(in.insert(
		where.getStart(),
		where.getSize(),
		-1
	), where.getSize());

	if (where < which)
		++which;

	std::swap_ranges(
		which.getStart(),
		which.getEnd(),
		neg_ones.getStart()
	);

	in.erase(
		which.getStart(),
		which.getEnd()
	);
}

void	PmergeMe::vector_sortUnsortedValues(std::vector<int> &in, PmergeMe::vector_intgroup begin, PmergeMe::vector_intgroup end)
{
	size_t	sorted_vals = 2;
	size_t	num_of_groups = begin.distance(end);
	vector_intgroup	unsorted_arr, start;

	for (
		start = begin + 3, unsorted_arr = begin + 2; 
		start < end; 
		start += 2, ++unsorted_arr, ++sorted_vals
	)
		vector_inArrayInsert(in, start, unsorted_arr);

	size_t				saved_val = sorted_vals;
	size_t				unsorted_val = num_of_groups - sorted_vals;
	size_t				counter, previous_jacobthal_number, current_jacobthal_number, j_num, index_to_insert;
	vector_intgroup		to_add;

	j_num = 2;
	previous_jacobthal_number = jacobsthal_num_gen(j_num);
	current_jacobthal_number = jacobsthal_num_gen(j_num);
	counter = current_jacobthal_number;

	for ( ; sorted_vals < num_of_groups; ++sorted_vals)
	{
		index_to_insert = saved_val + (current_jacobthal_number - 1);

		// there is a issue with this
		// in the wikipedia, it states that 
		// -- use a binary search from the start of S up to but not including xi to determine where to insert yi --
		// which basically means my binary search end should be at the larger pair of the element im trying to insert
		// however, this turned out to be a MASSIVE pain in the ass to implement
		// as the elements being inserted everywhere + jacobsthal indexing = impossible to track where the original pair is
		// i can make an array that stores these iterators and their respective pairs
		// but 1. im trying to avoid creating new containers
		// 2. fuck i spent too much time on this i am NOT doing that
		to_add = std::lower_bound(begin, begin + sorted_vals, *(begin + index_to_insert));
		vector_inArrayInsert(in, begin + index_to_insert, to_add);

		--counter;
		if (counter <= previous_jacobthal_number)
		{
			++j_num;
			previous_jacobthal_number = current_jacobthal_number;
			current_jacobthal_number = jacobsthal_num_gen(j_num);
			if (current_jacobthal_number >= unsorted_val)
				current_jacobthal_number = unsorted_val;
			counter = current_jacobthal_number;
		}
	}
}

void	PmergeMe::vector_ford_john_runner(std::vector<int> &in, PmergeMe::vector_intgroup begin, PmergeMe::vector_intgroup end)
{
	bool	has_strangler = begin.distance(end) % 2;

	if (has_strangler)
		end = end - 1;

	size_t	num_of_groups = begin.distance(end);

	if (!num_of_groups)
		return;

	for (vector_intgroup start = begin; start < end; start += 2)
	{
		if (*(start) > *(start + 1))
		{
			std::swap_ranges(
				start.getStart(),
				start.getEnd(),
				(start + 1).getStart()
			);
		}
	}

	size_t	next_size = begin.getSize() * 2;
	vector_ford_john_runner(in, vector_intgroup(begin.getStart(), next_size), vector_intgroup(end.getStart(), next_size));
	vector_sortUnsortedValues(in, begin, end);

	if (has_strangler)
	{
		vector_intgroup to_add = std::lower_bound(begin, end, *(end));
		vector_inArrayInsert(in, end, to_add);
	}
}

void	PmergeMe::ford_johnson(std::vector<int> &in)
{
	// prevent insert from invalidating iterator
	// do not do this :P
	in.reserve(in.size() * 2);
	vector_ford_john_runner(in, vector_intgroup(in.begin(), 1), vector_intgroup(in.end(), 1));
}

/* List Sorting */
// it is strongly advised to implement your algorithm for 
// each container and thus to avoid using a generic function

PmergeMe::list_intgroup::list_intgroup() : ptr(), groupsize()
{
}

PmergeMe::list_intgroup::list_intgroup(list_iter start, size_t groupsize) : ptr(start), groupsize(groupsize)
{
}

PmergeMe::list_intgroup::list_intgroup(list_intgroup const &other)
{
	*(this) = other;
}

PmergeMe::list_intgroup::~list_intgroup()
{
}

PmergeMe::list_intgroup &PmergeMe::list_intgroup::operator=(list_intgroup const &other)
{
	if (&other == this)
		return *this;

	this->ptr = other.ptr;
	this->groupsize = other.groupsize;
	return (*this);
}

PmergeMe::list_intgroup &PmergeMe::list_intgroup::operator++()
{
	std::advance(ptr, groupsize);
	return (*(this));
}

PmergeMe::list_intgroup PmergeMe::list_intgroup::operator++(int)
{
	list_intgroup	save((*this));

	std::advance(ptr, groupsize);
	return (save);
}

PmergeMe::list_intgroup &PmergeMe::list_intgroup::operator--()
{
	std::advance(ptr, -groupsize);
	return (*(this));
}

PmergeMe::list_intgroup PmergeMe::list_intgroup::operator--(int)
{
	list_intgroup	save((*this));

	std::advance(ptr, -groupsize);
	return (save);
}

PmergeMe::list_intgroup &PmergeMe::list_intgroup::operator+=(std::ptrdiff_t skip)
{
	std::advance(this->ptr, (skip * groupsize));
	return (*this);
}

PmergeMe::list_intgroup &PmergeMe::list_intgroup::operator-=(std::ptrdiff_t skip)
{
	std::advance(this->ptr, -(skip * groupsize));
	return (*this);
}

PmergeMe::list_intgroup PmergeMe::list_intgroup::operator+(std::ptrdiff_t skip)
{
	list_intgroup	save(*this);

	std::advance(save.ptr, (skip * groupsize));
	return (save);
}

PmergeMe::list_intgroup PmergeMe::list_intgroup::operator-(std::ptrdiff_t skip)
{
	list_intgroup	save(*this);

	std::advance(save.ptr, -(skip * groupsize));
	return (save);
}

size_t PmergeMe::list_intgroup::operator-(list_intgroup &another)
{
	return (this->distance(another));
}

bool	PmergeMe::list_intgroup::operator==(list_intgroup &other)
{
	return this->ptr == other.ptr;
}

bool	PmergeMe::list_intgroup::operator!=(list_intgroup &other)
{
	return this->ptr != other.ptr;
}

int	PmergeMe::list_intgroup::operator*()
{
	list_iter	last_val = ptr;
	std::advance(last_val, (groupsize - 1));
	return *(last_val);
}

PmergeMe::list_intgroup::list_iter	PmergeMe::list_intgroup::getStart()
{
	return ptr;
}

PmergeMe::list_intgroup::list_iter	PmergeMe::list_intgroup::getEnd()
{
	list_iter	end_ptr = ptr;
	std::advance(end_ptr, groupsize);
	return end_ptr;
}

// get distance of 2 iterator
size_t	PmergeMe::list_intgroup::distance(list_intgroup &other)
{
	size_t	ptr_distance;
	ptr_distance = std::distance(ptr, other.ptr);

	return ((ptr_distance < 0 ? -1 * ptr_distance : ptr_distance) / groupsize);
}

size_t	PmergeMe::list_intgroup::getSize()
{
	return groupsize;
}


PmergeMe::list_intgroup	PmergeMe::list_inArrayInsert(std::list<int> &in, list_intgroup which, list_intgroup where)
{
	list_intgroup return_group = which - 1;

	in.insert(
		where.getStart(),
		which.getStart(),
		which.getEnd()
	);

	std::list<int>::iterator one_last = in.erase(
		which.getStart(),
		which.getEnd()
	);

	return return_group;
};

void	PmergeMe::list_sortUnsortedValues(std::list<int> &in, list_intgroup begin, list_intgroup end)
{
	size_t				num_of_groups = begin.distance(end);
	size_t				count;
	size_t				sorted_vals = 2;
	list_intgroup		unsorted_arr, start;

	count = 0;
	start = begin + 3;
	unsorted_arr = begin + 2;
	while (start != end && num_of_groups > 2)
	{
		if (start == end)
			break;
		if (!(count % 2))
		{
			start = list_inArrayInsert(in, start, unsorted_arr);
			++sorted_vals;
		}
		++start;
		++count;
	}

	size_t		saved_val = sorted_vals;
	size_t		unsorted_val = num_of_groups - sorted_vals;
	size_t		counter, previous_jacobthal_number, current_jacobthal_number, j_num;
	j_num = 2;
	previous_jacobthal_number = 0;
	current_jacobthal_number = jacobsthal_num_gen(j_num);
	counter = current_jacobthal_number;

	list_intgroup		next = begin + saved_val;
	for ( ; sorted_vals < num_of_groups; ++sorted_vals )
	{
		list_intgroup to_add = std::lower_bound(begin, begin + (sorted_vals - 1), *(next));
		next = list_inArrayInsert(in, next, to_add);

		if (to_add == begin)
			begin = list_intgroup(in.begin(), begin.getSize());

		--counter;
		if (counter <= previous_jacobthal_number)
		{
			++j_num;
			previous_jacobthal_number = current_jacobthal_number;
			current_jacobthal_number = jacobsthal_num_gen(j_num);
			if (current_jacobthal_number >= unsorted_val)
				current_jacobthal_number = unsorted_val;
			counter = current_jacobthal_number;
			next = begin + saved_val + (current_jacobthal_number - 1);
		}
	}
}

void	PmergeMe::list_ford_john_runner(std::list<int> &in, list_intgroup begin, list_intgroup end)
{
	size_t	count = 0; // pov: bidirectional iterators
	bool	has_strangler = begin.distance(end) % 2;

	if (has_strangler)
		end = end - 1;

	size_t	num_of_groups = begin.distance(end);

	if (!num_of_groups)
		return;

	count = 0;
	for (list_intgroup start = begin; start != end; ++start, ++count)
	{
		if (!(count % 2) && *(start) > *(start + 1))
		{
			std::swap_ranges(
				start.getStart(),
				start.getEnd(),
				(start + 1).getStart()
			);
		}
	}

	size_t	next_size = begin.getSize() * 2;
	list_ford_john_runner(in, list_intgroup(begin.getStart(), next_size), list_intgroup(end.getStart(), next_size));
	// mm refreshing head again
	begin = list_intgroup(in.begin(), begin.getSize());
	list_sortUnsortedValues(in, begin, end);

	if (has_strangler)
	{
		list_intgroup to_add = std::lower_bound(begin, end, *(end));
		list_inArrayInsert(in, end, to_add);
	}
}

void	PmergeMe::ford_johnson(std::list<int> &in)
{
	list_ford_john_runner(in, PmergeMe::list_intgroup(in.begin(), 1), PmergeMe::list_intgroup(in.end(), 1));
}

// joy, copy paste time
