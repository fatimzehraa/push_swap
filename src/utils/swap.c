/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:58:56 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/03 13:28:09 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "push_swap.h"
#include <stdio.h>

void sa(t_list **stack_a)
{
	int tmp;

	if (ft_lstsize(*stack_a) > 1)
	{
		tmp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = tmp;
	}
	else
		return ;
}

void sb(t_list **stack_b)
{
	int tmp;

	if (ft_lstsize(*stack_b) > 1)
	{
		tmp = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = tmp;
	}
	else
		return ;
}

void ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
