/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 13:16:10 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/26 13:18:06 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "list.h"
#include "push_swap.h"
#include <stdio.h>

int	is_sorted(t_list *stack_a)
{
	int	pos;

	if (stack_a == NULL)
		return (0);
	pos = stack_a->p;
	while (stack_a)
	{
		if (pos > stack_a->p)
			return (0);
		pos = stack_a->p;
		stack_a = stack_a->next;
	}
	return (1);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = (*stack_b)->next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = tmp;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = tmp;
}
