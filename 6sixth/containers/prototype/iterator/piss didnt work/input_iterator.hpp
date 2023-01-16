#ifndef __INPUT_ITERATOR_HPP__
#define __INPUT_ITERATOR_HPP__

#include "iterator.hpp"
// wtf am i doing
namespace ft
{
	template <typename _type>
	class input_iterator : public ft::iterator<_type>
	{
		public:
			input_iterator() {};
			input_iterator(_type *ptr_loc) : iterator(ptr_loc) {}
			input_iterator(input_iterator const &ori) : iterator(ori.ptr) {}

			~input_iterator() {};

			input_iterator &operator=(input_iterator const &ori) { iterator::ptr = ori.ptr; return (*this); };
			_type	operator*() const { return (*iterator::ptr); };

		private:
			typedef ft::iterator<_type> iterator;

	};
}

#endif