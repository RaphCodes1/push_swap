/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:26:15 by rcreer            #+#    #+#             */
/*   Updated: 2024/08/29 22:29:44 by rcreer           ###   ########.fr       */
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

static void	error(t_stack_node **a, t_stack_node **b)
{
	free_stack(a);
	if (!*b || !b)
		return ;
	else
		free_stack(b);
	write(1, "error\n", 6);
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
		error(a, b);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*next_line;
	int				len;

	a = NULL;
	b = NULL;
	if (ac == 1 || !av[1][0])
		return (0);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	stack_init(&a, av + 1, ac == 2);
	len = stack_len(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		push_swap_cmd(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(a) && stack_len(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
}
