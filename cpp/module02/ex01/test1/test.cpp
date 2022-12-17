#include <iostream>

using namespace std;

int main()
{
	int i = 5;
	cout << "i = " << i << endl;
	// cout << "bitshifted 2, i is now = " << (i<<2) << endl;
	// cout << "i = " << i << endl;  
	if (i & (1<<31))
	{
		cout << "This is a negative number" <<endl;
		i = i ^ (1<<31); // "turn off the sign"
		i = i - 1; 
		// 2147483647 = 1111111111111111111111111111111
		i = i ^ (2147483647); // twos complement
		i = abs(i);
		cout << "i is now = " << i << endl;
	}
	else
	{
		cout << "This is not a negative number" <<endl;
		i = i ^ (2147483647); // twos complement;
		i = i + 1;
		i = i | (1<<31); // "turn on" the sign;
		cout << "i is now = " << i << endl;
	}
}