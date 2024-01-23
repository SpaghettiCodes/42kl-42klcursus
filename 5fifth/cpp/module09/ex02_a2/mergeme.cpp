# include <algorithm>
# include <vector>
# include <math.h>
# include <iostream>

// determine which index to jam in next
int	jacobsthal_num_gen()
{
	static int jn;
	static int n;

	if (n == 0)
		jn = 0;
	else if (n == 1)
		jn = 1;
	else
		jn = pow(2, n) - jn;
	++n;
	return jn;
}

void	insert_element(std::vector<int> &in, size_t group_size, size_t which, size_t stop)
{
	size_t	group_num = in.size() / group_size;
	size_t	last_elem_loc = group_size - 1;
	size_t	i;

	std::vector<int>::iterator	chunk_start = in.begin() + (which * group_size);
	std::vector<int>::iterator	last_elem = chunk_start + last_elem_loc;
	std::vector<int>::iterator	chunk_stop = last_elem + 1;
	std::vector<int>::iterator	neg_ones;
	for ( i = 0; i < which; ++i )
	{
		std::cout << *(last_elem) << " : " << in[(i * group_size) + last_elem_loc] << std::endl;

		if (*(last_elem) < in[(i * group_size) + last_elem_loc])
		{
			// place padding values
			neg_ones = in.insert(
				in.begin() + (i * group_size),
				group_size,
				-1
			);

			// replace -1s with the real values
			chunk_start = in.begin() + ((which + 1) * group_size);
			chunk_stop =  chunk_start + last_elem_loc + 1;

			std::swap_ranges(
				chunk_start,
				chunk_stop,
				neg_ones
			);

			// remove -1s
			in.erase(
				chunk_start,
				chunk_stop
			);

			break;
		} 
	}
}

int jacobsthal_num_gen(int n)
{
	return ((pow(2, n) - pow(-1, n)) / 3);
}

void	ford_johnson(std::vector<int> &in, size_t group_size)
{
	in.reserve(100);

	std::size_t	total_size = in.size();
	std::size_t	num_of_groups = (total_size / group_size);
	std::size_t	num_of_subgroups = num_of_groups * 2;
	std::size_t	subgroup_size = group_size / 2;
	std::size_t	last_elem_loc = (group_size / 2) - 1;

	std::vector<int>::iterator	last_var;

	std::size_t	first_elem;
	std::size_t	second_elem;

	std::size_t i = 0;
	while (i < num_of_groups)
	{
		first_elem = i * group_size;
		second_elem = first_elem + (group_size / 2);

		if (in[first_elem + last_elem_loc] > in[second_elem + last_elem_loc])
		{
			std::swap_ranges(
				in.begin() + first_elem,
				in.begin() + second_elem,
				in.begin() + second_elem
			);
		}
		++i;
	}
	if ((total_size / group_size) <= 1)
		return;
	else
	{
		ford_johnson(in, group_size * 2);

		// insert remaining characters
		int	j_num_idx = 2;
		int previous_jacobthal_number = jacobsthal_num_gen(2);
		int	current_jacobthal_number = jacobsthal_num_gen(2);
		int current_indx = current_jacobthal_number;

		// insert at the start of S the element that was pair with the first and smallest element of S
		// well i mean its already there so :P
		int sorted_vals = 1;
		while (sorted_vals < num_of_groups * 2)
		{
			for (auto start = in.begin(); start != in.end(); ++start)
				std::cout << *(start) << " ";
			std::cout << std::endl;

			insert_element(in, subgroup_size, sorted_vals, sorted_vals + 1);

			for (auto start = in.begin(); start != in.end(); ++start)
				std::cout << *(start) << " ";
			std::cout << std::endl << "--------" << std::endl;

			++sorted_vals;
		}
	}
}

int main()
{
	std::vector<int> stuff = {65,79,14,27,83,46,62,86,42,56,24,40,51,76,87,89,53,35,73,21,91,10,1,38,82,13,39,92,41,25,18,74,98,61,11,57,75,50,90,64,28,43,30,47,37,94,32,6,26,58,80,52,55,15,60,100,29,95,44,96,3,19,16,70,36,17,49,84,22,63,72,9,2,45,33,8,54,5,34,12,93,69,67,66,20,77,97,78,85,23,31,88,59,81,7,48,68,4,71,99};
	// std::vector<int> stuff = {8,4,1,6,2,5,3,7};
	ford_johnson(stuff, 2);

	for (auto start = stuff.begin(); start != stuff.end(); ++start)
		std::cout << *(start) << " ";
	std::cout << std::endl;

	// for (int i = 2; i < 10; ++i)
	// {
	// 	std::cout << jacobsthal_num_gen(i) << " ";
	// }
	// std::cout << std::endl;
}