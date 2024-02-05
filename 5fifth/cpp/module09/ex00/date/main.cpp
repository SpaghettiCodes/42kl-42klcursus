#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitCoinExchange	calculator;
	std::string		in_file;

	if (ac != 2)
	{
		std::cout << "Error: Unable To Open" << std::endl;
		return (2);
	}
	if (calculator.generate_dictionary())
		calculator.make_calc(av[1]);
	// calculator.print_dictionary();
}


// // test files
// using namespace std;

// int main()
// {
// 	Date test1("2012-2-12",'-');
// 	Date test2("2012-12-2",'-');
// 	Date test3("0-1-0",'-');

// 	cout << (test1 < test2) << endl;
// 	cout << (test2 < test1) << endl;

// 	// cout << (test1 < test2) << endl;
// 	// cout << (test2 < test3) << endl; 
// 	// cout << (test1 < test3) << endl;
// }

// int main(int ac, char **av)
// {
// 	map<Date, string> test;

// 	Date test1("2011-02-2",'-');
// 	Date test2("2012-02-4",'-');
// 	Date test3("2023-01-24",'-');

// 	test[test1] = "abc";
// 	test[test2] = "def";
// 	test[test3] = "ghi";

// 	cout << test.find(test3)->second << endl;

// 	// // test1 is earlier than test2
	
// 	// cout << test1 << endl;
// 	// cout << test2 << endl;

// 	// cout << (test1 <= test2) << endl;
// }

// int main()
// {
// 	BitCoinExchange what;

// 	what.generate_dictionary();

// 	what.print_dictionary();

// 	cout << (what.data.find(Date("2014-04-28", '-')) == what.data.end()) << endl;
// }