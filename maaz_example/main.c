/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:33:13 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/13 15:56:33 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	// int		i;

	a = NULL;
	b = NULL;
	// i = 1;
	if (argc > 1) // ADD ARG_MAX
	{
		if (!parsing(&a, argc, argv))
			return (error_msg(&a, &b));
		if (!is_sorted(a, b))
			sorting(&a, &b);
		else
		{
			t_stack_clear(&a);
			t_stack_clear(&b);
			return (0);
		}
	}
	t_stack_clear(&a);
	t_stack_clear(&b);
}
