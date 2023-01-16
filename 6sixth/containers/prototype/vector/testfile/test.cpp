#include <iostream>
#include <vector>


using namespace std;

template <class abc>
void	print_vec(std::vector<abc> &toprint)
{
	typename std::vector<abc>::iterator start = toprint.begin();
	typename std::vector<abc>::iterator end = toprint.end();

	for (int i = 0; (start + i) != end; ++i)
		std::cout << *(start + i) << " ";
	std::cout << std::endl;
}

template <typename abc>
void showspace(vector<abc> &e)
{
	cout << "Capacity = " << e.capacity() << endl;	
	cout << "Size = " << e.size() << endl;	
}

// int main()
// {
// 	vector<int> lmao;

// 	showspace(lmao);
// 	for (int i = 0; i < 20; i++)
// 	{
// 		lmao.push_back(1);
// 	}
// 	showspace(lmao);
// 	lmao[30] = 123546;
// 	std::cout << lmao[30] << std::endl;
// 	showspace(lmao);
// 	lmao.shrink_to_fit();
// 	showspace(lmao);
// }

// int main()
// {
// 	vector<int> lmao;
// 	lmao.push_back(1);
// 	lmao.push_back(2);
// 	lmao.push_back(3);
// 	lmao.push_back(4);
// 	lmao.push_back(5);
// 	showspace(lmao);
// 	vector<int>::iterator start = lmao.begin();
// 	vector<int>::iterator end = lmao.end();

// 	lmao.assign(10, 19);
// 	showspace(lmao);
// 	vector<int>::iterator start2 = lmao.begin();
// 	vector<int>::iterator end2 = lmao.end();
// 	for (; start2 != end2; ++start2)
// 		cout << *start2 << " ";
// 	std::cout << std::endl;
// }

// int main()
// {
// 	std::vector<int> lmao;
// 	lmao.push_back(1);
// 	lmao.push_back(2);
// 	lmao.push_back(3);
// 	lmao.push_back(4);
// 	lmao.push_back(5);
// 	std::cout << "Lmao size :- " << std::endl;
// 	showspace(lmao);
// 	std::vector<int>::iterator start = lmao.begin();
// 	std::vector<int>::iterator end = lmao.end();

// 	// lmao.assign(10, 19);
// 	// showspace(lmao);
// 	// std::vector<int>::iterator start2 = lmao.begin();
// 	// std::vector<int>::iterator end2 = lmao.end();
// 	// for (; start2 != end2; ++start2)
// 	// 	std::cout << *start2 << " ";
// 	// std::cout << std::endl;

// 	std::vector<int> lmao2;
// 	lmao2.assign(start, end - 1);
// 	std::cout << "Lmao2 size :- " << std::endl;
// 	showspace(lmao2);
// 	std::vector<int>::iterator start2 = lmao2.begin();
// 	std::vector<int>::iterator end2 = lmao2.end();
// 	for (; start2 != end2; ++start2)
// 		std::cout << *start2 << " ";
// 	std::cout << std::endl;
// }

// int main()
// {
// 	std::vector<int> lmao;

// 	for (int i = 0; i < 10; i++)
// 		lmao.push_back(i + 10);

// 	// lmao.erase(lmao.begin());
// 	// lmao.erase(lmao.end() - 1);

// 	std::cout << "before = ";
// 	print_vec(lmao);

// 	lmao.erase(lmao.begin(), lmao.end());

// 	std::cout << "after = ";
// 	print_vec(lmao);
// }

// int main()
// {
// 	std::vector<int> lmao;
// 	std::vector<int> lmao2;

// 	for (int i = 0; i < 10; i++)
// 		lmao.push_back(i);

// 	for (int i = 0; i < 10; i++)
// 		lmao2.push_back(i * 2);

// 	// lmao.erase(lmao.begin());
// 	// lmao.erase(lmao.end() - 1);

// 	std::cout << "before = ";
// 	print_vec(lmao);

// 	std::vector<int>::iterator test = lmao.begin() + 2;
// 	int	insert_val = 10;

// 	// ft::vector<int>::iterator test2 = lmao.insert(test, insert_val);
// 	// std::cout << "insert returend = " << *test2 << std::endl;

// 	// lmao.insert(test, 10, insert_val);

// 	lmao.insert(test, lmao2.begin(), lmao2.end());

// 	std::cout << "after = ";
// 	print_vec(lmao);
// 	showspace(lmao);
// }

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
// 	std::vector<A> wtf;

// 	wtf.emplace_back("help");
// }

int main()
{
	std::vector<int> hyok;

	// hyok.reserve(10);
	showspace(hyok);

	hyok.resize(3);
	showspace(hyok);
}