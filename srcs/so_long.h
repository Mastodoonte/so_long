/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:14:53 by flmastor          #+#    #+#             */
/*   Updated: 2021/09/30 20:34:10 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_info
{
	int	width;
	int	height;
	int	collectible;
	int	exit;
	int	player;
	int	finish;
	int	stop_reading;
	int	collected;
}					t_info;

typedef struct s_win
{
	void	*win_ptr;
	void	*mlx_ptr;
	int		width;
	int		height;
}					t_win;

typedef struct s_position
{
	int	x;
	int	y;
}					t_position;

typedef struct s_image
{
	void	*img;
	int		width;
	int		height;
}					t_image;

typedef struct s_global
{
	t_win		*win;
	t_image		*image_ground;
	t_image		*image_wall;
	t_image		*image_king;
	t_image		*image_king_left;
	t_image		*image_ennemy;
	t_image		*image_door;
	t_image		*image_bomb;
	t_position	*position;
	t_info		*info;
	char		**map;
	int			counter_m;
}			t_global;

int		get_next_line(int fd, char **line, int *ret);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
void	error_msg(t_info *info, int id_error);
void	*info_init(t_info *info);
void	display(t_info *info);
char	*ft_strcpy(char *dest, char *src);
int		check_map(char **av, t_info *info);
int		check_ber_extension(char *extension, char *good_extension);
int		error_gestion(char **av, t_info *info);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	check_line(char *line, t_info *info);
void	check_first_last_line(char *line, t_info *info);
void	ft_putstr(char *str);
int		transfer_img_2(t_global *global);
int		transfer_img(t_global *global, t_win *win, t_position *position);
int		creation_window(t_win *win, t_info *info);
int		display_texture(t_global *global, char **av, t_info *info);
int		display_line(t_global *global, char *line, int count);
int		ft_add_map(char **g_map, char *line, int height);
int		error_gestion(char **av, t_info *info);
void	get_pos_p(t_global *global);
void	ft_putnbr(int nb);
int		ft_putchar(char c);
void	left_moove(t_global *global);
void	right_moove(t_global *global);
void	down_moove(t_global *global);
void	up_moove(t_global *global);
int		key_hook_pressed(int keypass, t_global *global);
void	collection_item(t_global *global);
int		key_hook(t_global *global);
void	close_win(t_global *global);
void	load_gnl(char *line, int ret, t_info *info);
void	error_msg1(t_info *info, char **line);
void	collection_item(t_global *global);
int		udr_transfer_img(t_global *global, t_win *win, t_position *position);
int		close_win_cross(t_global *global);
void	close_win(t_global *global);
int		close_winn(t_global *global);
int		udr_mini_win(t_global *global, int h);
int		key_hook(t_global *global);
int		mini_win(t_global *global);
void	check_inside(int *file, t_info *info, char **av);
void	help_close(t_global *global);
void	free_img(t_global *global, t_win *win);

#endif
