#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int smallest_loc(int *stack, int stack_size)
{
    int smallest_val;
    int smallest_loc;
    int i;

    smallest_val = INT_MAX;
    i = -1;
    while (++i < stack_size)
    {
        if (stack[i] < smallest_val && stack[i] < smallest_val)
        {
            smallest_val = stack[i];
            smallest_loc = i;
        }
    }
    return (smallest_loc);
}

int larger_than(int *stack, int reference, int stack_size)
{
    int larger;
    int i;

    larger = 0;
    i = 0;
    while(i < stack_size)
    {
        if (reference > stack[i])
            larger++;
        i++;
    }
    return (larger);
}

int supposed_loc(int larger_than, int smallest_loc, int stack_size)
{
    int suppose_loc;
    int offset;

    offset = smallest_loc;

    suppose_loc = smallest_loc + larger_than;
    while (suppose_loc >= (stack_size))
        suppose_loc = suppose_loc - stack_size;
    return (suppose_loc);
}

int main()
{
    int stack[] = {10, 1, 3, 6};
    int reference = 9;
    int stack_size = 4;
    int larger = larger_than(stack, reference, stack_size);
    int loc = smallest_loc(stack, stack_size);
    int s_loc = supposed_loc(larger, loc, stack_size);
    printf("your reference value is larger than these amount of data : %d\n", larger);
    printf("The smallest value location is at %d\n", loc);
    printf("Your value should be in = %d, based on current datas\n", s_loc);
}