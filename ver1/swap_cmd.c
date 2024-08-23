#include "push_swap.h"

static void swap_cmd(t_stack_node **stack)
{
    *stack = (*stack)->next;
    (*stack)->prev->prev = *stack;
    (*stack)->prev->next = (*stack)->next;
    if((*stack)->next)
        (*stack)->next->prev = (*stack)->prev;
    (*stack)->next = (*stack)->prev;
    (*stack)->prev = NULL;
}

void sa(t_stack_node **a,bool checker)
{
    swap_cmd(a);
    if(!checker)
        write(1,"sa\n",1);
}

void sb(t_stack_node **b,bool checker)
{
    swap_cmd(b);
    if(!checker)
        write(1,"sb\n",3);
}

void sb(t_stack_node **b,bool checker)
{
    swap_cmd(b);
    if(!checker)
        write(1,"sb\n",3);
}

void ss(t_stack_node **a, t_stack_node **b, bool checker)
{   
    swap_cmd(a);
    swap_cmd(b);
    if(!checker)
        write(1,"ss\n",3);
}