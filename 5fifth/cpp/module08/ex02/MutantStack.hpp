#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <stack>
#include <deque>
#include <iterator>

// i could have just inherited stack...
template <class TypeA, class container = std::deque<TypeA> >
class MutantStack : public std::stack<TypeA, container>
{
	public:
		typedef typename container::iterator iterator;
		typedef typename std::stack<TypeA, container> inner_con;	

		MutantStack() {};
		MutantStack(MutantStack<TypeA, container> &ori) 
		{
			*this = ori;
		}

		~MutantStack() {};

		MutantStack<TypeA, container>  &operator=(MutantStack<TypeA, container>  &ori) 
		{
			inner_con::c = ori.inner_con::c;
		}

		// https://en.cppreference.com/w/cpp/container/stack
		iterator begin()
		{
			// TODO check why (std::stack<TypeA, container>::c) is needed to access a protected member
			return (inner_con::c.begin());
		}

		iterator end()
		{
			return (inner_con::c.end());
		}
};

#endif 