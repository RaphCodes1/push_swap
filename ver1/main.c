#include "push_swap.h"

int main(int ac, char **av)
{   
    t_stack_node *a;
    // t_stack_node *b;

    a = NULL;
    // b = NULL;
    if(ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    else if(ac == 2)
        av = ft_split(av[1], ' ');
    stack_init(&a,av + 1,ac == 2);
    tiny_sort(&a);
    while(a)
    {   
        printf("a: %d\n",a->value);
        a = a->next;
    }
} 