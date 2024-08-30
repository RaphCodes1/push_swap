/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:32:38 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/12 17:00:07 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static t_stack	*target_block_for_a(t_stack *element, t_stack *a)
{
	long	target_element;
	t_stack	*temp;
	t_stack	*target;

	target_element = (long)INT_MIN - 1;
	target = a;
	temp = a;
	while (a != NULL)
	{
		if (element->content > a->content && target_element < a->content)
		{
			target_element = a->content;
			target = a;
		}
		a = a->next;
	}
	if (target_element == (long)INT_MIN - 1)
		target = find_max_block(temp);
	return (target);
}

static t_stack	*target_block_for_b(t_stack *element, t_stack *a)
{
	long	target_element;
	t_stack	*temp;
	t_stack	*target;

	target_element = (long)INT_MAX + 1;
	target = a;
	temp = a;
	while (a != NULL)
	{
		if (element->content < a->content && target_element > a->content)
		{
			target_element = a->content;
			target = a;
		}
		a = a->next;
	}
	if (target_element == (long)INT_MAX + 1)
		target = find_min_block(temp);
	return (target);
}

t_stack	*target_block(t_stack *element, t_stack *s, char t_stacks)
{
	t_stack	*target;

	if (t_stacks == 'a')
		target = target_block_for_a(element, s);
	else if (t_stacks == 'b')
		target = target_block_for_b(element, s);
	else
		target = NULL;
	return (target);
}
