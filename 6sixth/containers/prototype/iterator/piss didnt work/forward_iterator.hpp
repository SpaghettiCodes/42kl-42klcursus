#ifndef __forward_iterator_HPP__
#define __forward_iterator_HPP__

#include "forward_iterator.hpp"

namespace ft
{
	template <class _type>
	class forward_iterator : public ft::input_iterator<_type>
	{
		public:
			forward_iterator() {};

			forward_iterator(_type *ptr_loc)
			{
				iterator::ptr = ptr_loc;
			}

			forward_iterator(forward_iterator const &ori) 
			{ 
				iterator::ptr = ori.ptr;
			}

			~forward_iterator() {};
			
			_type		&operator*() 
			{ 
				return (*iterator::ptr); 
			};

		private:
			typedef ft::iterator<_type> iterator;

	};
}

#endif