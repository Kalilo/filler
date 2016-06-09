#include "filler.h"

static int	process_pos(int lines, int *size, char *line, t_data *map)
{
	char	**l;

	l = ft_strsplit(line, ' ');
	ft_putstr_fd("read.c\t\tprocess_pos:\tString Succesfully Split\n", debugfd);
	if (lines == 1)
	{
		ft_putstr_fd("read.c\t\tprocess_pos:\tDetermining Player\n", debugfd);
		if (ft_strcmp(l[2], "p1") == 0)
			map->player = 1;
		else
			map->player = 2;
		ft_putstr_fd("read.c\t\tprocess_pos:\tPlayer assigned\n", debugfd);
	}
	if (lines == 2)
	{
		ft_putstr_fd("read.c\t\tprocess_pos:\tDetermining Map Dimensions\n", debugfd);
		map->map.y = ft_atoi(l[1]);
		map->map.x = ft_atoi(l[2]);
		size += map->map.y;
		ft_putstr_fd("read.c\t\tprocess_pos:\tMap size determined\n", debugfd);
	}
	if (2 < lines && lines < *size)
	{ // DEBUG
		ft_putstr_fd("read.c\t\tprocess_pos:\tRunning store_arr\n", debugfd);
		store_arr(&map->map, line, lines - 3);
		ft_putstr_fd("read.c\t\tprocess_pos:\tSuccesfully used store_arr\n", debugfd);
	} // DEBUG
	if (lines == *size && map->piece.x == 0)
	{
		ft_putstr_fd("read.c\t\tprocess_pos:\tDetermines Piece Size\n", debugfd);
		map->piece.y = ft_atoi(l[1]);
		map->piece.x = ft_atoi(l[2]);
		*size += map->piece.y;
		ft_putstr_fd("read.c\t\tprocess_pos:\tPiece size determined\n", debugfd);
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
		ft_putstr_fd("read.c\t\tread_input:\tAttempting to GetNextLine\n", debugfd);
		if (!(get_next_line(fd, &line)))
			return (0);
		ft_putstr_fd("read.c\t\tread_input:\tRunning process_pos\n", debugfd);
		process_pos(lines, &size, line, map);
		lines++;
		ft_putstr_fd("read.c\t\tread_input:\tAttempting to free 'line' from GNL\n", debugfd);
		free(line);
		ft_putstr_fd("read.c\t\tread_input:\tSuccesfully freed 'line' from GNL\n", debugfd);
		if (lines >= size)
			done = 1;
	}
		ft_putstr_fd("read.c\t\tread_input:\tReturning 1\n", debugfd);
	return (1);
}
