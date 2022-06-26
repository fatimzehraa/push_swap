/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:59:56 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/26 13:00:59 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

void	sort_3(t_list **stack_a, int start)
{
	if ((*stack_a)->p == start + 1 && (*stack_a)->next->p == start + 0)
		sa(stack_a);
	else if ((*stack_a)->p == start + 2 && (*stack_a)->next->p == start + 0)
		ra(stack_a);
	else if ((*stack_a)->p == start + 1 && (*stack_a)->next->p == start + 2)
		rra(stack_a);
	if (is_sorted(*stack_a))
		return ;
	else
		sa(stack_a);
	sort_3(stack_a, start);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size > 3)
		push_node_b(stack_a, stack_b, 0, size / 2);
	if (size > 4)
		push_node_b(stack_a, stack_b, 1, size / 2);
	sort_3(stack_a, size - 3);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
