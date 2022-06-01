/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:31:51 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/01 19:46:14 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}
