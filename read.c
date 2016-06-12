/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 09:57:02 by khansman          #+#    #+#             */
/*   Updated: 2016/06/12 13:14:49 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	*re_malloc(char *line, size_t size)
{
	char				*tmp;

	tmp = ft_strnew(size + 50);
	if (size > 0)
	{
		tmp = ft_strcpy(tmp, line);
		free(line);
	}
	return (tmp);
}

static int	get_line(int fd, char **line)
{
	static unsigned int	k;
	char				buff;
	char				*l;

	read(fd, &buff, 1);
	while (buff != '\n' && buff != '\0')
	{
		if (k % 50 == 0 || k == 0)
			l = re_malloc(l, k);
		l[k] = buff;
		if (buff != 0)
			k++;
		read(fd, &buff, 1);
	}
	*line = l;
	if (k > 0)
	{
		k = 0;
		return (1);
	}
	return (0);
}

int			get_player(t_data *info)
{
	char				**l;
	char				*line;

	if (!(get_line(0, &line)))
		return (0);
	l = ft_strsplit(line, ' ');
	if (ft_strcmp(l[2], "p1") == 0)
		info->player = 1;
	else if (ft_strcmp(l[2], "p2") == 0)
		info->player = 2;
	else
		return (0);
	return (1);
}

static int	process_pos(int lines, int *size, char *line, t_data *map)
{
	char				**l;

	l = ft_strsplit(line, ' ');
	if (lines == 2)
	{
		map->map.y = ft_atoi(l[1]);
		map->map.x = ft_atoi(l[2]);
		*size = *size + map->map.y;
	}
	else if (lines > 3 && lines < *size)
	{
		if (map->piece.y == 0)
			store_arr(&map->map, l[1], lines - 4);
		else
			store_arr(&map->piece, l[0], (lines - (map->map.y + 5)));
	}
	else if (lines == 4 + map->map.y && map->piece.x == 0)
	{
		map->piece.y = ft_atoi(l[1]);
		map->piece.x = ft_atoi(l[2]);
		*size = *size + map->piece.y;
	}
	else if (lines <= *size && lines > map->map.y + 4)
		store_arr(&map->piece, l[0], (lines - (map->map.y + 5)));
	return (1);
}

int			read_input(int fd, t_data *map)
{
	int					done;
	int					size;
	int					lines;
	char				*line;

	done = 0;
	size = 4;
	lines = 2;
	while (!(done))
	{
		if (!(get_line(fd, &line)))
			done = (0);
		process_pos(lines, &size, line, map);
		lines++;
		free(line);
		if (lines >= size + 1)
			done = 1;
	}
	if (map->piece.y != 0)
		return (1);
	return (0);
}
