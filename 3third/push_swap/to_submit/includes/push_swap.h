#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_split.h"
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

typedef unsigned int bool;
#define TRUE 1
#define FALSE 0

typedef struct s_pushswap
{
	int	*un_sorted;
	int	total_size;
	int	*sorted;
	int	*stack_a;
	int	*stack_b;
	int	a_size;
	int	b_size;
	unsigned int moves;
	bool print:1;
}	t_pushswap;

// normal sort algo 
void	q_sort(int *a, int first, int last);

// atoi
int		ft_atoi(const char *str, t_pushswap *stacks, char **free_me, int *free_me_2);

// get arguments
void			realloc_tab(t_pushswap *stack, int new_size, char **new_stuff);
unsigned int	count_elem(char **stuff);
int				fill(t_pushswap *stack, char **av, int ac);

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

// printstack for debug
void	printstack(t_pushswap *stacks);

// solving stacks
void	shift_to_correct(t_pushswap *stack, int larger, int toplace);
void	action(t_pushswap *stack, int toplace);
int		larger_than(int *stack, int reference, int stack_size);
int		moves(int larger_than, int smallest_loc, int stack_size);
void	search_and_add(t_pushswap *stack);

// solving big stacks

// pushes from b to a
void	push_to_a(t_pushswap *stack, int start, int end);
// pushes from a to b
void	push_to_b(t_pushswap *stack, int start_loc, int end_loc, int chunk_size);
// reverts all changes (lowest value at the top)
void	revert_changes(t_pushswap *stack);
// solves chunk
void	solve_chunk(t_pushswap *stack, int count);
// solves data with number >= 100
void	solve_very_big(t_pushswap *stack);

// get location of values in stack
// get value location in stack a
int		get_loc(t_pushswap *stack, int val);
// find the start element in stack_a
int		find_start_half(t_pushswap *stack, int max, int min);
// find the end element in stack_a
int		find_end_half(t_pushswap *stack, int max, int min);
// get largest value location in stack a
int		get_largest_loc(t_pushswap *stack);
// gets the lowest value location in stack a
int		get_lowest_loc(t_pushswap *stack);

// determine the correct location of reference to push to stack_a
// get number of elements larger than reference (from bottom)
int		get_no_larger(t_pushswap *stack, int reference, int last_elem_loc);
// get number of elements smaller than reference (from top)
int		get_no_smaller(t_pushswap *stack, int reference, int first_elem_loc);

// determine the number of moves to sort a certain value
// determines moves needed to rotate stack_a
int		moves_needed_rot_a(t_pushswap *stack, int reference, int max, int min);
// calculate the value with the least moves to push into a
void	find_lesser_moves(t_pushswap *stack, int max_val, int min_val);
// calculate the value within max and min with the least amount of moves to push to b
int		find_and_push(t_pushswap *stack, int max, int min);

// rotating the stacks
// determines how to rotate stack_b (to be used with (find_lesser_moves))
void	rot_b(t_pushswap *stack, int smallest_move_loc);
// rotate the stacks to the correct location
void	rotate_to_correct(t_pushswap *stack, int moves, char stack_name);
// go to the top of the last chunk OR the bottom of the very first chunk (has the largest value) to sort the next chunk at the correct location
void	go_to_last_chunk(t_pushswap *stack, int last_stack_smallest_loc);

// structure stuff
// count number of instructions to sort data
int				count_instruct(t_instructions *instruct);
// delete and free all of instructions
void			del_all(t_instructions **instructions);
// initialize instructions
t_instructions	*init_instruction();
// returns the pointer to the last node in a linked list 
t_instructions	*last_node(t_instructions *instruction);
// adds a new node at the last node in a linked list
void			add_node(t_instructions *instruction, char *move);

// array utils
// copys one int array to another int array and returns a pointer to the copied int array
int				*int_dup(int *source, int source_size);
// duplicates a string and returns a pointer to the duplicated string 
char			*str_dup(char *str);

//print
int		str_len(char *str);
void	print_instruction(t_instructions *instruction);

// error
int		error(t_pushswap *stack, char **free_me, int *free_me_2);

// initialize 
// initialize chunk (pushing 2 elements from b to a to have a start element and end element)
int				init_chunk(t_pushswap *stack);
// initialize a new instruction node
t_instructions	*init_instruct_node();
// initalize stacks a and b and also instructions
void			init_stacks(t_pushswap *stack);
// initalize push_swap structure
void			init_struct(t_pushswap *pushswap);

// free stuff
void	freedoublechar(char **tab);
void	freeall(t_pushswap *pushswap);

#endif
