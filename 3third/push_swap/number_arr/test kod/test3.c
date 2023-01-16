# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

    typedef struct s_pushswap
    {
        int *sorted;
        int *stack_a;
        int *stack_b;
        int a_size;
        int b_size;
        int total_size;
    } t_pushswap;


int action(t_pushswap *stacks, int midpoint_val)
{
    int closest_start;
    int closest_end;

    closest_start = 0;
    while (closest_start < stacks->a_size && midpoint_val < stacks->stack_a[closest_start])
    {
        closest_start++;
    }
    closest_end = stacks->a_size - 1;
    while (closest_end >= 0 && midpoint_val < stacks->stack_a[closest_end])
    {
        closest_end--;
    }
    if (closest_start == (stacks->a_size) && closest_end == -1)
        printf("Bruhter no possible moves bruhter"); 
    closest_end = stacks->a_size - closest_end;
    printf("Closest val that is lesser than midpoint from the start = %d\n", closest_start);
    printf("Closest val that is lesser than the midpoint from the end = %d\n", closest_end);
    if (closest_end < closest_start)
        return (closest_end * -1);
    else
        return (closest_start);
}

int main()
{
    t_pushswap teststruct;
    int test[] = {14, 21, 15,8,2,7};
    teststruct.stack_a = test;
    teststruct.a_size = sizeof(test) / sizeof(int);
    printf("size of test array, %d\n", teststruct.a_size);
    int test2[] = {0};
    teststruct.stack_b = test2;
    printf("Steps to Take %d\n", action(&teststruct, 0));
}