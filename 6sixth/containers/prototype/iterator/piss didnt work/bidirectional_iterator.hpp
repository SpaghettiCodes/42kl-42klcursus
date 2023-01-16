#ifndef __BIDIRECTIONAL_ITERATOR_HPP__
#define __BIDIRECTIONAL_ITERATOR_HPP__

#include "forward_iterator.hpp"

namespace ft
{
	template <typename _type>
	class bidirectional_iterator : public forward_iterator<_type>
	{
		public:
			bidirectional_iterator() {};
			bidirectional_iterator(_type *ptr_loc) : forward_iterator<_type>(ptr_loc) {}
			bidirectional_iterator(bidirectional_iterator const &ori)  : forward_iterator<_type>(ori.ptr) {}
			~bidirectional_iterator() {};

			bidirectional_iterator &operator=(bidirectional_iterator const &ori) { iterator::ptr = ori.ptr; return (*this); };
			bidirectional_iterator &operator--() 
			{ 
				iterator::ptr = iterator::ptr - 1; 
				return (*this); 
			}
			bidirectional_iterator &operator--(int) 
			{ 
				bidirectional_iterator ret;
				ret = *this; 
				this->ptr = this->ptr - 1; 
				return (ret);
			}

		private:
			typedef ft::iterator<_type> iterator;
	};
}

#endif