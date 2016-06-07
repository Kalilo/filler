/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:23:04 by khansman          #+#    #+#             */
/*   Updated: 2016/06/06 14:45:53 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	process_pos(int lines, int *size, char *line, t_data *map)
{
	char	**l;

	l = ft_strsplit(line, ' ');
	if (lines == 1)
	{
		if (l[2] = "p1")
			map.player = 1;
		else
			map.player = 2;
	}
	if (lines == 2) 
	{
		map.map.y = ft_atoi(l[1]);
		map.map.x = ft_atoi(l[2]);
		size += map.map.y;
	}
	if (2 < line && line < size)
		store_arr(&map.map, line, lines - 3);
	if (line == size && map.piece_x == 0)
	{
		map.piece.y = ft_atoi(l[1]);
		map.piece.x = ft_atoi(l[2]);
		size += map.piece_y;
	}
	free2d_str(l);//write function
	return (1);
}

int			read_input(int fd, t_data *map)
{
	int		done;
	int		size;
	int		line_no;
	char	*line;

	done = 0;
	size = 4;
	line_no = 1;
	while(!(done))
	{
		if (!(getnextline(fd, &line)))
			return (0);
		process_pos(line_no, &size, line, map);
		line_no++;
		free(line);
		if (line == size)
			done = 1;
	}
	return (1);
}
