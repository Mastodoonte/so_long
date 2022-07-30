/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:39:45 by flmastor          #+#    #+#             */
/*   Updated: 2021/09/30 11:51:39 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	help_check_m(char **tmp, char **line, int *file, char **av)
{
	*tmp = NULL;
	*line = NULL;
	*file = open(av[1], O_RDONLY);
	if (*file < 0)
		exit(EXIT_FAILURE);
}

static int	end_check(char**tmp, char **line, int *file, t_info *info)
{
	(void)line;
	(void)file;
	check_first_last_line(*tmp, info);
	if (info->stop_reading > 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static void	under_check_map(char **tmp, char **line, int *ret, t_info *info)
{
	if (*ret == 1 && info->finish == 0)
		free(*tmp);
	load_gnl(*line, *ret, info);
	if (*line && info->finish == 0)
	{
		*tmp = ft_calloc(sizeof(char), ft_strlen(*line) + 1);
		ft_strlcpy(*tmp, *line, ft_strlen(*line) + 1);
	}
	if (info->stop_reading > 0)
	{
		*ret = -1;
	}
	free(*line);
}

int	under_check_map2(char **tmp, char **line, int path, t_info *info)
{
	if (path == 1)
	{
		if (*tmp)
			free(*tmp);
		free(*line);
		return (1);
	}
	if (path == 2)
	{
		free(*line);
		info->finish++ ;
		return (1);
	}
	if (path == 3)
	{
		if (*tmp)
			free(*tmp);
	}
	return (0);
}

int	check_map(char **av, t_info *info)
{
	int		file;
	int		ret;
	char	*line;
	char	*tmp;

	ret = 1;
	check_inside(&file, info, av);
	help_check_m(&tmp, &line, &file, av);
	while (ret > 0)
	{
		ret = get_next_line(file, &line, &ret);
		if (ret == 0)
			under_check_map2(&tmp, &line, 2, info);
		if (ret == 0 && info->finish == 1)
		{
			if (end_check(&tmp, &line, &file, info) == 1)
				return (under_check_map2(&tmp, &line, 1, info));
			else
				under_check_map2(&tmp, &line, 3, info);
			break ;
		}
		under_check_map(&tmp, &line, &ret, info);
	}
	close(file);
	return (0);
}
