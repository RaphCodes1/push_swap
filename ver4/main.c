/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:30:55 by rcreer            #+#    #+#             */
/*   Updated: 2024/08/29 22:31:38 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_av(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

static int	number_check(char *s)
{
	int	i;

	i = 0;
	if(!s)
		return (1);
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

static void algorithm(t_stack_node **a)
{	
	t_stack_node *b;

	b = NULL;
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, false);
		else if (stack_len(*a) == 3)
			tiny_sort(a);
		else
			push_swap(a, &b);
	}
}

static void ac_checker(int ac, char **av)
{	
	if(ac == 1)
		exit(1);
	else if ((ac == 2 && !av[1][0]))
	{
		write(2,"Error\n",6);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	char			*res;

	a = NULL;
	res = NULL;
	ac_checker(ac,av);
	if (ac == 2)
	{	
		res = split_modif(av);
		if (!number_check(res))
			error_msg_main(res);
		av = ft_split(av[1], ' ');
		free(res);
	}
	else if (ac > 2)
	{
		res = split_modif(av);
		av = ft_split(res, ' ');
		free(res);
	}
	if (stack_init(&a, av + 1, ac == 2))
		algorithm(&a);
	if (ac > 2)
		free_av(av);
	free_stack(&a);
}
