/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:56:23 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/03 15:20:45 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "push_swap.h"
#include <stdio.h>

void pa(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	if (*stack_b == NULL)
		return ;
	tmp = (*stack_b)->next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = tmp;
}

void pb(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	if (*stack_a == NULL)
		return ;
	tmp = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = tmp;
}
