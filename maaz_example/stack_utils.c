/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:01:12 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/12 17:01:18 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*t_stack_new(int number)
{
	t_stack	*block;

	block = malloc(sizeof(t_stack));
	if (!block)
		return (NULL);
	block->content = number;
	block->index_to_top = 0;
	block->next = NULL;
	return (block);
}

t_stack	*last_block(t_stack *a)
{
	t_stack	*block;

	block = a;
	if (!block)
		return (NULL);
	while (block->next != NULL)
		block = block->next;
	return (block);
}

void	t_stack_add(t_stack **a, t_stack *new_block)
{
	t_stack	*block;

	if (!a)
		return ;
	if (*a == NULL)
	{
		if (!new_block)
			return ;
		*a = new_block;
	}
	else
	{
		block = last_block(*a);
		block->next = new_block;
	}
}

int	t_stack_len(t_stack *a)
{
	int		len;
	t_stack	*ptr;

	len = 0;
	ptr = a;
	while (ptr != NULL)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}

char	*t_stack_init(t_stack **a, char **strings, int len)
{
	int			i;
	long long	number;

	i = 0;
	number = 0;
	while (i < len)
	{
		if (!ft_atol_modified(strings[i], &number))
			return (NULL);
		if (!repetition_error(a, number))
			return (NULL);
		t_stack_add(a, t_stack_new(number));
		i++;
	}
	return ("Initialised");
}

// void	print_t_stack(t_stack *a)
// {
// 	t_stack *block;

// 	block = a;
// 	while (block != NULL)
// 	{
// 		printf("%d ", block->content);
// 		block = block->next;
// 	}
// 	printf("\n");
// }