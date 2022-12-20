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

		Array<Type>	&operator=(Array<Type> &ori);
		Type 		&operator[](int index);
		
		unsigned int size() const;


	private:
		Type				*stuff;
		unsigned int		stuff_size;

		Type	*copy_over(Type *ori, int ori_size);

		class OutOfBounds : public std::exception
		{
			virtual const char* what() const throw() { return ("Index given is out of bounds!"); }
		};

};

#include "Array.tpp"

#endif