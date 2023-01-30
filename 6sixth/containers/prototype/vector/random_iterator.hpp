#ifndef __RANDOM_ITERATOR_HPP__
#define __RANDOM_ITERATOR_HPP__

#include <iterator>

// wow i wonder how im gonna implement const interators aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
namespace ft
{
template <typename InputIt>
std::ptrdiff_t distance(InputIt first, InputIt last)
{
	std::ptrdiff_t count = 0;
	for (; first != last; ++first)
		++count;
	return (count);
}

template <typename _type>
class random_iterator
{
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef _type							value_type;
		typedef	std::ptrdiff_t					distance;
		typedef _type*							pointer;
		typedef _type&							reference;

		random_iterator() {}

		random_iterator(value_type *ptr_loc) 
		{ ptr = ptr_loc; }

		random_iterator(random_iterator const &ori) 
		{ ptr = ori.ptr; }

		~random_iterator() {}

		random_iterator &operator=(random_iterator const &ori) 
		{ ptr = ori.ptr; return (*this); }

		bool		operator==(random_iterator const &ori) const
		{ return (ptr == ori.ptr); }
		
		bool		operator!=(random_iterator const &ori) const
		{ return (ptr != ori.ptr); }
		
		bool		operator<=(random_iterator const &ori) const
		{ return (ptr <= ori.ptr); }

		bool		operator>=(random_iterator const &ori) const
		{ return (ptr >= ori.ptr); }

		bool		operator<(random_iterator const &ori) const
		{ return (ptr < ori.ptr); }

		bool		operator>(random_iterator const &ori) const
		{ return (ptr > ori.ptr); }

		random_iterator &operator++()
		{ 
			this->ptr = this->ptr + 1; 
			return (*this); 
		}
		
		random_iterator operator++(int) 
		{ 
			random_iterator ret;

			ret = *this; 
			this->ptr = this->ptr + 1; 
			return (ret);
		}

		random_iterator &operator+=(int n) 
		{ 
			this->ptr = this->ptr + n;  
			return (*this); 
		}

		random_iterator operator+(int n) const
		{ 
			random_iterator ret;

			ret.ptr = this->ptr + n; 
			return (ret);
		}

		random_iterator &operator--() 
		{ 
			this->ptr = this->ptr - 1; 
			return (*this); 
		}
		
		random_iterator operator--(int) 
		{ 
			random_iterator ret;

			ret = *this; 
			this->ptr = this->ptr - 1; 
			return (ret);
		}

		random_iterator &operator-=(int n) 
		{ 
			this->ptr = this->ptr - n; 
			return (*this); 
		}

		random_iterator operator-(int n) const
		{ 
			random_iterator ret;

			ret.ptr = this->ptr - n; 
			return (ret);
		}

		reference operator[](int n) const
		{ return (*(ptr + n)); }

		reference operator*() const
		{ return (*ptr);};

	private:
		_type *ptr;
};
}

#endif