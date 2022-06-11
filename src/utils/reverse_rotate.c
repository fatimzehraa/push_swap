/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimzehra </var/spool/mail/fatimzehra>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 00:14:03 by fatimzehra        #+#    #+#             */
/*   Updated: 2022/06/06 16:59:56 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "push_swap.h"

void rra(t_list **stack_a)
{
	t_list *curr;
	t_list *befor_last;
	t_list *last_node;

	curr = *stack_a;
	while (curr)
	{
		if (curr->next != NULL)
			befor_last = curr;
		curr = curr->next;
	}
	last_node = befor_last->next;
	last_node->next = *stack_a;
	*stack_a = last_node;
	befor_last->next = NULL;
}

void rrb(t_list **stack_b)
{
	t_list *curr;
	t_list *befor_last;
	t_list *last_node;

	curr = *stack_b;
	while (curr)
	{
		if (curr->next != NULL)
			befor_last = curr;
		curr = curr->next;
	}
	last_node = befor_last->next;
	last_node->next = *stack_b;
	*stack_b = last_node;
	befor_last->next = NULL;
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
