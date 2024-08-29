/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:36:10 by rcreer            #+#    #+#             */
/*   Updated: 2024/08/29 22:36:35 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_cmd(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*to_push;

	if (!*src)
		return ;
	to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	to_push->prev = NULL;
	if (!*dest)
	{
		*dest = to_push;
		to_push->next = NULL;
	}
	else
	{
		to_push->next = *dest;
		to_push->next->prev = to_push;
		*dest = to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	push_cmd(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	push_cmd(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
