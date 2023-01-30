#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <memory>
#include <iostream>

#include "random_iterator.hpp"

namespace ft
{

	template <typename T, std::size_t _elem_no>
	class array
	{
		public:
			typedef T							_type;
			typedef std::size_t					size_type;
			typedef std::ptrdiff_t				difference_type;
			typedef _type&						reference;
			typedef _type*						pointer; 
			typedef ft::random_iterator<_type>	iterator;

			array() : _size(_elem_no)
			{ _content  = alloc.allocate(_size); }

			array(pointer c_array) : _size(_elem_no)
			{
				// epic undefined behavior moment
				_content  = alloc.allocate(_size);
				try
				{
					for (int i = 0; i < _size ; i++, c_array++)
						_content[i] = (*c_array);
				}
				catch (std::exception &e) { }
			}

			~array()
			{
				alloc.deallocate(_content, _size);
				_content = nullptr;
			}

			array	&operator=(array &rhs)
			{
				for (int i = 0; i < rhs.size; i++)
					_content[i] = rhs._content[i];
			}

			reference	at(std::size_t pos)
			{ 
				if (!(pos < size()))
					throw std::out_of_range();
				return (_content[pos]);
			}

			reference	operator[](std::size_t pos)
			{ return (_content[pos]); }

			reference	front()
			{ return (_content[0]); }

			reference	back()
			{ return (_content[_size - 1]); }

			pointer data()
			{ return (_content); }

			iterator	begin()
			{
				iterator ret;

				ret = &_content[0];
				return ret;
			}

			iterator	end()
			{
				iterator ret;

				ret = &_content[_size];
				return ret;
			}

			bool	empty()
			{
				if (_size)
					return (true);
				return (false);
			}

			std::size_t	size() const
			{ return (_size); }

			std::size_t	max_size() const
			{
				return (_size);
			}

			void	fill(const reference value)
			{
				for (int i = 0; i < _size; i++)
					_content[i] = value;
			}

			void	swap(array &other)
			{
				_type	temp;
	
				for (int i = 0; i < _size; i++)
				{
					temp = _content[i];
					_content[i] = other._content[i];
					other._content[i] = temp;
				}
			}

		private:
			std::allocator<_type>	alloc;
			_type					*_content;
			std::size_t				_size;
	};
}

#endif