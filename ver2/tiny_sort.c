/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:33:30 by rcreer            #+#    #+#             */
/*   Updated: 2024/08/29 22:34:27 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_highest(t_stack_node *stack)
{
	int				max;
	t_stack_node	*highest;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			highest = stack;
		}
		stack = stack->next;
	}
	return (highest);
}

void	tiny_sort(t_stack_node **stack)
{
	t_stack_node	*max;

	max = find_highest(*stack);
	if (max && *stack == max)
		ra(stack, false);
	else if (max && (*stack)->next == max)
		rra(stack, false);
	if ((*stack) && (*stack)->value > (*stack)->next->value)
		sa(stack, false);
}

void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}

// int main()
// {
//     t_stack_node *node1;

//     node1 = malloc(sizeof(t_stack_node));
//     node1->next = malloc(sizeof(t_stack_node));
//     node1->next->next = malloc(sizeof(t_stack_node));
//     node1->prev = NULL;
//     node1->value = 5;
//     node1->next->value = 4;
//     node1->next->next->value = 3;
//     node1->next->prev = node1;
//     node1->next->next->prev = node1->next;
//     node1->next->next->next = NULL;

//     t_stack_node *node2;

//     node2 = malloc(sizeof(t_stack_node));
//     node2->next = malloc(sizeof(t_stack_node));
//     node2->next->next = malloc(sizeof(t_stack_node));
//     node2->next->next->next = malloc(sizeof(t_stack_node));
//     node2->next->next->next->next = malloc(sizeof(t_stack_node));
//     node2->prev = NULL;
//     node2->value = -3;
//     node2->next->value = -48;
//     node2->next->next->value = 100;
//     node2->next->next->next->value = 9;
//     node2->next->next->next->next->value = -1;
//     node2->next->prev = node2;
//     node2->next->next->prev = node2->next;
//     node2->next->next->next->prev = node2->next->next;
//     node2->next->next->next->next->prev = node2->next->next->next;
//     node2->next->next->next->next->next = NULL;

//     tiny_sort(&node1);
//     // set_target_node(node1,node2);

//     init_nodes(node1,node2);
//     print_stack(&node1,'v','1');
//     print_stack(&node2,'v','2');

//     // current_pos(node1);
//     // current_pos(node2);
//     // set_price(node1,node2);

// }