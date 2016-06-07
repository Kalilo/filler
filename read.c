#include "filler.h"
#include <stdio.h>	//DEBUG CODE! :D

static int	process_pos(int lines, int *size, char *line, t_data *map)
{
	char	**l;

	l = ft_strsplit(line, ' ');
	printf("String Succesfully Split\n");
	if (lines == 1)
	{
		if (ft_strcmp(l[2], "p1") == 0)
			map->player = 1;
		else
			map->player = 2;
	printf("Player assigned\n");
	}
	if (lines == 2)
	{
		map->map.y = ft_atoi(l[1]);
		map->map.x = ft_atoi(l[2]);
		size += map->map.y;
	printf("Map size determined\n");
	}
	if (2 < lines && lines < *size)
		store_arr(&map->map, line, lines - 3);//write function
	if (lines == *size && map->piece.x == 0)
	{
		map->piece.y = ft_atoi(l[1]);
		map->piece.x = ft_atoi(l[2]);
		*size += map->piece.y;
	printf("Piece size determined\n");
	}
//	free2d_str(l);//write function
	return (1);
}

int			read_input(int fd, t_data *map)
{
	int		done;
	int		size;
	int		lines;
	char	*line;

	done = 0;
	size = 4;
	lines = 1;
	while(!(done))
	{
		if (!(get_next_line(fd, &line)))
			return (0);
		printf("Running process_pos\n");
		process_pos(lines, &size, line, map);
		lines++;
		free(line);
		if (lines == size)
			done = 1;
	}
	return (1);
}
