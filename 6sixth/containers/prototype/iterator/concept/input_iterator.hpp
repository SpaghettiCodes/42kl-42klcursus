#ifndef __INPUT_ITERATOR_HPP__
#define __INPUT_ITERATOR_HPP__

#include "iterator.hpp"
// wtf am i doing
namespace ft
{
	template <typename _type>
	class input_iterator
	{
		public:
			input_iterator() {};

			input_iterator(_type *ptr_loc) 
			{
				ptr = ptr_loc;
			}

			input_iterator(input_iterator const &ori) 
			{ 
				ptr = ori.ptr;
			}
	
			~input_iterator() {};

			input_iterator &operator=(input_iterator const &ori) { ptr = ori.ptr; return (*this); };

			bool		operator==(input_iterator const &ori) 
			{ 
				return (ptr == ori.ptr); 
			}
			
			bool		operator!=(input_iterator const &ori) 
			{ 
				return (ptr != ori.ptr); 
			}
			
			input_iterator &operator++() 
			{ 
				this->ptr = this->ptr + 1; 
				return (*this); 
			}
			
			input_iterator &operator++(int) 
			{ 
				input_iterator ret;
				ret = *this; 
				this->ptr = this->ptr + 1; 
				return (ret);
			}
			
			_type		operator*() const { return (*ptr); };

		private:
			_type *ptr;
	};
}

#endif