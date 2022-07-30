/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:56:58 by flmastor          #+#    #+#             */
/*   Updated: 2021/09/30 11:36:39 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_next_line(int fd, char **line, int *ret)
{
	int		i;
	char	buf;

	*ret = 1;
	if (!line)
		return (-1);
	*line = malloc(1234567);
	**line = 0;
	i = 0;
	buf = 0;
	while (*ret > 0)
	{
		*ret = read(fd, &buf, 1);
		if (buf == '\n')
			break ;
		else if (buf == '\0')
			break ;
		(*line)[i] = buf;
		buf = 0;
		i++;
	}
	(*line)[i] = 0;
	if (*ret == -1)
		**line = 0;
	return (*ret);
}

void	load_gnl(char *line, int ret, t_info *info)
{
	if (ret != 0)
		info->height++;
	if (info->height == 1)
		info->width = ft_strlen(line);
	if (info->height == 1)
		check_first_last_line(line, info);
	if (info->width != ft_strlen(line))
	{
		free(line);
		line = NULL;
		error_msg(info, 1);
		ret = (-1);
	}
	if (info->height > 1)
		check_line(line, info);
}
