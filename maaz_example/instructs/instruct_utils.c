/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:28:20 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/12 16:58:57 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	swap(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = (*b);
	(*b) = (*b)->next;
	if ((*a) == NULL)
	{
		temp->next = NULL;
		(*a) = temp;
	}
	else
	{
		temp->next = *a;
		*a = temp;
	}
}

void	rotate(t_stack **a)
{
	t_stack	*temp;
	t_stack	*current;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	current = *a;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	temp->next = NULL;
}

void	reverse_rotate(t_stack **a)
{
	t_stack	*prev;
	t_stack	*current;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	prev = NULL;
	current = *a;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *a;
	*a = current;
}
