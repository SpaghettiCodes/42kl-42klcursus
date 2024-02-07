#include <vector>
#include <iostream>

class	Group_Iter {
	public:

		typedef typename std::vector<int>		vct;
		typedef typename vct::iterator			vct_iter;

		Group_Iter() : _size(0)
		{ }

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
		{ return ((this->iter) < (compare.iter)); }

		bool	operator>(const Group_Iter &compare)
		{ return ((this->iter) > (compare.iter)); }

		bool	operator>=(const Group_Iter &compare)
		{ return ((this->iter) >= (compare.iter)); }

		bool	operator<=(const Group_Iter &compare)
		{ return ((this->iter) <= (compare.iter)); }

		void	operator=(const Group_Iter &from)
		{
			this->iter = from.iter;
			this->_size = from._size;
		}

		Group_Iter&	operator++()
		{
			*(this) = *(this) + 1;
			return (*this);
		}

		Group_Iter	operator+(std::size_t num)
		{ return (Group_Iter(iter + (num * _size), _size)); }

		Group_Iter	operator-(std::size_t num)
		{ return (Group_Iter(iter - (num * _size), _size)); }

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

		std::size_t	distance(Group_Iter iter_2)
		{
			return ((iter_2.iter - this->iter) / _size);
		}

		bool 	operator!=(const Group_Iter &compare) 
		{ return (this->iter != compare.iter); }

	private:
		vct_iter	iter;
		std::size_t	_size;
};