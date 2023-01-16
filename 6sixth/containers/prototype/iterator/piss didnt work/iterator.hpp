#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

namespace ft
{
	template <class _type>
	class iterator
	{
		public:
			iterator() {};

			iterator(_type *ptr_loc) 
			{
				ptr = ptr_loc;
			}

			iterator(iterator const &ori) 
			{ 
				ptr = ori.ptr;
			}
	
			~iterator() {};

			iterator &operator=(iterator const &ori) { ptr = ori.ptr; return (*this); };

			bool		operator==(iterator const &ori) 
			{ 
				return (ptr == ori.ptr); 
			}
			
			bool		operator!=(iterator const &ori) 
			{ 
				return (ptr != ori.ptr); 
			}
			
			// this doesnt work REEEEEEEEEEEEEE
			iterator &operator++() 
			{ 
				this->ptr = this->ptr + 1; 
				return (*this); 
			}
			
			iterator &operator++(int) 
			{ 
				iterator ret;
				ret = *this; 
				this->ptr = this->ptr + 1; 
				return (ret);
			}

		protected:
			_type *ptr;
	};
}

#endif