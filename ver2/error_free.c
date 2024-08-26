#include "push_swap.h"

void free_matrix(char **av)
{
    int i;

    i = -1;

    if(!av || !*av)
        return ;
    while(av[i])
        free(av[i++]);
    free(av - 1);
}

void free_stack(t_stack_node **stack)
{
    t_stack_node *tmp;
    t_stack_node *current;
    if(!stack)
        return ;
    current = *stack;
    while(current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}

void error_free(t_stack_node **stack, char **av, bool flag_ac_2)
{
    free_stack(stack);
    if(flag_ac_2)
        free_matrix(av);
    write(1,"Error\n",6);
    exit(1);
}

int error_syntax(char *s)
{   
    if(!(*s == '-' || *s == '+' || (*s >= '0' && *s <= '9')))
        return (1);
    if(((*s == '-' || *s == '+') && !(s[1] >= '0' && s[1] <= '9')))
        return (1);
    while(*++s)
    {  
        if(!(*s >= '0' && *s <= '9'))
            return (1);
    }
    return (0);
}
int error_repetition(t_stack_node *a, int nbr)
{
    if(a == NULL)
        return (1);
    while(a)
    {
        if(a->value == nbr)
            return (0);
        a = a->next;
    }
    return (1);
}