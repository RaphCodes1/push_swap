/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:01:00 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/13 15:52:21 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "pushswap.h"

static void	print_msg(t_stack *a, t_stack *b)
{
	if (!is_sorted(a, b))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

static char	*perform_instruct(char *instruct, t_stack **a, t_stack **b)
{
	if (ft_memcmp(instruct, "pa\n", ft_strlen(instruct)) == 0)
		pa_checker(a, b);
	else if (ft_memcmp(instruct, "pb\n", ft_strlen(instruct)) == 0)
		pb_checker(b, a);
	else if (ft_memcmp(instruct, "sa\n", ft_strlen(instruct)) == 0)
		sa_checker(a);
	else if (ft_memcmp(instruct, "sb\n", ft_strlen(instruct)) == 0)
		sb_checker(b);
	else if (ft_memcmp(instruct, "ra\n", ft_strlen(instruct)) == 0)
		ra_checker(a);
	else if (ft_memcmp(instruct, "rb\n", ft_strlen(instruct)) == 0)
		rb_checker(b);
	else if (ft_memcmp(instruct, "rra\n", ft_strlen(instruct)) == 0)
		rra_checker(a);
	else if (ft_memcmp(instruct, "rrb\n", ft_strlen(instruct)) == 0)
		rrb_checker(b);
	else if (ft_memcmp(instruct, "rr\n", ft_strlen(instruct)) == 0)
		rr_checker(a, b);
	else if (ft_memcmp(instruct, "rrr\n", ft_strlen(instruct)) == 0)
		rrr_checker(a, b);
	else if (ft_memcmp(instruct, "ss\n", ft_strlen(instruct)) == 0)
		ss_checker(a, b);
	else
		return (NULL);
	return ("Success");
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*instruct;

	a = NULL;
	b = NULL;
	instruct = NULL;
	if (argc > 1)
	{
		if (!parsing(&a, argc, argv))
			return (error_msg_bonus(&a, &b, instruct));
		instruct = get_next_line(0);
		while (instruct)
		{
			if (!perform_instruct(instruct, &a, &b))
				return (error_msg_bonus(&a, &b, instruct));
			free(instruct);
			instruct = get_next_line(0);
		}
		free(instruct);
		print_msg(a, b);
	}
	t_stack_clear(&a);
	t_stack_clear(&b);
}
