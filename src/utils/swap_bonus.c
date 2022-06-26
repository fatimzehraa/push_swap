/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 13:18:26 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/26 13:19:35 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "push_swap.h"
#include <stdio.h>

void	swap(t_list **stack)
{
	t_list	*node_1;
	t_list	*node_2;
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		node_1 = (*stack);
		node_2 = (*stack)->next;
		tmp = node_2->next;
		node_2->next = node_1;
		node_1->next = tmp;
		*stack = node_2;
	}
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
