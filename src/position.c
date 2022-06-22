/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimzehra </var/spool/mail/fatimzehra>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:02:47 by fatimzehra        #+#    #+#             */
/*   Updated: 2022/06/12 13:35:46 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "push_swap.h"

void	position(t_list *stack_a)
{
	t_list	*curr;


	while (stack_a)
	{
		curr = stack_a->next;
		while (curr)
		{
			if (stack_a->content > curr->content)
				stack_a->p++;
			else
				curr->p++;
			curr = curr->next;
		}
		stack_a = stack_a->next;
	}
}

int	p_index(t_list *stack_a, int position)
{
	int i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->p == position)
			break ;
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}
