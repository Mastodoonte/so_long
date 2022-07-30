/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:34:51 by florianma         #+#    #+#             */
/*   Updated: 2021/09/30 15:55:23 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	transfer_img_2(t_global *global)
{
	t_image	image_king;
	t_image	image_ennemy;
	t_image	image_bomb;

	global->image_king = malloc(sizeof(image_king));
	if (!global->image_king)
		return (1);
	global->image_ennemy = malloc(sizeof(image_ennemy));
	if (!global->image_ennemy)
		return (1);
	global->image_bomb = malloc(sizeof(image_bomb));
	if (!global->image_bomb)
		return (1);
	global->image_king->img = mlx_xpm_file_to_image(global->win->mlx_ptr, \
			"textures/king_right.xpm", &global->image_king->width, \
			&global->image_ground->height);
	global->image_ennemy->img = mlx_xpm_file_to_image(global->win->mlx_ptr, \
			"textures/ennemy.xpm", &global->image_ennemy->width, \
			&global->image_ennemy->height);
	global->image_bomb->img = mlx_xpm_file_to_image(global->win->mlx_ptr, \
			"textures/bomb.xpm", &global->image_bomb->width, \
			&global->image_bomb->height);
	return (0);
}

int	udr_transfer_img(t_global *global, t_win *win, t_position *position)
{
	t_image	image_wall;
	t_image	image_ground;
	t_image	image_door;	

	global->win = win;
	global->position = position;
	global->image_ground = malloc(sizeof(image_ground));
	if (!global->image_ground)
		return (1);
	global->image_wall = malloc(sizeof(image_wall));
	if (!global->image_wall)
		return (1);
	global->image_door = malloc(sizeof(image_door));
	if (!global->image_door)
		return (1);
	return (0);
}

int	transfer_img(t_global *global, t_win *win, t_position *position)
{
	if (udr_transfer_img(global, win, position) == 1)
		return (1);
	global->image_ground->img = mlx_xpm_file_to_image(global->win->mlx_ptr, \
			"textures/ground.xpm", &global->image_ground->width, \
			&global->image_ground->height);
	global->image_wall->img = mlx_xpm_file_to_image(global->win->mlx_ptr, \
			"textures/wall.xpm", &global->image_wall->width, \
			&global->image_wall->height);
	global->image_door->img = mlx_xpm_file_to_image(global->win->mlx_ptr, \
		"textures/door.xpm", &global->image_door->width, \
		&global->image_door->height);
	transfer_img_2(global);
	if (!global->image_ground->img || !global->image_wall->img
		|| !global->image_door->img || !global->image_king->img
		|| !global->image_ennemy->img || !global->image_bomb->img)
	{
		free_img(global, win);
	}
	return (0);
}

int	creation_window(t_win *win, t_info *info)
{
	if (info->width > 48 || info->height > 25)
	{
		free(info);
		write(1, "Error\nThe size is too big\n", 26);
		exit(EXIT_FAILURE);
	}
	win->width = info->width * 40;
	win->height = info->height * 40;
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == 0)
		return (0);
	win->win_ptr = mlx_new_window(win->mlx_ptr, \
			win->width, win->height, "so_long");
	if (win->win_ptr == 0)
		return (0);
	return (0);
}

void	collection_item(t_global *global)
{
	int	x;
	int	y;

	x = global->position->x / 40;
	y = global->position->y / 40;
	if (global->map[x][y] == 'C')
	{
		global->map[x][y] = '0';
		global->info->collected = global->info->collected + 1;
	}
}
