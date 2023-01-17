/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:04:35 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 17:18:05 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_split.h"
# include "get_next_line.h"

typedef struct s_pushswap{
	int	*stack_a;
	int	a_size;
	int	*stack_b;
	int	b_size;
	int	total_size;
}	t_pushswap;

int		ft_atoi(const char *str, t_pushswap *stacks,
			char **to_free, int *to_free2);

void	freedoublechar(char	**tab);

int		fill(t_pushswap *stack, char **av, int ac);

// operations
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

// operations utils
void	swap(int *num1, int *num2);
void	shift_right(int *dest, int size_dest);
void	shift_left(int *dest, int size_dest);
void	reverserotate(int *tab, int size_tab);
void	rotate(int *tab, int size_tab);
void	push(int *src, int *size_src, int *dest, int *size_dest);

// string utils
int		str_cmp(char *str1, char *str2);

// handle input
int		listeninstruction(t_pushswap *stacks);

// error
int		errorexit(t_pushswap *stacks, char **to_free, int *to_free2);
void	freeall(t_pushswap *stacks);

#endif