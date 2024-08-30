/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:30:58 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/12 16:59:52 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack	*cheapest_block(t_stack *a, t_stack *b)
{
	int		least_price;
	int		push_price;
	t_stack	*cheapest_block;
	t_stack	*temp_b;

	least_price = push_cost(a, b, b, target_block(b, a, 'b'));
	cheapest_block = b;
	temp_b = b;
	while (b != NULL)
	{
		push_price = push_cost(a, temp_b, b, target_block(b, a, 'b'));
		if (push_price < least_price)
		{
			cheapest_block = b;
			least_price = push_price;
		}
		b = b->next;
	}
	return (cheapest_block);
}

t_stack	*find_max_block(t_stack *a)
{
	t_stack	*max;

	max = a;
	while (a != NULL)
	{
		if (a->content > max->content)
			max = a;
		a = a->next;
	}
	return (max);
}

t_stack	*find_min_block(t_stack *a)
{
	t_stack	*min;

	min = a;
	while (a != NULL)
	{
		if (a->content < min->content)
			min = a;
		a = a->next;
	}
	return (min);
}
