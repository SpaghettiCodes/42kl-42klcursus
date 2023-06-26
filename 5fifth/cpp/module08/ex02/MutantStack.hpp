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
			c = ori.c;
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
};

#endif 