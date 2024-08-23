#include "push_swap.h"

t_stack_node *find_last_node(t_stack_node *node)
{   
    if(!node)
        return (NULL);
    while(node->next)
        node = node->next;
    return(node);
}

void append_node(t_stack_node **stack,int nbr)
{
    t_stack_node *node;
    t_stack_node *last_node;

    if(!stack)
        return ;
    node = malloc(sizeof(t_stack_node));
    if(!node)
        return ;
    node->value = nbr;
    node->next = NULL;
    if(*stack == NULL)
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
}