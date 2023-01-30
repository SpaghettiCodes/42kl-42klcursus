#ifndef __RANDOM_ITERATOR_HPP__
#define __RANDOM_ITERATOR_HPP__

namespace ft
{
	template <typename _type>
	class random_iterator
	{
		public:
			random_iterator() {};

			random_iterator(_type *ptr_loc) 
			{ ptr = ptr_loc; }

			random_iterator(random_iterator const &ori) 
			{ ptr = ori.ptr; }

			~random_iterator() {};

			random_iterator &operator=(random_iterator const &ori) { ptr = ori.ptr; return (*this); };

			bool		operator==(random_iterator const &ori) 
			{ return (ptr == ori.ptr); }
			
			bool		operator!=(random_iterator const &ori) 
			{ return (ptr != ori.ptr); }
			
			bool		operator<=(random_iterator const &ori) 
			{ return (ptr <= ori.ptr); }

			bool		operator>=(random_iterator const &ori) 
			{ return (ptr >= ori.ptr); }

			bool		operator<(random_iterator const &ori) 
			{ return (ptr < ori.ptr); }

			bool		operator>(random_iterator const &ori) 
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

			random_iterator operator+(int n) 
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

			random_iterator operator-(int n) 
			{ 
				random_iterator ret;

				ret.ptr = this->ptr - n; 
				return (ret);
			}

			_type &operator[](int n)
			{ return (*(ptr + n)); }

			_type		&operator*() 
			{ return (*ptr); }

		private:
			_type *ptr;
	};
}

#endif