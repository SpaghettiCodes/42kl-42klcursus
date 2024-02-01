# ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);

		void	run();
		void	print_val();

	private:
		class	NotAPositiveDigit : public std::exception {
			const char *what() const throw() {
				return ("Not a valid Positive Integer");
			}
		};

		bool	is_numeric(char *stuff);
		void	get_values(int ac, char **av);

		void	print_vct(std::vector<int> stuff);
		void	print_sorted();
	
		void	vector_runner();
		void	vector_fordjohn();

		/* Jacobsthal Number */
		int		jacobsthal_num_gen(int n);

		/* Vector Sorting */
		int		vec_binary_search(std::vector<int> &in, size_t group_size, size_t which, int start, int stop );
		void	vec_in_array_insert(std::vector<int> &in, size_t group_size, size_t which, size_t where);
		void	vec_binary_insert(std::vector<int> &in, size_t group_size, size_t which, size_t sorted_end);
		void	vec_ford_johnson(std::vector<int> &in, size_t group_size, size_t prev_size);

		/* List Sorting */

		/* Cool Variables */

		std::vector<int>	hard_copy;

		std::vector<int>	vec;
		std::list<int>		lst;
		timeval				time_vec;
		timeval				time_list;

		int					ac;
		char				**av;
};

# endif