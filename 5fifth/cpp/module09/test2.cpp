#include <iostream>

class X
{
	public:
		typedef		int	stuff;
		static int a_var;
		static int epic()
		{
			std::cout << "hi" << std::endl;
			return (1);
		}
};

int	X::a_var = 20;

template <typename T>
void	callstuff(T stuff)
{
	std::cout << "in static var = " << T::a_var << std::endl;

	T::epic();

	typename T::stuff a = 10;

	std::cout << "made with typedef in X " << a << std::endl;
}

int main()
{
	X stuff;
	callstuff<X> (stuff);
}