#include "vector.hpp"

template <typename abc>
void showspace(ft::vector<abc> &e)
{
	std::cout << "Capacity = " << e.capacity() << std::endl;	
	std::cout << "Size = " << e.size() << std::endl;	
}


template <class abc>
void	print_vec(ft::vector<abc> &toprint)
{
	typename ft::vector<abc>::iterator start = toprint.begin();
	typename ft::vector<abc>::iterator end = toprint.end();

	for (int i = 0; (start + i) != end; ++i)
		std::cout << *(start + i) << " ";
	std::cout << std::endl;
}


// int main()
// {
// 	ft::vector<int> test;

// 	for (int i = 0; (i < 10); i++){
// 		showspace(test);
// 		test.push_back(i);
// 	}
// 	showspace(test);

// 	ft::vector<int>::iterator start = test.begin();
// 	ft::vector<int>::iterator end = test.end();

// 	// for (int i = 0; (start + i) != end; ++i)
// 	// {
// 	// 	std::cout << *(start + i) << " ";
// 	// }

// 	for (; start != end; ++start)
// 		std::cout << *(start) << " ";
// 	std::cout << std::endl;

// 	test.pop_back();
// 	showspace(test);
// }

// int main()
// {
// 	ft::vector<int> lmao;
// 	lmao.push_back(1);
// 	lmao.push_back(2);
// 	lmao.push_back(3);
// 	lmao.push_back(4);
// 	lmao.push_back(5);
// 	std::cout << "Lmao size -- " << std::endl;
// 	showspace(lmao);
// 	ft::vector<int>::iterator start = lmao.begin();
// 	ft::vector<int>::iterator end = lmao.end();

// 	// lmao.assign((size_t) 10, 19);
// 	// showspace(lmao);
// 	// ft::vector<int>::iterator start2 = lmao.begin();
// 	// ft::vector<int>::iterator end2 = lmao.end();
// 	// for (; start2 != end2; ++start2)
// 	// 	std::cout << *start2 << " ";
// 	// std::cout << std::endl;

// 	// ft::vector<int> lmao2;
// 	// lmao2.assign(start, end - 1);
// 	// std::cout << "Lmao2 size -- " << std::endl;
// 	// showspace(lmao2);
// 	// ft::vector<int>::iterator start2 = lmao2.begin();
// 	// ft::vector<int>::iterator end2 = lmao2.end();
// 	// for (; start2 != end2; ++start2)
// 	// 	std::cout << *start2 << " ";
// 	// std::cout << std::endl;
// }

// int main()
// {
// 	ft::vector<int> lmao;

// 	for (int i = 0; i < 10; i++)
// 		lmao.push_back(i + 10);

// 	// lmao.erase(lmao.begin());
// 	// lmao.erase(lmao.end() - 1);

// 	std::cout << "before = ";
// 	print_vec(lmao);

// 	// lmao.erase(lmao.begin(), lmao.end());
// 	lmao.clear();

// 	std::cout << "after = ";
// 	print_vec(lmao);
// 	showspace(lmao);
// }

// erase and insert test

// int main()
// {
// 	ft::vector<int> lmao;
// 	ft::vector<int> lmao2;

// 	for (int i = 0; i < 10; i++)
// 		lmao.push_back(i);

// 	for (int i = 1; i < 11; i++)
// 		lmao2.push_back(i * 2);

// 	std::cout << "before = ";
// 	print_vec(lmao);

// 	ft::vector<int>::iterator test = lmao.begin();
// 	const std::size_t	insert_val = 10;

// 	// lmao.erase(lmao.begin());
// 	// lmao.erase(lmao.end() - 1);

// 	// ft::vector<int>::iterator test2 = lmao.insert(test, insert_val);
// 	// std::cout << "insert returend = " << *test2 << std::endl;

// 	// lmao.insert(test, 10, insert_val);

// 	lmao.insert(test, lmao2.begin(), lmao2.end());

// 	std::cout << "after = ";
// 	print_vec(lmao);
// 	showspace(lmao);
// }

// emplace back test

// struct A
// {
// 	std::string ehe;
// 	A(std::string str)
// 	{
// 		ehe = str;
// 	}
// };

// #include "string"
// int main()
// {
// 	ft::vector<A> wtf;

// 	wtf.emplace_back("help");
// }


// resize test

// int main()
// {
// 	ft::vector<int> c;

// 	c.push_back(1);
// 	c.push_back(2);
// 	c.push_back(3);

// 	print_vec(c);

// 	c.resize(5);
// 	print_vec(c);

// 	c.resize(2);
// 	print_vec(c);

// 	c.resize(6, 4);
// 	print_vec(c);
// }

