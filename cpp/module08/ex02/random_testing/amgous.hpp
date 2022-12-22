#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <vector>
#include <iterator>

// testing iterators
template <class TypeA>
class AVeryCoolContainer
{
	public:
	class iterator : public std::iterator<
			std::input_iterator_tag,
			TypeA,
			std::ptrdiff_t,
			TypeA*,
			TypeA&
	>
	{
		public :
			iterator() {};
			iterator(iterator &ori) : _ptr(ori._ptr) {} ;
			iterator &operator=(iterator &ori) {_ptr = ori.ptr;} ;
			iterator &operator++() {_ptr = _ptr + 1; return (*this);} ;
			iterator operator++(int) {iterator save = _ptr; ++_ptr; return (save);} ;
			// iterator &operator--() {_ptr = _ptr - 1; return (_ptr);};
			// iterator operator--(int) {TypeA *save = _ptr; --_ptr; return (save);};
			bool	operator==(iterator const &other) const {return (_ptr == other._ptr);} ;
			bool	operator!=(iterator const &other) const {return (_ptr != other._ptr);} ;
			TypeA	&operator*() const;

		private:
			TypeA *_ptr;
	};
	iterator &begin();
	iterator &end();

	private:
		std::vector
};

#endif 