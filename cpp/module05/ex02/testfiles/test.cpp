#include <iostream>
#include <string>

using namespace std;

class test
{
	public :
		virtual ~test();
		virtual void printtest() = 0;
};

test::~test()
{
}

void test::printtest()
{
	cout << "From Base Class" << endl;
}

class derived_test : public test
{
	public :
		void printtest();
};

void derived_test::printtest()
{
	cout << "From Derived Class" << endl;
}

class runner
{
	public :
		void runprog(test &test);
};

void runner::runprog(test &test)
{
	test.printtest();
}

int main()
{
	test *hyok = new derived_test;
	runner run;

	run.runprog(*hyok);

	delete hyok;
}

