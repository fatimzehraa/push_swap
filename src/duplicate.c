/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimzehra </var/spool/mail/fatimzehra>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:12:17 by fatimzehra        #+#    #+#             */
/*   Updated: 2022/06/21 09:13:26 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((sizeof(char) * ft_strlen(s1)) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char **ft_duplicate(int argc, char **argv)
{
	int i;

	char **splitted_nb;

	splitted_nb = malloc(argc * sizeof(char **));
	if (splitted_nb == NULL)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		splitted_nb[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	splitted_nb[i] = NULL;
	return (splitted_nb);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_duplicated_number(char **splitted_nb)
{
	int i;
	int j;

	i = 0;
	while (splitted_nb[i])
	{
		j = i + 1;
		while (splitted_nb[j])
		{
			if (ft_strcmp(splitted_nb[i], splitted_nb[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
