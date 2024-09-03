/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:37:19 by rcreer            #+#    #+#             */
/*   Updated: 2024/08/29 22:37:39 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_pos(t_stack_node *stack)
{
	int	len;
	int	i;

	i = 0;
	if (!stack)
		return ;
	len = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= len)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*holder_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		holder_a = a;
		while (holder_a)
		{
			if (holder_a->value > b->value
				&& holder_a->value < best_match_index)
			{
				best_match_index = holder_a->value;
				target_node = holder_a;
			}
			holder_a = holder_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = b_len - b->current_position;
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += a_len - (b->target_node->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			holder_best_match;
	t_stack_node	*cheapest_node;

	if (!b)
		return ;
	holder_best_match = LONG_MAX;
	while (b)
	{
		if (b->push_price < holder_best_match)
		{
			holder_best_match = b->push_price;
			cheapest_node = b;
		}
		b->cheapest = false;
		b = b->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	current_pos(a);
	current_pos(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
