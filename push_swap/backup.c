
// int		find_lesser_moves(t_pushswap *stack, int max_val, int min_val)
// {
// 	int current;
// 	int next;
// 	int last;]

// 	current = moves_needed(stack, stack->stack_b[0], max_val, min_val);
// 	next = moves_needed(stack, stack->stack_b[1], max_val, min_val);
// 	last = moves_needed(stack, stack->stack_b[stack->b_size - 1], max_val, min_val);
// 	if (current < 0)
// 		current = current * -1;
// 	if (next < 0)
// 		next = next * -1;
// 	if (last < 0)
// 		last = last * -1;
// 	if (++next < current)
// 	{
// 		sb(stack);
// 		return (1);
// 	}
// 	if (++last < current)
// 	{
// 		rrb(stack);
// 		return (1);
// 	}
// 	return (0);
// }