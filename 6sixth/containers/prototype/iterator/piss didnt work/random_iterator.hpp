#ifndef __RANDOM_ITERATOR_HPP__
#define __RANDOM_ITERATOR_HPP__

#include "forward_iterator.hpp"

namespace ft
{
	template <typename _type>
	class random_iterator : public ft::bidirectional_iterator<_type>
	{
		public:
			random_iterator() {};

			random_iterator(_type *ptr_loc) : bidirectional_iterator<_type>(ptr_loc) {}

			random_iterator(random_iterator const &ori) : bidirectional_iterator<_type>(ori) {}

			~random_iterator() {};

			random_iterator &operator=(random_iterator const &ori) { iterator::ptr = ori.ptr; return (*this); };
			
			bool		operator<=(random_iterator const &ori) 
			{ 
				return (iterator::ptr <= ori.ptr); 
			}

			bool		operator>=(random_iterator const &ori) 
			{ 
				return (iterator::ptr >= ori.ptr); 
			}

			bool		operator<(random_iterator const &ori) 
			{ 
				return (iterator::ptr < ori.ptr); 
			}

			bool		operator>(random_iterator const &ori) 
			{ 
				return (iterator::ptr > ori.ptr); 
			}

			random_iterator &operator+=(int n) 
			{ 
				iterator::ptr = iterator::ptr + n;  
				return (*this); 
			}

			random_iterator operator+(int n) 
			{ 
				random_iterator ret;

				ret.ptr = iterator::ptr + n; 
				return (ret);
			}

			random_iterator &operator-=(int n) 
			{ 
				iterator::ptr = iterator::ptr - n; 
				return (*this); 
			}

			random_iterator operator-(int n) 
			{ 
				random_iterator ret;

				ret.ptr = iterator::ptr - n; 
				return (ret);
			}

			_type &operator[](int n)
			{
				return (*(iterator::ptr + n));
			}

		private:
			typedef ft::iterator<_type> iterator;
	};
}

#endif