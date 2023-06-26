# ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <array>
#include <deque>

#include <cstdlib>
#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <exception>


class PmergeMe
{
	public:
		PmergeMe();

		typedef typename std::vector<int>		vct;
		typedef typename vct::iterator			vct_iter;

		typedef typename std::deque<int>		dqu;
		typedef typename dqu::iterator			dqu_iter;

		typedef std::chrono::_V2::system_clock::time_point		clock;
		typedef std::chrono::microseconds						ms;

		void	runner(int ac, char **av);
		void	print_val();

	private:
		class	NotAPositiveDigit : public std::exception {
			const char *what() const throw() {
				return ("Not a valid Positive Integer");
			}
		};
	
		class	Group_Iter {
			public:

				Group_Iter(vct_iter start, std::size_t size_) : iter(start), _size(size_)
				{ }

				Group_Iter(Group_Iter start, std::size_t size_)
				{ 
					iter = start.iter;
					_size = size_;
				}

				vct_iter get_start()
				{
					return (iter);
				}

				vct_iter get_end()
				{
					std::ptrdiff_t	skip(_size - 1);
					return (iter + skip);
				}

				bool	operator<(const Group_Iter &compare)
				{ return (*(this->iter) < *(compare.iter)); }

				bool	operator>(const Group_Iter &compare)
				{ return (*(this->iter) > *(compare.iter)); }

				Group_Iter	operator+(std::size_t num)
				{ return (Group_Iter(iter + (num * _size), _size)); }

				std::size_t	size()
				{ return (_size); }

				void	chunk_swap(Group_Iter iter_2)
				{
					vct_iter	one = iter;
					vct_iter	two = iter_2.iter;
					for (std::size_t i = 0; i < _size; ++i)	
					{
						std::iter_swap(one, two);
						++one;
						++two;
					}
				}

				bool 	operator!=(const Group_Iter &compare)
				{ return (this->iter != compare.iter); }

			private:
				vct_iter	iter;
				std::size_t	_size;
		};

		bool	is_numeric(char *stuff);
		void	get_values(int ac, char **av);

		void	print_vct(vct stuff);
		void	print_sorted();
	
		void	vector_runner();
		void	vct_sort(vct_iter begin, vct_iter end);

		std::vector<int>	hard_copy;

		std::vector<int>	vec;
		std::list<int>		lst;
		ms					time_vec;
		ms					time_list;
};

# endif