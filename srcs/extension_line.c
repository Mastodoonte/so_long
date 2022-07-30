/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:39:59 by flmastor          #+#    #+#             */
/*   Updated: 2021/09/30 12:12:17 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber_extension(char *extension, char *good_extension)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (extension[i] && extension[i] != '.')
	{
		i++;
	}
	if (extension[i] == '\0')
		return (1);
	while (extension[i + j] && good_extension[j])
	{
		if (extension[i + j] == good_extension[j])
			j++;
		else
			break ;
	}
	if (extension[i + j] == '\0' && good_extension[j] == '\0')
		return (0);
	else
		return (1);
}

void	check_first_last_line(char *line, t_info *info)
{
	int	i;

	i = 0;
	if (info->height > 1)
	{
		if (info->width != (int)ft_strlen(line))
		{
			error_msg(info, 0);
		}
	}
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			error_msg(info, 0);
		i++;
	}
}

void	udr_check_line(char c, t_info *info)
{
	if (c == 'E')
		info->exit = info->exit + 1;
	if (c == 'C')
		info->collectible = info->collectible + 1;
	if (c == 'P')
		info->player = info->player + 1;
}

void	check_line(char *line, t_info *info)
{
	int	i;

	i = -1;
	if ((line && info && (line[0] != '1'
				|| line[info->width - 1] != '1')) && info->height == 1)
		error_msg(info, 2);
	while (line[++i] && line && info)
	{	
		if (i == 0 || i == info->width - 1)
		{
			if (line[i] != '1')
				error_msg1(info, &line);
		}
		else
		{
			if (line[i] != 'P' && line[i] != 'C'
				&& line[i] != 'E' && line[i] != '0' && line[i] != '1')
				error_msg1(info, &line);
			udr_check_line(line[i], info);
		}
	}
}

void	free_img(t_global *global, t_win *win)
{
	if (global->image_ground->img)
		mlx_destroy_image(global->win->mlx_ptr, global->image_ground->img);
	if (global->image_wall->img)
		mlx_destroy_image(global->win->mlx_ptr, global->image_wall->img);
	if (global->image_king->img)
		mlx_destroy_image(global->win->mlx_ptr, global->image_king->img);
	if (global->image_ennemy->img)
		mlx_destroy_image(global->win->mlx_ptr, global->image_ennemy->img);
	if (global->image_door->img)
		mlx_destroy_image(global->win->mlx_ptr, global->image_door->img);
	if (global->image_bomb->img)
		mlx_destroy_image(global->win->mlx_ptr, global->image_bomb->img);
	free(global->image_ground);
	free(global->image_wall);
	free(global->image_king);
	free(global->image_ennemy);
	free(global->image_door);
	free(global->image_bomb);
	free(global->info);
	mlx_destroy_window(global->win->mlx_ptr, global->win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	free(win->mlx_ptr);
	ft_putstr("Error\nImage missing into textures's folder\n");
	exit(EXIT_FAILURE);
}
