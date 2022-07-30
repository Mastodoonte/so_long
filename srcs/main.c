/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:26:52 by flmastor          #+#    #+#             */
/*   Updated: 2021/09/30 20:53:39 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	key_hook(t_global *global)
{	
	global->counter_m = global->counter_m + 1;
	if (global->counter_m == 1)
	{
		write(1, "Move = 1\n", 9);
	}
	else
	{
		write(1, "Moves = ", 8);
		ft_putnbr(global->counter_m);
		write(1, "\n", 1);
	}
	return (1);
}

int	key_hook_pressed(int keypass, t_global *global)
{
	if (keypass == 119)
		up_moove(global);
	if (keypass == 115)
		down_moove(global);
	if (keypass == 97)
		left_moove(global);
	if (keypass == 100)
		right_moove(global);
	if (keypass == 65307)
		close_win(global);
	return (0);
}

int	mini_win(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->info->height)
	{
		udr_mini_win(global, i);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_info		*info;
	t_position	pos;
	t_win		win;
	t_global	global;
	int			error;

	info = NULL;
	error = 0;
	if (ac == 2)
	{
		info = info_init(info);
		error = error_gestion(av, info);
		if (error == 1)
			error_msg(info, 1);
		creation_window(&win, info);
		global.counter_m = 0;
		global.info = info;
		transfer_img(&global, &win, &pos);
		display_texture(&global, av, info);
		get_pos_p(&global);
		mlx_hook(win.win_ptr, 2, 1L << 0, key_hook_pressed, &global);
		mlx_hook(win.win_ptr, 17, 0, close_win_cross, &global);
		mlx_hook(win.win_ptr, 12, 1L << 15, mini_win, &global);
		mlx_loop(win.mlx_ptr);
	}
}
