/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:28:35 by rcreer            #+#    #+#             */
/*   Updated: 2024/09/02 17:32:10 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *s)
{
	int		conv;
	long	res;
	int		i;

	res = 0;
	conv = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			conv *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * conv);
}

static void	bool_checker(bool flag_ac_2, char **av)
{
	if (flag_ac_2)
		free_matrix(av);
}

int	stack_init(t_stack_node **a, char **av, bool flag_ac_2)
{
	long	nbr;
	int		i;
	int		check;

	i = 0;
	check = 1;
	while (av[i])
	{
		if (error_syntax(av[i]))
		{
			check = error_free(a, av, flag_ac_2);
			break ;
		}
		nbr = ft_atol(av[i]);
		if ((nbr > INT_MAX || nbr < INT_MIN) || !(error_repetition(*a,
					(int)nbr)))
		{
			check = error_free(a, av, flag_ac_2);
			break ;
		}
		append_node(a, (int)nbr);
		i++;
	}
	bool_checker(flag_ac_2, av);
	return (check);
}
