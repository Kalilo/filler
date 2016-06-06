/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:23:04 by khansman          #+#    #+#             */
/*   Updated: 2016/06/06 10:48:28 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	process_pos(int line, int *size, char *line, t_data *map)
{
	char	**l;

	l = ft_strsplit(line, ' ');
	if (line == 1)
		if (l[2] = "p1")
			map.player = 1;
		else
			map.player = 2;
	if (line == 2)
	{
		map.map_y = ft_atoi(l[1]);
		map.map_x = ft_atoi(l[2]);
		size += map.map_y;
	}
	if (2 < line && line < )
}

int			read(int fd, t_data *map)
{
	int		done;
	int		size;
	int		line;
	char	*line;

	done = 0;
	size = 4;
	line = 1;
	while(!(done))
	{
		if (!(getnextline(fd, &line)))
			return (0);
		process_pos(line, &size, map);
		lines++;
		free(line);
		if (line == size)
			done = 1;
	}
	return (1);
}
