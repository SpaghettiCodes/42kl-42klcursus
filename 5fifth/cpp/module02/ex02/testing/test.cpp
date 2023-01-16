#include "Fixed.hpp"

using namespace std;

int main()
{
	for (float i = -1; i < 1; i += 0.005)
	{
		Fixed fixed(i);
		cout << "Value: " << fixed << endl;
		cout << "Raw bits: " << fixed.getRawBits() << endl;
	} 
}