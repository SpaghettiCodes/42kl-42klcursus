#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <iterator> // for iterators
#include <algorithm> // for find

class NotFound : public std::exception
{
	virtual const char* what() const throw()
	{
		return ("Im Blind");
	}
};

// T is a container of integers
template <class T>
typename T::iterator easyfind(T container, int tofind)
{
	// need typename before T::iterator because 'T' is a dependent scope - error
	// https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords

	// compiler basically has no idea what T::iterator does
	//			- this could be a function, it could be a member as well
	// T cant be looked up until the actual template arguments are known 
	// 			- called a dependant name (depends on template parameters)

	// to tell the compiler that T::iterator is a type, use the keyword "typename"
	// 'typename' keyword is used to specify that a name is a type in a template;

	// if you want to tell that its a member or a function
	//		- T::x = 10 - static member
	//		- T::x() - static function
	typename T::iterator ret = find(container.begin(), container.end(), tofind); // funny, i never knew find is a function in cpp algo
	// or you can use auto
	// HOWEVER auto is a c++11? function soooo :(

	if (ret == container.end())
		throw NotFound();
	return (ret);
}

#endif