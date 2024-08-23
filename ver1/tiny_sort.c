#include "push_swap.h"

int find_highest(t_stack_node **stack)
{
    int max;

    max = 0;
    t_stack_node *tmp = *stack;
    while(tmp) 
    {
        if(tmp->value >= max)
            max = tmp->value;
        tmp = tmp->next;
    }
    return (max);
}

void tiny_sort(t_stack_node **stack)
{
    int max;

    max = find_highest(stack);
    if((*stack)->value == max)
        ra(stack, false);
    else if((*stack)->next->value == max)
        rra(stack, false);
    if((*stack)->value > (*stack)->next->value)
        sa(stack,false);
}

// int main()
// {
//     t_stack_node *node;

//     node = malloc(sizeof(t_stack_node));
//     node->next = malloc(sizeof(t_stack_node));
//     node->next->next = malloc(sizeof(t_stack_node));
//     node->prev = NULL;
//     node->value = 123;
//     node->next->value = 42;
//     node->next->next->value = -4567;
//     node->next->prev = node;
//     node->next->next->prev = node->next;
//     node->next->next->next = NULL;

//     tiny_sort(&node);

//     while(node)
//     {
//         printf("%d\n",node->value);
//         node = node->next;
//     }

// }