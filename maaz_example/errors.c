/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:32:58 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/13 15:25:40 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	space_only(char *s)
{
	int	i;

	i = 0;
	if (ft_strlen(s) == 0)
		return (1);
	while (s[i] == ' ' && s[i] != '\0')
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

int	error_msg(t_stack **a, t_stack **b)
{
	t_stack_clear(a);
	t_stack_clear(b);
	write(2, "Error\n", 6);
	exit(1);
}

char	*repetition_error(t_stack **a, long number)
{
	t_stack	*block;

	block = (*a);
	while (block)
	{
		if (block->content == number)
			return (NULL);
		block = block->next;
	}
	return ("No repetition");
}
