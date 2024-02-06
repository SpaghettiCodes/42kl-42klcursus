# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <cstdio>
# include <sys/time.h> // gettimeofday is in sys/time.h, and we cant use chrono (c++11)
# include <iostream>

class PmergeMe
{
	public:
		PmergeMe(int ac, char **av);

		void	run();

	private:
		PmergeMe(); // class is not meant to be ran w/o ac av

		bool	is_numeric(char *stuff);
		void	get_values(int ac, char **av);

		template <typename Container>
		void	print_container(Container &container);

		template <typename Container>
		bool	isSorted(Container &container);

		void	print_sorted();
	
		void	vector_runner();
		void	list_runner();
		void	print_time();

		/* Jacobsthal Number */
		int		jacobsthal_num_gen(int n);

		/* Vector Sorting */

								// provides the member types in order to use stl algo
		class vector_intgroup : public std::iterator<std::random_access_iterator_tag, int>
		{
			public:	
				typedef	std::vector<int>::iterator vector_iter;

				vector_intgroup();
				vector_intgroup(vector_iter start, size_t groupsize);
				vector_intgroup(vector_intgroup const &other);
				~vector_intgroup();

				vector_intgroup	&operator=(vector_intgroup const &other);
				vector_intgroup	&operator++();
				vector_intgroup	operator++(int);
				vector_intgroup	&operator--();
				vector_intgroup	operator--(int);
				vector_intgroup	&operator+=(std::ptrdiff_t skip);
				vector_intgroup	&operator-=(std::ptrdiff_t skip);
				vector_intgroup	operator+(std::ptrdiff_t skip);
				vector_intgroup	operator-(std::ptrdiff_t skip);
				size_t			operator-(vector_intgroup &another);
				bool			operator<(vector_intgroup &other);
				bool			operator<=(vector_intgroup &other);
				bool			operator==(vector_intgroup &other);
				bool			operator>(vector_intgroup &other);
				bool			operator>=(vector_intgroup &other);
				int				operator*();

				vector_iter	getStart();
				vector_iter	getEnd();
				size_t		distance(vector_intgroup &other);
				size_t		getSize();

			private:
				vector_iter	ptr;
				size_t		groupsize;
		};

		void	vector_inArrayInsert(std::vector<int> &in, vector_intgroup which, vector_intgroup where);
		void	vector_sortUnsortedValues(std::vector<int> &in, vector_intgroup begin, vector_intgroup end);
		void	vector_ford_john_runner(std::vector<int> &in, vector_intgroup begin, vector_intgroup end);
		void	ford_johnson(std::vector<int> &in);

		/* List Sorting */

		class list_intgroup : public std::iterator<std::bidirectional_iterator_tag, int>
		{
			public:	
				typedef	std::list<int>::iterator list_iter;

				list_intgroup();
				list_intgroup(list_iter start, size_t groupsize);
				list_intgroup(list_intgroup const &other);
				~list_intgroup();

				list_intgroup	&operator=(list_intgroup const &other);
				list_intgroup	&operator++();
				list_intgroup	operator++(int);
				list_intgroup	&operator--();
				list_intgroup	operator--(int);
				list_intgroup	&operator+=(std::ptrdiff_t skip);
				list_intgroup	&operator-=(std::ptrdiff_t skip);
				list_intgroup	operator+(std::ptrdiff_t skip);
				list_intgroup	operator-(std::ptrdiff_t skip);
				size_t			operator-(list_intgroup &another);
				bool			operator==(list_intgroup &other);
				bool			operator!=(list_intgroup &other);
				int				operator*();

				list_iter	getStart();
				list_iter	getEnd();
				size_t		distance(list_intgroup &other);
				size_t		getSize();

			private:
				list_iter	ptr;
				size_t		groupsize;
		};

		list_intgroup	list_inArrayInsert(std::list<int> &in, list_intgroup which, list_intgroup where);
		void			list_sortUnsortedValues(std::list<int> &in, list_intgroup begin, list_intgroup end);
		void			list_ford_john_runner(std::list<int> &in, list_intgroup begin, list_intgroup end);
		void			ford_johnson(std::list<int> &in);

		/* Variables */

		/* Stores av values */
		std::vector<int>	hard_copy;

		/* Copy of the stored av values that are sorted */
		/* Used to check if sorting algorithm sorted the values properly */
		std::vector<int>	vector_sorted_copy;
		std::list<int>		list_sorted_copy;

		/* Containers where algorithm will be applied on */
		std::vector<int>	vec;
		std::list<int>		lst;

		/* Store time result */
		timeval				time_vec_store;
		timeval				time_list_store;

		timeval				time_vec_sort;
		timeval				time_list_sort;

		/* Stores ac av */
		int					ac;
		char				**av;
};

template <typename Container>
void	PmergeMe::print_container(Container &container)
{
	typename Container::iterator	start;
	for (start = container.begin(); start != container.end(); ++start)
		std::cout << *(start) << " ";
	std::cout << std::endl;
}

template <typename Container>
bool	PmergeMe::isSorted(Container &container)
{
	typename Container::iterator	start;
	typename Container::iterator	stop = --container.end();
	typename Container::iterator	next;
	for (start = container.begin(); start != stop; ++start)
	{
		next = start;
		++next;
		if (*start > *next)
			return false;
	} 
	return true;
}

std::ostream	&operator<<(std::ostream &out, timeval &to_print);

# endif