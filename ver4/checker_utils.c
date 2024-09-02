/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:23:54 by rcreer            #+#    #+#             */
/*   Updated: 2024/09/02 19:24:48 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "push_swap.h"

void	stack_init_checker(t_stack_node **a, char **av, bool flag_ac_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			error_free_checker(a, av, flag_ac_2);
		nbr = ft_atol(av[i]);
		if ((nbr > INT_MAX || nbr < INT_MIN) || !(error_repetition(*a,
					(int)nbr)))
			error_free_checker(a, av, flag_ac_2);
		append_node(a, (int)nbr);
		i++;
	}
	if (flag_ac_2)
		free_matrix(av);
}

void	error_free_checker(t_stack_node **stack, char **av, bool flag_ac_2)
{
	free_stack(stack);
	if (flag_ac_2)
		free_matrix(av);
	write(2, "Error\n", 6);
	exit(1);
}

int	only_space_checker(char **s)
{
	int	i;
	int	f;

	i = 1;
	f = 0;
	while (s[i])
	{
		while (s[i][f])
		{
			if (s[i][f] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}

void	ac_checker_checker(int ac, char **av)
{
	if (ac == 1)
		exit(1);
	else if ((ac == 2 && !av[1][0]))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	ok_or_ko(t_stack_node *a, int len)
{
	if (stack_sorted(a) && stack_len(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
