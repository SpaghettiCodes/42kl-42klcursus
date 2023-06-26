#include "iter.hpp"
#include "iostream"

// template <typename T> void print( T const & x ) 
// { 
// 	std::cout << x << std::endl; return; 
// }

// class Awesome
// {
// 	public:
// 		Awesome( void ) : _n( 42 ) 
// 		{ 
// 			return; 
// 		}

// 		int get( void ) const 
// 		{ 
// 			return this->_n; 
// 		}
// 	private:
// 		int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) 
// {
// 	o << rhs.get(); 
// 	return o; 
// }

// int main() 
// {
// 	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
// 	Awesome tab2[5];

// 	iter( tab, 5, print );
// 	iter( tab2, 5, print );

// 	return 0;
// }


template <typename X> 
int afunction(X &a)
{
	return (2);
}

template <typename X> 
void printstuff(X &a)
{
	std::cout << a << std::endl;
}

int	multi_two(int &a)
{
	std::cout << a * 2 << std::endl;
	return (a * 2);
}

int main()
{
	int tab[] = {0, 1, 2, 3, 4};
	int size = 5;

	iter<int, void>(tab, size, printstuff);
	iter(tab, size, multi_two);
	iter(tab, size, afunction<int>);
}