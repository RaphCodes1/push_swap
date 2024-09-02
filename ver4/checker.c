/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:26:15 by rcreer            #+#    #+#             */
/*   Updated: 2024/09/02 19:30:04 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void	error(t_stack_node **a, t_stack_node **b, char *s)
{
	free_stack(a);
	free_stack(b);
	free(s);
	write(2, "Error\n", 6);
	exit(1);
}

static void	push_swap_cmd(t_stack_node **a, t_stack_node **b, char *s)
{
	if (ft_strcmp(s, "pa\n") == 0)
		pa(a, b, true);
	else if (ft_strcmp(s, "pb\n") == 0)
		pb(b, a, true);
	else if (ft_strcmp(s, "ra\n") == 0)
		ra(a, true);
	else if (ft_strcmp(s, "rb\n") == 0)
		rb(b, true);
	else if (ft_strcmp(s, "rr\n") == 0)
		rr(a, b, true);
	else if (ft_strcmp(s, "rra\n") == 0)
		rra(a, true);
	else if (ft_strcmp(s, "rrb\n") == 0)
		rrb(b, true);
	else if (ft_strcmp(s, "rrr\n") == 0)
		rrr(a, b, true);
	else if (ft_strcmp(s, "sa\n") == 0)
		sa(a, true);
	else if (ft_strcmp(s, "sb\n") == 0)
		sb(b, true);
	else
		error(a, b, s);
}

static void	error_space(char **av)
{
	write(2, "Error\n", 6);
	free_av_checker(av);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*next_line;
	int				len;

	a = NULL;
	b = NULL;
	ac_checker_checker(ac, av);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (only_space_checker(av))
			error_space(av);
	}
	stack_init_checker(&a, av + 1, ac == 2);
	len = stack_len(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		push_swap_cmd(&a, &b, next_line);
		free(next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	ok_or_ko(a, len);
	free_stack(&a);
}
