#include <iostream>
#include <string>

using namespace std;

class Help
{
	public:
	void set(string x)
	{
		arr[0] = x;
	}
	string	get()
	{
		return(arr[0]);
	}
	private:
		string	arr[4];
};

class Help2
{
	public:
		string getstuff();
	private:
};

string Help2::getstuff()
{
	string in;

	getline(cin, in);
	return (in);
}

int main()
{
	Help test;
	Help2 test2;
	test.set(test2.getstuff());
	cout << test.get() << endl;
}