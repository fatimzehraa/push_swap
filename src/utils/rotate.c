/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimzehra </var/spool/mail/fatimzehra>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:21:38 by fatimzehra        #+#    #+#             */
/*   Updated: 2022/06/06 00:13:21 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "list.h"
#include "push_swap.h"

void ra(t_list **stack_a)
{
	t_list *last_node;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	last_node = ft_lstlast(*stack_a);
	last_node->next = *stack_a;
	*stack_a = (*stack_a)->next;
	last_node->next->next = NULL;
}

void rb(t_list **stack_b)
{
	t_list *last_node;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	last_node = ft_lstlast(*stack_b);
	last_node->next = *stack_b;
	*stack_b = (*stack_b)->next;
	last_node->next->next = NULL;
}

void rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
