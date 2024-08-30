/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:30:17 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/12 17:00:16 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	reverse_rotate_ab(t_stack **a, t_stack **b, t_stack *cheapest,
		t_stack *target)
{
	rrr(a, b);
	cheapest->index_to_top++;
	target->index_to_top++;
}

void	rotate_a(t_stack **a, t_stack *target)
{
	ra(a);
	target->index_to_top--;
}

void	reverse_rotate_a(t_stack **a, t_stack *target)
{
	rra(a);
	target->index_to_top++;
}

void	rotate_b(t_stack **b, t_stack *cheapest)
{
	rb(b);
	cheapest->index_to_top--;
}

void	reverse_rotate_b(t_stack **b, t_stack *cheapest)
{
	rrb(b);
	cheapest->index_to_top++;
}
