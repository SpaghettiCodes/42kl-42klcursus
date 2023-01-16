#ifndef __BIDIRECTIONAL_ITERATOR_HPP__
#define __BIDIRECTIONAL_ITERATOR_HPP__

namespace ft
{
	template <typename _type>
	class bidirectional_iterator
	{
		public:
			bidirectional_iterator() {};

			bidirectional_iterator(_type *ptr_loc) 
			{
				ptr = ptr_loc;
			}

			bidirectional_iterator(bidirectional_iterator const &ori) 
			{ 
				ptr = ori.ptr;
			}

			~bidirectional_iterator() {};

			bidirectional_iterator &operator=(bidirectional_iterator const &ori) { ptr = ori.ptr; return (*this); };

			bool		operator==(bidirectional_iterator const &ori) 
			{ 
				return (ptr == ori.ptr); 
			}
			
			bool		operator!=(bidirectional_iterator const &ori) 
			{ 
				return (ptr != ori.ptr); 
			}
			
			bidirectional_iterator &operator++() 
			{ 
				this->ptr = this->ptr + 1; 
				return (*this); 
			}
			
			bidirectional_iterator &operator++(int) 
			{ 
				bidirectional_iterator ret;
				ret = *this; 
				this->ptr = this->ptr + 1; 
				return (ret);
			}

			bidirectional_iterator &operator--() 
			{ 
				this->ptr = this->ptr - 1; 
				return (*this); 
			}
			
			bidirectional_iterator &operator--(int) 
			{ 
				bidirectional_iterator ret;
				ret = *this; 
				this->ptr = this->ptr - 1; 
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