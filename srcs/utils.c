/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:41:49 by flmastor          #+#    #+#             */
/*   Updated: 2021/09/30 20:34:29 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	i;
	char			*str;
	unsigned int	total;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total = nmemb * size;
	str = malloc(total);
	if (str == NULL)
		return (NULL);
	if (!(size))
		return (NULL);
	i = 0;
	while (i < total)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	if (!dest || !src)
		return (0);
	i = 0;
	s = ft_strlen(src);
	if (size == 0)
		return (s);
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = s;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	dest = (char *)malloc(ft_strlen(src) * sizeof(char));
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*info_init(t_info *info)
{
	info = (t_info *)malloc(sizeof(t_info));
	info->width = 0;
	info->height = 0;
	info->collectible = 0;
	info->exit = 0;
	info->player = 0;
	info->finish = 0;
	info->stop_reading = 0;
	info->collected = 0;
	return (info);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}
