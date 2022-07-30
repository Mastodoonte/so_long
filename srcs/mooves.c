/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:09:27 by florianma         #+#    #+#             */
/*   Updated: 2021/09/30 20:53:57 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	udr_up(t_global *global, int y, int x, int key_pass)
{
	if (key_pass == 0)
	{
		global->map[y - 1][x] = '0';
		global->info->collected = global->info->collected + 1;
	}
	if (key_pass == 1)
	{
		global->map[y + 1][x] = '0';
		global->info->collected = global->info->collected + 1;
	}
	if (key_pass == 2)
	{
		global->map[y][x - 1] = '0';
		global->info->collected = global->info->collected + 1;
	}
	if (key_pass == 3)
	{	
		global->map[y][x + 1] = '0';
		global->info->collected = global->info->collected + 1;
	}
}

void	up_moove(t_global *global)
{
	int	y;
	int	x;

	y = global->position->y / 40;
	x = global->position->x / 40;
	if (global->map[y - 1][x] != '1' && global->map[y - 1][x] != 'E')
	{
		if (global->map[y - 1][x] == 'C')
			udr_up(global, y, x, 0);
		if (global->map[y][x] != 'E')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->\
				win_ptr, global->image_ground->img, \
				global->position->x, global->position->y);
		mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
				global->image_king->img, global->position->x, \
				global->position->y - 40);
		global->map[y][x] = '0';
		global->map[y - 1][x] = 'P';
		global->position->y -= 40;
		key_hook(global);
	}
	else if (global->map[y - 1][x] == 'E'
		&& global->info->collectible == global->info->collected)
		close_win(global);
}

void	down_moove(t_global *global)
{
	int	y;
	int	x;

	y = global->position->y / 40;
	x = global->position->x / 40;
	if (global->map[y + 1][x] != '1' && global->map[y + 1][x] != 'E')
	{
		if (global->map[y + 1][x] == 'C')
			udr_up(global, y, x, 1);
		if (global->map[y][x] != 'E')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win-> \
					win_ptr, global->image_ground->img, \
					global->position->x, global->position->y);
		mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
				global->image_king->img, global->position->x, \
				global->position->y + 40);
		global->map[y + 1][x] = 'P';
		global->map[y][x] = '0';
		global->position->y += 40;
		key_hook(global);
	}
	else if (global->map[y + 1][x] == 'E'
		&& global->info->collectible == global->info->collected)
		close_win(global);
}

void	right_moove(t_global *global)
{
	int	y;
	int	x;

	y = global->position->y / 40;
	x = global->position->x / 40;
	if (global->map[y][x + 1] != '1' && global->map[y][x + 1] != 'E')
	{
		if (global->map[y][x + 1] == 'C')
			udr_up(global, y, x, 2);
		if (global->map[y][x] != 'E')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->\
					win_ptr, global->image_ground->img, \
					global->position->x, global->position->y);
		mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
				global->image_king->img, global->position->x + 40, \
				global->position->y);
		global->map[y][x + 1] = 'P';
		global->map[y][x] = '0';
		global->position->x += 40;
		key_hook(global);
	}
	else if (global->map[y][x + 1] == 'E'
		&& global->info->collectible == global->info->collected)
		close_win(global);
}

void	left_moove(t_global *global)
{
	int	y;
	int	x;

	y = global->position->y / 40;
	x = global->position->x / 40;
	if (global->map[y][x - 1] != '1' && global->map[y][x - 1] != 'E')
	{
		if (global->map[y][x - 1] == 'C')
			udr_up(global, y, x, 3);
		if (global->map[y][x] != 'E')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->\
					win_ptr, global->image_ground->img, \
					global->position->x, global->position->y);
		mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
				global->image_king->img, global->position->x - 40, \
				global->position->y);
		global->map[y][x - 1] = 'P';
		global->map[y][x] = '0';
		global->position->x -= 40;
		key_hook(global);
	}
	else if (global->map[y][x - 1] == 'E'
		&& global->info->collectible == global->info->collected)
		close_win(global);
}
