#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include "array.hpp"
#include "random_iterator.hpp"
#include <limits>

// vector

// mostly done, just need to fix const_iterator and add a few more function overloads
// also do initializer_list
// oh, and do emplace also

namespace ft
{
template <class T, class Allocator = std::allocator<T>>
class vector
{
	public:
		typedef T								value_type;
		typedef Allocator						allocator_type;
		typedef std::size_t						size_type;
		typedef std::ptrdiff_t					differece_type;
		typedef value_type&						reference;
		typedef const value_type&				const_reference;
		typedef value_type*						pointer;
		typedef const value_type*				const_pointer;
		typedef ft::random_iterator<T>			iterator;
		typedef ft::random_iterator<const T>	const_iterator;

		vector() : _size(0), _capacity(0) 
		{ _content = alloc.allocate(0); }

		vector(size_type n) : _size(0), _capacity(n) 
		{ _content = alloc.allocate(n); }

		~vector() 
		{
			for (int i = 0; i < _size; ++i)
				alloc.destroy(&_content[i]);
			alloc.deallocate(_content, _capacity);
		}

		void assign(size_type count, const T& value)
		{
			if (_capacity < count)
				reserve(count);
			for (int i = 0; i < count; ++i)
				alloc.construct(&_content[i], value);
			_size = count;
		}

		template <class InputIt>
		void assign(InputIt first, InputIt last)
		{
			int i = 0, count = distance(first, last);
			if (count > _capacity)
				reserve(count);
			for (; first != last; ++first, ++i)
				alloc.construct(&_content[i], (*first));
			_size = i;
		}

		allocator_type get_allocator() const
		{ return (alloc); }

		reference at(size_type pos)
		{
			if (pos >= size())
				throw std::out_of_range("Out of range (vector)");
			return (_content[pos]);
		}

		const_reference at(size_type pos) const
		{
			if (pos >= size())
				throw std::out_of_range("Out of range (vector)");
			return (_content[pos]);
		}

		reference operator[](size_type pos)
		{ return (&_content[pos]); }

		const_reference operator[](size_type pos) const
		{ return (&_content[pos]); }

		reference front()
		{ return (_content[0]); }

		const_reference front() const
		{ return (_content[0]); }

		reference back()
		{ return (_content[_size - 1]); }

		const_reference back() const
		{ return (_content[_size - 1]); }

		T* data()
		{ return (_content); }

		const T* data() const
		{ return (_content); }

		iterator	begin()
		{ return (&_content[0]); }

		iterator	end()
		{ return (&_content[_size]); }

		bool	empty()
		{ return (begin() == end() ); }

		std::size_t	size() const
		{ return (_size); }

		std::size_t max_size()
		{ return (std::numeric_limits<differece_type>::max()); }

		void	reserve(size_type new_cap)
		{
			if (new_cap > max_size())
				throw std::length_error("out of bounds (ft::vector)");
			if (new_cap > _capacity)
				make_dupe(new_cap);
		}

		std::size_t capacity()
		{ return (_capacity); }

		void	shrink_to_fit()
		{	
			if (_size < _capacity)
				make_dupe(_size);
		}

		void	clear()
		{
			erase(begin(), end());
		}

		iterator insert (iterator pos, const T& value)
		{
			differece_type _pos = distance(begin(), pos);

			check_capacity();
			if (_pos >= 0)
			{
				move_element_right(&_content[_pos], &_content[_size], 1);
				alloc.construct(&_content[_pos], value);
				++_size;
			}

			return (&_content[_pos]);
		}

		iterator insert (iterator pos, size_type count, const T& value)
		{
			differece_type _pos = distance(begin(), pos);

			while ( !(check_capacity(count)) ) { }

			if (_pos >= 0)
			{
				pos = begin() + _pos;
				for (int i = 0; i < count; ++i)
					insert(pos, value);
			}
			return (&_content[_pos]);
		}

		template <class InputIt>
		iterator insert (iterator pos, InputIt first, InputIt last)
		{
			size_type elements = distance(first, last);
			differece_type _pos = distance(begin(), pos);

			while (!(check_capacity(elements))) { }
			
			if (_pos >=0)
			{
				pos = begin() + _pos;
				for (; first != last; ++first, --elements)
				{
					insert(pos, *(first));
					++pos;
				}
			}
			return (&_content[_pos]);
		}

		// deal with this later lmao
		// template <class... Args> // wtf is Args&&...
		// iterator emplace( iterator pos, Args&&... args )
		// {
		// 	differece_type _pos = distance(begin, pos);

		// 	alloc.construct(&_content[_pos]);
		// }

		iterator erase( iterator pos )
		{
			differece_type _pos = distance(begin(), pos);

			if (_pos >= 0)
			{
				alloc.destroy(&_content[_pos]);
				if ((_pos + 1) != _size)
					move_element_left(&_content[_pos + 1], &_content[_size], 1);
				--_size;
			}
			return (&_content[_pos]);
		}

		iterator erase( iterator first, iterator last )
		{
			differece_type _len = distance(first, last);

			for (; _len > 0; --_len)
				first = erase(first);
			return (first);
		}

		void	push_back(const T& value)
		{
			check_capacity();
			alloc.construct(&_content[_size], value);
			++_size;
		}

		// probably works...?
		template <class... Args>
		void emplace_back(Args&&... args)
		{
			check_capacity();
			alloc.construct(&_content[_size], std::forward<Args>(args)...);
			++_size;
		}

		void	pop_back()
		{
			if (_size)
			{
				alloc.destroy(&_content[_size - 1]);
				--_size;
			}
		}

		void	resize(size_type count)
		{
			int i = 0;

			if (count > _capacity)
				reserve(count);
			
			// skip first _size elements
			for ( ; i < _size && i < count; ++i) { }

			// additional copies of value / default-inserted elements are appended
			for ( ; i < count ; ++i)
				alloc.construct(&_content[i]);

			// container is reduced to the first count elements
			for ( ; i < _size; ++i)
				erase(&_content[i]);

			_size = count;
		}

		void	resize(size_type count, const value_type& value)
		{
			int i = 0;

			if (count > _capacity)
				reserve(count);
			
			// skip first _size elements
			for ( ; i < _size && i < count; ++i) { }

			// additional copies of value / default-inserted elements are appended
			for ( ; i < count ; ++i)
				alloc.construct(&_content[i], value);

			// container is reduced to the first count elements
			for ( ; i < _size; ++i)
				erase(&_content[i]);

			_size = count;
		}

		void swap( vector& other )
		{
			value_type *temp;

			temp = _content;
			_content = other._content;
			other._content = temp;
		}

	private:

		void	move_element_left(pointer start, pointer end, int diff)
		{
			for (; start != end; ++start)
			{
				alloc.construct((start - diff), *(start));
				// (*(start - diff)) = (*start);
				alloc.destroy(start);
			}
		}

		void	move_element_right(pointer start, pointer end, int diff)
		{
			for (; (start - 1) != end; --end)
			{
				alloc.construct((end + diff), *(end));
				// (*(end + diff)) = (*end);
				alloc.destroy(end); 
			}
		}

		void	transfer_content(pointer to, size_type &to_size, pointer from, size_type &from_size)
		{
			for (int i = 0; (i < to_size && i < from_size); i++)
				alloc.construct(&to[i], from[i]);
				// to[i] = from[i];
		}

		void	make_dupe(size_type new_cap)
		{
			pointer new_array;

			new_array = alloc.allocate(new_cap);
			transfer_content(new_array, new_cap, _content, _size);
			if (_capacity)
				alloc.deallocate(_content, _capacity);
			_content = new_array;
			_capacity = new_cap;
		}

		bool	check_capacity()
		{
			if (_size == _capacity)
			{
				!(_capacity) ? reserve(1) : reserve(_capacity * 2);
				return 0;
			}
			return 1;
		}

		bool	check_capacity(size_type to_add)
		{
			if ((_size + to_add) >= _capacity)
			{
				!(_capacity) ? reserve(1) : reserve(_capacity * 2);
				return 0;
			}
			return 1;
		}

		Allocator		alloc;
		pointer			_content;
		size_type		_size;
		size_type		_capacity;
};
}

#endif