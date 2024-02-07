#include "test.hpp"

int main()
{
	std::size_t	size = 5;

	std::vector<int> stuff({1,2,3,4,5,6,7,8,9});
	Group_Iter	start(stuff.begin(), size);
	Group_Iter	end(stuff.end(), size);
	int	i(0);
	Group_Iter iter;

	try
	{
		for (iter = start; iter < end; ++iter, ++i)
		{
			std::cout << i << " : " << *(iter.get_start()) << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}