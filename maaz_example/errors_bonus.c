/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:55:50 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/13 15:55:53 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	error_msg_bonus(t_stack **a, t_stack **b, char *instruct)
{
	t_stack_clear(a);
	t_stack_clear(b);
	if (instruct)
		free(instruct);
	write(2, "Error\n", 6);
	exit(1);
	return (0);
}
