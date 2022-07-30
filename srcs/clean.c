/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:50:50 by flmastor          #+#    #+#             */
/*   Updated: 2021/09/30 20:27:23 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_close(t_global *global)
{
	if (global->map)
		free(global->map);
	if (global->image_ground)
		mlx_destroy_image(global->win->mlx_ptr, global->image_ground->img);
	if (global->image_wall)
		mlx_destroy_image(global->win->mlx_ptr, global->image_wall->img);
	if (global->image_king)
		mlx_destroy_image(global->win->mlx_ptr, global->image_king->img);
	if (global->image_ennemy)
		mlx_destroy_image(global->win->mlx_ptr, global->image_ennemy->img);
	if (global->image_door)
		mlx_destroy_image(global->win->mlx_ptr, global->image_door->img);
	if (global->image_bomb)
		mlx_destroy_image(global->win->mlx_ptr, global->image_bomb->img);
	free(global->image_ground);
	free(global->image_wall);
	free(global->image_king);
}

int	close_winn(t_global *global)
{
	int	i;
	int	max;

	i = 0;
	write(1, "Well done\n", 10);
	max = global->info->height;
	while (i < max)
	{
		free(global->map[i]);
		global->map[i] = NULL;
		i++;
	}
	help_close(global);
	free(global->image_ennemy);
	free(global->image_door);
	free(global->image_bomb);
	free(global->info);
	mlx_destroy_window(global->win->mlx_ptr, global->win->win_ptr);
	if (global->win->mlx_ptr)
	{
		mlx_destroy_display(global->win->mlx_ptr);
		free(global->win->mlx_ptr);
	}
	return (0);
}

void	close_win(t_global *global)
{
	int	i;
	int	max;

	write(1, "Well done\n", 10);
	i = 0;
	max = global->info->height;
	while (i < max)
	{
		free(global->map[i]);
		global->map[i] = NULL;
		i++;
	}
	help_close(global);
	mlx_destroy_window(global->win->mlx_ptr, global->win->win_ptr);
	mlx_destroy_display(global->win->mlx_ptr);
	free(global->win->mlx_ptr);
	free(global->image_ennemy);
	free(global->image_door);
	free(global->image_bomb);
	free(global->info);
	exit(EXIT_SUCCESS);
}

int	close_win_cross(t_global *global)
{
	close_winn(global);
	exit(EXIT_SUCCESS);
}

void	check_inside(int *file, t_info *info, char **av)
{
	char	*test;
	int		try;

	test = NULL;
	*file = open(av[1], O_RDONLY);
	if (*file < 0)
		error_msg(info, 0);
	try = get_next_line(*file, &test, &try);
	if (!(*test) || !test)
	{
		write(1, "Error\nEmpty file\n", 17);
		close(*file);
		if (test)
			free(test);
		free(info);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(*file);
		free(test);
	}
}
