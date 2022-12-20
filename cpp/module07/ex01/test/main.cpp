#include "iter.hpp"
#include "iostream"

template <typename T> void print( T const & x ) 
{ 
	std::cout << x << std::endl; return; 
}

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) 
		{ 
			return; 
		}

		int get( void ) const 
		{ 
			return this->_n; 
		}
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) 
{
	o << rhs.get(); 
	return o; 
}

int main() 
{
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];

	iter( tab, 5, print<int>);
	iter( tab2, 5, print<Awesome>);

	return 0;
}

// template <typename X> 
// void printstuff(X &a)
// {
// 	std::cout << a << std::endl;
// }

// int main()
// {
// 	int tab[] = {0, 1, 2, 3, 4};
// 	int size = 5;

// 	iter(tab, size, printstuff);
// }