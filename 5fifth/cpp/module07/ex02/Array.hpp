#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

template <typename Type> 
class Array
{
	public:
		Array();
		Array(unsigned int size);
		Array(Array<Type> const &ori);
		~Array();

		Array<Type>	&operator=(Array const &ori);
		Type 		&operator[](int const index);

		// so that const Array can have their stuff taken out
		Type const	&operator[](int const index) const;

		unsigned int size() const;

		class OutOfBounds : public std::exception
		{
			virtual const char* what() const throw() { return ("Error: Index given is out of bounds!"); }
		};

	private:
		unsigned int		stuff_size;
		Type				*stuff;

		Type	*copy_over(Type *ori, int ori_size);

};

#include "Array.tpp"

#endif