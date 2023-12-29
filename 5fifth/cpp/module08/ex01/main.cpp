#include "Span.hpp"
#include <iostream>
#include <climits>

// int main()
// {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	Span sp2 = sp;

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	std::cout << sp2.shortestSpan() << std::endl;
// 	std::cout << sp2.longestSpan() << std::endl;

// 	Span sp3(1);

// 	sp3.addNumber(1);

// 	try {
// 		std::cout << sp3.shortestSpan() << std::endl;
// 	}
// 	catch (std::exception &e) {
// 		std::cout << e.what() << std::endl;
// 	}

// 	sp3 = sp;
// 	std::cout << sp3.shortestSpan() << std::endl;
// 	std::cout << sp3.longestSpan() << std::endl;

// 	Span edgecase = Span(4);

// 	edgecase.addNumber(INT_MIN);

// 	edgecase.addNumber(-2);
// 	edgecase.addNumber(-1);
// 	edgecase.addNumber(INT_MAX);

// 	std::cout << edgecase.shortestSpan() << std::endl;
// 	std::cout << edgecase.longestSpan() << std::endl;

// 	return 0;
// }

int main()
{
	Span sp = Span(5);
	int tab[5] = {INT_MIN, -2, -1, INT_MAX};

	sp.addNumber(1);
	sp.addNumbers(tab, 4);

	std::cout << "Stored Elements: " << sp.stored() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}