/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:58:56 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/01 21:32:28 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	//{
	//	tmp = (*stack_a)->next->next;
	//	(*stack_a)->next->next = (*stack_a)->next;
	//	(*stack_a)->next = tmp;
	//	(*stack_a) = (*stack_a)->next;
	//}
	else
		perror("stack_a has less than two elements");
}
