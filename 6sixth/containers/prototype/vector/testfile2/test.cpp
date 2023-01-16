#include "iostream"

class parent
{
	public:
		void printmsg()
		{
			std::cout << "Hi from parent" << std::endl;
		}
};

class child : public parent
{
	public :
		void printmsg()
		{
			std::cout << "Hi from child" << std::endl;
		}
};

int main()
{
	child a;
	a.printmsg();

	parent *b;

	b = new child;

	b->printmsg();
}