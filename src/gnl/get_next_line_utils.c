/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <fael-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:03:13 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/26 13:31:56 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "push_swap.h"

void	ft_strncpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strncpy(s, s1, s1_len);
	ft_strncpy(s + s1_len, s2, s2_len);
	free(s1);
	return (s);
}

int	is_new_line(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
