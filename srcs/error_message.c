/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:42:11 by flmastor          #+#    #+#             */
/*   Updated: 2021/09/30 20:52:58 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	error_msg1(t_info *info, char **line)
{
	free(*line);
	free(info);
	ft_putstr("Error\n The map must be composed of only : 0, 1 ,C,E, P\n");
	exit(EXIT_FAILURE);
}

void	error_msg(t_info *info, int id_mess)
{
	if (id_mess == 0)
	{
		free(info);
		ft_putstr("Error\n Please verify the extension map\n");
		exit(EXIT_FAILURE);
	}
	if (id_mess == 1)
	{
		free(info);
		ft_putstr("Error\nThe map is not conform !\n");
		exit(EXIT_FAILURE);
	}
	if (id_mess == 2)
	{
		free(info);
		ft_putstr("Error\n The map must be composed of only : 0, 1 ,C,E, P\n");
		exit(EXIT_FAILURE);
	}
	info->stop_reading = 1;
}

int	error_gestion(char **av, t_info *info)
{
	if (check_ber_extension(av[1], ".ber") == 1)
	{
		error_msg(info, 0);
		return (1);
	}
	if (check_map(av, info) == 1)
	{
		error_msg(info, 0);
		return (1);
	}
	if (info->collectible == 0 || info->exit == 0
		|| info->player == 0 || info->exit > 1)
	{
		error_msg(info, 2);
		return (1);
	}
	if (info->player > 1)
	{
		ft_putstr("Error\nCome on, you must have only one player\n");
		return (1);
	}
	return (0);
}
