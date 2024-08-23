#include "push_swap.h"

static void rev_rotate(t_stack_node **stack)
{
    t_stack_node *last_node = find_last_node(*stack);
    last_node->prev->next = NULL;
    last_node->next = *stack;
    *stack = last_node;
    last_node->next->prev = last_node;
    last_node->prev = NULL;
}
void rra(t_stack_node **a,bool checker)
{
    rev_rotate(a);
    if(!checker)
        write(1,"rra\n",4);
}

void rrb(t_stack_node **b,bool checker)
{
    rev_rotate(b);
    if(!checker)
        write(1,"rrb\n",4);
}
void rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
    rev_rotate(a);
    rev_rotate(b);
    if(!checker)
        write(1,"rrr\n",4);
}