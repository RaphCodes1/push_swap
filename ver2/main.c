#include "push_swap.h"

int main(int ac, char **av)
{   
    t_stack_node *a;
    t_stack_node *b;
    char *res;

    a = NULL;
    b = NULL;
    res = NULL; 

    if(ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    else if(ac == 2)
        av = ft_split(av[1], ' ');
    else if(ac > 2)
    {
        res = split_modif(av);
        av = ft_split(res,' ');
        free(res);
    }
    stack_init(&a,av + 1,ac == 2);
    // t_stack_node *tmp = a;
    // printf("Temp:");
    // while(tmp)
    // {
    //     printf(" %d",tmp->value);
    //     tmp = tmp->next;
    // }
    // printf("\n");
    if(!stack_sorted(a))
    {
        if(stack_len(a) == 2)
            sa(&a, false);
        else if(stack_len(a) == 3)
            tiny_sort(&a);
        else
            push_swap(&a,&b);
    }
    // printf("result:");
    // while(a)
    // {
    //     printf(" %d",a->value);
    //     a = a->next;
    // }
    // printf("\n");
    free_stack(&a);
} 