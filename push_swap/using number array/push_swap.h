#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// push swap operations
void	sa(int *a, int size_a);
void	sb(int *b, int size_b);
void	ss(int *a, int size_a, int *b, int size_b);
void	pa(int *a, int *size_a, int *b, int *size_b);
void	pb(int *b, int *size_b, int *a, int *size_a);
void	ra(int *a, int size_a);
void	rb(int *b, int size_b);
void	rr(int *a, int size_a, int *b, int size_b);
void	rra(int *a, int size_a);
void	rrb(int *b, int size_b);
void	rrr(int *a, int size_a, int *b, int size_b);

// utils
void	swap(int *num1, int *num2);
void	shift_right(int *dest, int size_dest);
void	shift_left (int *dest, int size_dest);
void	reverserotate(int *tab, int size_tab);
void	rotate(int *tab, int size_tab);
void	push(int *src, int size_src, int *dest, int size_dest);
int		*int_dup(int *a, int size_a);

#endif
