#ifndef __forward_iterator_HPP__
#define __forward_iterator_HPP__

namespace ft
{
	template <class _type>
	class forward_iterator
	{
		public:
			forward_iterator() {};

			forward_iterator(_type *ptr_loc) 
			{
				ptr = ptr_loc;
			}

			forward_iterator(forward_iterator const &ori) 
			{ 
				ptr = ori.ptr;
			}

			~forward_iterator() {};

			forward_iterator &operator=(forward_iterator const &ori) { ptr = ori.ptr; return (*this); };

			bool		operator==(forward_iterator const &ori) 
			{ 
				return (ptr == ori.ptr); 
			}
			
			bool		operator!=(forward_iterator const &ori) 
			{ 
				return (ptr != ori.ptr); 
			}
			
			forward_iterator &operator++() 
			{ 
				this->ptr = this->ptr + 1; 
				return (*this); 
			}
			
			forward_iterator &operator++(int) 
			{ 
				forward_iterator ret;
				ret = *this; 
				this->ptr = this->ptr + 1; 
				return (ret);
			}
			
			_type		&operator*() 
			{ 
				return (*ptr); 
			};

		private:
			_type *ptr;
	};
}

#endif