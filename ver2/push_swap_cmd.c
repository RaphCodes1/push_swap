#include "push_swap.h"

static void rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
    while(*a != cheapest_node->target_node && *b != cheapest_node)
        rr(a,b,false);
    current_pos(*a);
    current_pos(*b);
}

static void reverse_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
    while(*a != cheapest_node->target_node && *b != cheapest_node)
        rrr(a,b,false);
    current_pos(*a);
    current_pos(*b);
}

void finish_rotation(t_stack_node **stack, t_stack_node *top_node, char c)
{
    while(*stack != top_node)
    {
        if(c == 'a')
        {
            if(top_node->above_median)
                ra(stack, false);
            else
                rra(stack, false);
        }
        else if(c == 'b')
        {
            if(top_node->above_median)
                rb(stack, false);
            else
                rrb(stack, false);
        }
    }
}
static void move_nodes(t_stack_node **a,t_stack_node **b)
{
    t_stack_node *cheapest_node;

    cheapest_node = return_cheapest(*b);
    if(cheapest_node->above_median && cheapest_node->target_node->above_median)
        rotate_both(a,b, cheapest_node);
    else if(!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
        reverse_rotate_both(a,b, cheapest_node);
    finish_rotation(b, cheapest_node, 'b');
    finish_rotation(a, cheapest_node->target_node, 'a');
    pa(a,b,false);
}
void push_swap(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *smallest;
    int len_a;

    len_a = stack_len(*a);
    if(len_a == 5)
        handle_five(a,b);
    else
    {
        while(len_a-- > 3)
            pb(b,a,false);
    }
    tiny_sort(a);
    while(*b)
    {
        init_nodes(*a,*b);
        move_nodes(a,b);
    }
    current_pos(*a);
    smallest = find_smallest(*a);
    if(smallest->above_median)
        while(*a != smallest)
            ra(a,false);
    else
        while(*a != smallest)
            rra(a,false);
}
