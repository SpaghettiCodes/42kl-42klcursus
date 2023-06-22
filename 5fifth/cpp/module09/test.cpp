#include <iostream>
#include <vector>
#include <string>

int main()
{
	typedef	std::string str_t;
	str_t myvector;
	
	myvector.push_back('a');
	myvector.push_back('b');
	myvector.push_back('c');
	myvector.push_back('d');
	myvector.push_back('g');
	myvector.push_back('a');
	myvector.push_back('h');

	typedef str_t::iterator iter_type;

	std::reverse_iterator<iter_type>	reverse_end(myvector.end());
	iter_type							end(myvector.end());


	std::cout << myvector.find('a') << std::endl;
	std::cout << myvector.find_last_of('a') << std::endl;

	return 0;
}