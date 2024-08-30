/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_for_both_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:55:12 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/13 15:55:13 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ss_checker(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

void	rr_checker(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	rrr_checker(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
