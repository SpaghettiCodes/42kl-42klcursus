# include <algorithm>
# include <vector>
# include <iostream>
# include "pmergeme.hpp"

int	PmergeMe::vec_binary_search(	std::vector<int> &in,
					size_t group_size,
					size_t which,
					int start,
					int stop
)
{
	int							last_elem_loc = group_size - 1;
	int							midpoint = ((stop - start) / 2) + start;

	std::vector<int>::iterator	tomatch_start = in.begin() + (which * group_size);
	std::vector<int>::iterator	tomatch_end = tomatch_start + last_elem_loc;

	std::vector<int>::iterator	mid_start = in.begin() + (midpoint * group_size);
	std::vector<int>::iterator	mid_end = mid_start + last_elem_loc;

	std::vector<int>::iterator	start_start = in.begin() + (start * group_size);
	std::vector<int>::iterator	start_end = start_start + last_elem_loc;

	if (stop <= start)
		return ((*(tomatch_end) > *(start_end)) ? (start + 1) : start);

	if (*(tomatch_end) == *(mid_end))
		return midpoint + 1;

	if (*(tomatch_end) > *(mid_end))
		return vec_binary_search(in, group_size, which, midpoint + 1, stop);

	return vec_binary_search(in, group_size, which, start, midpoint - 1);
}

void	PmergeMe::vec_in_array_insert(	std::vector<int> &in,
							size_t group_size,
							size_t which,
							size_t where
)
{
	std::vector<int>::iterator	chunk_start = in.begin() + (which * group_size);
	size_t						last_elem_loc = group_size - 1;
	std::vector<int>::iterator	last_elem = chunk_start + last_elem_loc;
	std::vector<int>::iterator	chunk_stop = last_elem + 1;
	std::vector<int>::iterator	neg_ones;

	// place padding values
	neg_ones = in.insert(
		in.begin() + (where * group_size),
		group_size,
		-1
	);

	chunk_start = in.begin() + ((which + 1) * group_size);
	chunk_stop =  chunk_start + last_elem_loc + 1;

	// swap over the -1 values
	std::swap_ranges(
		chunk_start,
		chunk_stop,
		neg_ones
	);

	// remove padding values
	in.erase(
		chunk_start,
		chunk_stop
	);
}

void	PmergeMe::vec_binary_insert(	std::vector<int>	&in,
						size_t	group_size,
						size_t	which,
						size_t	sorted_end
					)
{
	size_t	group_num = in.size() / group_size;
	size_t	i;

	i = vec_binary_search(in, group_size, which, 0, sorted_end);
	if (i >= which)
		return;
	vec_in_array_insert(in, group_size, which, i);
}

void	PmergeMe::vec_ford_johnson(std::vector<int> &in, size_t group_size, size_t prev_size)
{
	std::size_t	subgroup_size = group_size / 2;
	std::size_t	total_size = prev_size * subgroup_size;

	std::size_t	num_of_groups = (total_size / group_size);
	bool		is_odd = total_size % group_size;
	std::size_t	num_of_subgroups = num_of_groups * 2;
	std::size_t	last_elem_loc = (group_size / 2) - 1;

	std::size_t	first_elem;
	std::size_t	second_elem;
	std::size_t i = 0;

	if (!(num_of_groups))
		return;

	// swap the pairs by determine which is the higest
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

	vec_ford_johnson(in, group_size * 2, num_of_groups);

	// place the sorted bigger values to the front of the array
	int	sorted_vals = 2; // the first pair is left alone
	int current_indx = 3;
	while (sorted_vals < (num_of_groups + 1))
	{
		vec_in_array_insert(in, subgroup_size, current_indx, sorted_vals);
		++sorted_vals;
		current_indx += 2;
	}

	// insert remaining characters
	int	j_num = 2;
	int previous_jacobthal_number = jacobsthal_num_gen(2);
	int	current_jacobthal_number = jacobsthal_num_gen(2);
	current_indx = current_jacobthal_number;

	while (sorted_vals < num_of_subgroups)
	{
		vec_binary_insert(in, subgroup_size, current_jacobthal_number + num_of_groups, sorted_vals);

		++sorted_vals; 
		--current_indx;
		if (current_indx <= previous_jacobthal_number)
		{
			j_num++;
			previous_jacobthal_number = current_jacobthal_number;
			current_jacobthal_number = jacobsthal_num_gen(j_num);
			if (current_jacobthal_number >= num_of_groups)
				current_jacobthal_number = (num_of_groups - 1);

			current_indx = current_jacobthal_number;
		}
	}

	if (is_odd)
		vec_binary_insert(in, subgroup_size, prev_size - 1, sorted_vals);
}

