#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <stack>
#include <deque>
#include <iterator>

template <class TypeA, class container = std::deque<TypeA> >
class MutantStack : public std::stack<TypeA, container>
{
	public:
		typedef typename container::iterator iterator;
		typedef typename std::stack<TypeA, container> s;	

		MutantStack() {};
		MutantStack(MutantStack<TypeA, container> &ori) 
		{
			*this = ori;
		}

		~MutantStack() {};

		MutantStack<TypeA, container>  &operator=(MutantStack<TypeA, container>  &ori) 
		{
			this->c = ori.c;
		}

		// https://en.cppreference.com/w/cpp/container/stack
		iterator begin()
		{
			return (s::c.begin());
		}

		iterator end()
		{
			return (s::c.end());
		}

		// i dont THINK i need a const iterator?
		// really not sure, not specified so immm not gonna put it?
};

#endif 