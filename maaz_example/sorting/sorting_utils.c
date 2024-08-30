/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:31:11 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/12 16:59:56 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	index_to_top(t_stack *element, t_stack *s)
{
	int	index;
	int	mid_line;
	int	len;
	int	index_to_top;

	index = 0;
	len = t_stack_len(s);
	if (len % 2 == 0)
		mid_line = len / 2;
	else
		mid_line = (len / 2) + 1;
	while (s != NULL)
	{
		if (s->content == element->content)
			break ;
		index++;
		s = s->next;
	}
	if (index >= mid_line)
		index_to_top = (len - index) * -1;
	else
		index_to_top = index;
	s->index_to_top = index_to_top;
	return (index_to_top);
}

int	push_cost(t_stack *a, t_stack *b, t_stack *element, t_stack *target)
{
	int	index_to_top_a;
	int	index_to_top_b;
	int	push_price;

	index_to_top_a = index_to_top(element, b);
	index_to_top_b = index_to_top(target, a);
	if (index_to_top_a * index_to_top_b >= 0)
	{
		if (ft_abs(index_to_top_a) > ft_abs(index_to_top_b))
			push_price = ft_abs(index_to_top_a);
		else
			push_price = ft_abs(index_to_top_b);
	}
	else
		push_price = ft_abs(index_to_top_a) + ft_abs(index_to_top_b);
	return (push_price + 1);
}
