/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:07:23 by florianma         #+#    #+#             */
/*   Updated: 2021/09/14 12:38:15 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_count(char const *str, char c)
{
	int	i;
	int	compteur;

	i = 0;
	compteur = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			compteur++;
		while (str[i] != c && str[i])
			i++;
	}
	return (compteur);
}

char	**ft_allocate(char const *s, char c, char **dest, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		while (s[k] == c && s[k])
			k++;
		while (s[k] != c && s[k])
		{
			j++;
			k++;
		}
		dest[i] = (char *)malloc((j + 1) * sizeof(char));
		if (dest[i] == NULL)
			return (NULL);
		i++;
		j = 0;
	}
	dest[i] = 0;
	return (dest);
}

char	**fill_it_up(char const *s, char c, char **dest, int size)
{	
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		while (s[k] == c && s[k])
			k++;
		while (s[k] != c && s[k])
		{
			dest[i][j] = s[k];
			j++;
			k++;
		}
		dest[i][j] = '\0';
		j = 0;
		i++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count(s, c);
	dest = (char **)malloc((size + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	ft_allocate(s, c, dest, size);
	fill_it_up(s, c, dest, size);
	return (dest);
}
