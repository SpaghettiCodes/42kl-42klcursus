#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

template <typename Type> 
class Array
{
	public:
		Array();
		Array(unsigned int size);
		Array(Array<Type> &ori);
		~Array();

		template <typename Type2>
		Array<Type>	&operator=(Array<Type2> const &ori);
		Type 		&operator[](int const index);

		// so that const Array can have their stuff taken out
		Type const	&operator[](int const index) const;

		unsigned int size() const;


	private:
		unsigned int		stuff_size;
		Type				*stuff;

		template <typename Type2>
		Type2	*copy_over(Array<Type2> const &ori);

		class OutOfBounds : public std::exception
		{
			virtual const char* what() const throw() { return ("Error: Index given is out of bounds!"); }
		};

};

#include "Array.tpp"

#endif