#include "push_swap.h"

static void rotate(t_stack_node **stack)
{
    t_stack_node *last_node;    
    int len;

    len = stack_len(*stack);
    if(!stack || !*stack || len == 1)
        return ;
    last_node = find_last_node(*stack);
    last_node->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
}
void ra(t_stack_node **a, bool checker)
{
    rotate(a);
    if(!checker)
        write(1,"ra\n",3);
}
void rb(t_stack_node **b, bool checker)
{
    rotate(b);
    if(!checker)
        write(1,"rb\n",3);
}

void rr(t_stack_node **a, t_stack_node **b, bool checker)
{   
    rotate(a);
    rotate(b);
    if(!checker)
        write(1,"rr\n",3);
}