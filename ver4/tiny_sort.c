/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:33:30 by rcreer            #+#    #+#             */
/*   Updated: 2024/09/02 17:26:07 by rcreer           ###   ########.fr       */
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
