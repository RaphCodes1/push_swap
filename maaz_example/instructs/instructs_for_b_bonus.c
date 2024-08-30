/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_for_b_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:55:02 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/13 15:55:03 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sb_checker(t_stack **b)
{
	swap(b);
}

void	pb_checker(t_stack **b, t_stack **a)
{
	push(b, a);
}

void	rb_checker(t_stack **b)
{
	rotate(b);
}

void	rrb_checker(t_stack **b)
{
	reverse_rotate(b);
}
