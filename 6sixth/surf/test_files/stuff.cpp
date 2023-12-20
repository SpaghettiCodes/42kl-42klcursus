#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string a("one    two    three");

	stringstream he(a);
	string chunk;

	// for (int x = 0; x < 3; ++x){
	// 	he >> chunk;
	// 	cout << chunk << endl;
	// }

	string stuff("onetwothree");
	cout << (stuff == "onetwothree") << endl;

	fstream hehe;

	hehe.open("abcdef", ios::out);
	if (!hehe)
		cout << "yep!" << endl;
	hehe << "walaoeh";
}