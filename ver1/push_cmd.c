#include "push_swap.h"

static void push_cmd(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *to_push;

    to_push = *a;
    *a = (*a)->next;
    if(*a)
        (*a)->prev = NULL;
    to_push->prev = NULL;
    if(!*b)
    {
        *b = to_push;
        to_push->next = NULL;
    }
    else
    {
        to_push->next = *b;
        to_push->next->prev = to_push;
        *b = to_push;
    }
}
void pa(t_stack_node **a, t_stack_node **b, bool checker)
{
    push_cmd(a,b);
    if(!checker)
        write(1,"pa\n",3);
}
void pb(t_stack_node **a, t_stack_node **b, bool checker)
{
    push_cmd(b,a);
    if(!checker)
        write(1,"pb\n",3);
}