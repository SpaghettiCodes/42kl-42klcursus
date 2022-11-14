#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

// the struct

typedef struct s_instructions
{
	char *move;
	struct s_instructions *next;
}	t_instructions;

typedef struct s_pushswap
{
	int	*un_sorted;
	int	*sorted;
	int	*stack_a;
	int	*stack_b;
	int	a_size;
	int	b_size;
	int	total_size;
	t_instructions	*instructions;
}	t_pushswap;

// normal sort algo 
void	q_sort(int *a, int first, int last);

// atoi
int		ft_atoi(const char *str, t_pushswap *stacks);

// push swap operations
void	sa(t_pushswap *stack);
void	sb(t_pushswap *stack);
void	ss(t_pushswap *stack);
void	pa(t_pushswap *stack);
void	pb(t_pushswap *stack);
void	ra(t_pushswap *stack);
void	rb(t_pushswap *stack);
void	rr(t_pushswap *stack);
void	rra(t_pushswap *stack);
void	rrb(t_pushswap *stack);
void	rrr(t_pushswap *stack);

// operation utils
void	swap(int *num1, int *num2);
void	shift_right(int *dest, int size_dest);
void	shift_left (int *dest, int size_dest);
void	reverserotate(int *tab, int size_tab);
void	rotate(int *tab, int size_tab);
void	push(int *src, int *size_src, int *dest, int *size_dest);

// solve
void	solve(t_pushswap *stack);
int		solve_two(t_pushswap *stack);
int		solve_three(t_pushswap *stack);
void	solve_small_big(t_pushswap *stack);
void	solve_very_big(t_pushswap *stack);
int		smallest_loc(int *stack, int stack_size);

// printstack for debug
void	printstack(t_pushswap *stacks);

// solving stacks
void	shift_to_correct(t_pushswap *stack, int larger, int toplace);
void	action(t_pushswap *stack, int toplace);
int		larger_than(int *stack, int reference, int stack_size);
int		moves(int larger_than, int smallest_loc, int stack_size);
void	search_and_add(t_pushswap *stack);

// solving big stacks

// rotate the stacks to the correct location
void	rotate_to_correct(t_pushswap *stack, int moves, char stack_name);
// get number of elements larger than reference (from bottom)
int		get_no_larger(t_pushswap *stack, int reference, int last_elem_loc);
// get number of elements smaller than reference (from top)
int		get_no_smaller(t_pushswap *stack, int reference, int first_elem_loc);
// initialize chunk (pushing 2 elements from b to a to have a start element and end element)
int		init_chunk(t_pushswap *stack);
// find the start element in stack_a
int		find_start_half(t_pushswap *stack, int max, int min);
// find the end element in stack_a
int		find_end_half(t_pushswap *stack, int max, int min);
// determine moves needed to rotate a so that reference can be pushed correctly
int		moves_needed(t_pushswap *stack, int reference, int max, int min);
// get value location in stack a
int		get_loc(t_pushswap *stack, int val);
// get largest value location in stack a
int		get_largest_loc(t_pushswap *stack);
// go to the top of the last chunk OR the bottom of the very last chunk (has the largest value)
void	go_to_last_chunk(t_pushswap *stack, int last_stack_smallest_loc);
// calculate the value with the least moves to push into a
void	find_lesser_moves(t_pushswap *stack, int max_val, int min_val);
// pushes from b to a
void	push_to_a(t_pushswap *stack, int start, int end);
// calculate the value within max and min with the least amount of moves to push to b
int		find_and_push(t_pushswap *stack, int max, int min);
// pushes from a to b
void	push_to_b(t_pushswap *stack, int start_loc, int end_loc, int chunk_size);
// gets the lowest value location in stack a
int		get_lowest_loc(t_pushswap *stack);
// reverts all changes (lowest value at the top)
void	revert_changes(t_pushswap *stack);
// solves chunk
void	solve_chunk(t_pushswap *stack, int count);
// solves data with number >= 100
void	solve_very_big(t_pushswap *stack);

// structure stuff

// count number of instructions to sort data
int				count_instruct(t_instructions *instruct);
// delete and free all of instructions
void			del_all(t_instructions **instructions);
// initialize instructions
t_instructions	*init_instruction();
// copys one int array to another int array and returns a pointer to the copied int array
int				*int_dup(int *source, int source_size);
// initalize stacks a and b and also instructions
void			init_stacks(t_pushswap *stack);
// duplicates a string and returns a pointer to the duplicated string 
char			*str_dup(char *str);
// returns the pointer to the last node in a linked list 
t_instructions	*last_node(t_instructions *instruction);
// adds a new node at the last node in a linked list
void			add_node(t_instructions *instruction, char *move);

//print
int		str_len(char *str);
void	print_instruction(t_instructions *instruction);

// error
int		error(t_pushswap *stack);

#endif
