/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_for_a_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:54:49 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/13 15:54:59 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sa_checker(t_stack **a)
{
	swap(a);
}

void	pa_checker(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	ra_checker(t_stack **a)
{
	rotate(a);
}

void	rra_checker(t_stack **a)
{
	reverse_rotate(a);
}
