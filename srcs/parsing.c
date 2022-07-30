/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:08:34 by florianma         #+#    #+#             */
/*   Updated: 2021/09/30 20:51:57 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_add_map(char **g_map, char *line, int height)
{
	int	i;

	i = 0;
	g_map[height] = (char *)malloc(ft_strlen(line) + 1);
	if (!g_map[height])
		return (0);
	while (line[i])
	{
		g_map[height][i] = line[i];
		i++;
	}
	g_map[height][i] = '\0';
	return (0);
}

int	display_line(t_global *global, char *line, int count)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '0')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
					global->image_ground->img, i * 40, count * 40);
		else if (line[i] == '1')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
					global->image_wall->img, i * 40, count * 40);
		else if (line[i] == 'P')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
					global->image_king->img, i * 40, count * 40);
		else if (line[i] == 'P')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
					global->image_king->img, i * 40, count * 40);
		else if (line[i] == 'E')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
					global->image_door->img, i * 40, count * 40);
		else if (line[i] == 'C')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
					global->image_bomb->img, i * 40, count * 40);
	}
	return (0);
}

void	get_pos_p(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (global->map[i])
	{
		j = 0;
		while (global->map[i][j])
		{
			if (global->map[i][j] == 'P')
			{
				global->position->x = (j) * 40 ;
				global->position->y = (i) * 40;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	udr_mini_win(t_global *global, int h)
{
	int	i;

	i = -1;
	while (global->map[h][++i])
	{
		if (global->map[h][i] == '0')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
					global->image_ground->img, i * 40, h * 40);
		else if (global->map[h][i] == '1')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
					global->image_wall->img, i * 40, h * 40);
		else if (global->map[h][i] == 'P')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
					global->image_king->img, i * 40, h * 40);
		else if (global->map[h][i] == 'P')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
					global->image_king->img, i * 40, h * 40);
		else if (global->map[h][i] == 'E')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
					global->image_door->img, i * 40, h * 40);
		else if (global->map[h][i] == 'C')
			mlx_put_image_to_window(global->win->mlx_ptr, global->win->win_ptr, \
					global->image_bomb->img, i * 40, h * 40);
	}
	return (0);
}

int	display_texture(t_global *global, char **av, t_info *info)
{
	int		ret;
	int		fd;
	char	*line;
	int		i_h;

	global->map = (char **)malloc((sizeof(char *)) * (info->height + 1));
	if (!global->map)
		return (1);
	fd = open(av[1], O_RDONLY);
	i_h = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line, &ret);
		if (ret == 0)
			break ;
		ft_add_map(global->map, line, i_h);
		display_line(global, line, i_h);
		free(line);
		i_h++;
	}
	free(line);
	global->map[i_h] = 0;
	close(fd);
	return (0);
}
