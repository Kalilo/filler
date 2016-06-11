#include "filler.h"


int			get_player(t_data *info)
{
	char	**l;
	char	* line;
	if (!(get_next_line(0, lines)))
	return (0);
	if (ft_strcmp(l[2], "p1") == 0)
		map->player = 1;
	else if (ft_strcmp(l[2], "p2") == 0)
		map->player = 2;
	else
		return (0);
	return (1);
}

static int	process_pos(int lines, int *size, char *line, t_data *map)
{
	char	**l;

				ft_putstr_fd("ENTERING FILE:read.c\n\n", debugfd);

	ft_putstr_fd("\nread.c\t\tprocess_pos:\t---Input Variables---\n", debugfd);
	ft_putstr_fd("\tint\t\tlines\t\t[", debugfd);
	ft_putnbr_fd(lines, debugfd);
	ft_putstr_fd("]\n", debugfd);
	ft_putstr_fd("\tint\t\t*size\t\t[", debugfd);
	ft_putnbr_fd(*size, debugfd);
	ft_putstr_fd("]\n", debugfd);
	ft_putstr_fd("\tchar\t\t*line\t\t[", debugfd);
	ft_putstr_fd(line, debugfd);
	ft_putstr_fd("]\n", debugfd);
	ft_putstr_fd("\tt_data\t\t*map:\t\n", debugfd);
	ft_putstr_fd("\t-t_grid\t\tmap\t\n", debugfd);
	ft_putstr_fd("\t--char\t**grid\tTHIS IS THE MAP STORAGE\n", debugfd);
	ft_putstr_fd("\t--int\t\t\ty\t[", debugfd);
	ft_putnbr_fd(map->map.y, debugfd);
	ft_putstr_fd("]\n", debugfd);
	ft_putstr_fd("\t--int\t\t\tx\t[", debugfd);
	ft_putnbr_fd(map->map.x, debugfd);
	ft_putstr_fd("]\n", debugfd);
	
	ft_putstr_fd("\tt_data\t\t*map:\t\n", debugfd);
	ft_putstr_fd("\t-t_grid\t\tpiece\t\n", debugfd);
	ft_putstr_fd("\t--char\t**grid\tTHIS IS THE PIECE STORAGE\n", debugfd);
	ft_putstr_fd("\t--int\t\t\ty\t[", debugfd);
	ft_putnbr_fd(map->piece.y, debugfd);
	ft_putstr_fd("]\n", debugfd);
	ft_putstr_fd("\t--int\t\t\tx\t[", debugfd);
	ft_putnbr_fd(map->piece.x, debugfd);
	ft_putstr_fd("]\n", debugfd);
	
					ft_putstr_fd("read.c\t\tprocess_pos:\t---Input Variables---\n", debugfd);

	l = ft_strsplit(line, ' ');
	if (lines == 1)
	{
//					ft_putstr_fd("read.c\t\tprocess_pos:\tDetermining Player\n", debugfd);
		if (ft_strcmp(l[2], "p1") == 0)
			map->player = 1;
		else
			map->player = 2;
	}
	else if (lines == 2)
	{
//					ft_putstr_fd("read.c\t\tprocess_pos:\tDetermining Map Dimensions\n", debugfd);
		map->map.y = ft_atoi(l[1]);
		map->map.x = ft_atoi(l[2]);
		*size = *size + map->map.y;
//					ft_putstr_fd("read.c\t\tprocess_pos:\tMap Size: [", debugfd);
//					ft_putnbr_fd(*size, debugfd);
//					ft_putstr_fd("]\n", debugfd);
	}
	else if (lines > 3 && lines < *size) //|| (map->piece.y == 0 && lines >= 5 + map->map.y))
	{ // DEBUG
//					ft_putstr_fd("read.c\t\tprocess_pos:\tRunning store_arr\n", debugfd);
		if (map->piece.y == 0)
			store_arr(&map->map, l[1], lines - 4);
		else
		store_arr(&map->piece, l[0], (lines - (map->map.y + 5)));
	} // DEBUG
	else if (lines == 4 + map->map.y && map->piece.x == 0)
	{
//					ft_putstr_fd("read.c\t\tprocess_pos:\tDetermining Piece Size\n", debugfd);
		map->piece.y = ft_atoi(l[1]);
		map->piece.x = ft_atoi(l[2]);
		*size = *size + map->piece.y;
	}
	else if (lines <= *size && lines > map->map.y + 4)
	{
//					ft_putstr_fd("process_pos:\tPiece (M)Allocation [", debugfd);
//					ft_putnbr_fd((lines - (map->map.y + 5)), debugfd);
//					ft_putstr_fd("]\n", debugfd);		
		store_arr(&map->piece, l[0], (lines - (map->map.y + 5)));
	}
//	free2d_str(l);//write function
//					ft_putstr_fd("read.c\t\tprocess_pos:\tReturning 1\n", debugfd);
//					ft_putstr_fd("EXITING FILE:read.c\n\n", debugfd);
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
//		ft_putstr_fd("read.c\t\tread_input:\tlines: [", debugfd);
//		ft_putnbr_fd(lines, debugfd);
//		ft_putstr_fd("]\n", debugfd);
//		ft_putstr_fd("read.c\t\tread_input:\tAttempting to GetNextLine\n", debugfd);
		if (!(get_next_line(fd, &line)))
			return (0);
//		ft_putstr_fd("read.c\t\tread_input:\tRunning process_pos\n", debugfd);
		process_pos(lines, &size, line, map);
		lines++;
		free(line);
//		ft_putstr_fd("read.c\t\tread_input:\tSuccesfully freed 'line' from GNL\n", debugfd);
		if (lines >= size + 1)
			done = 1;
	}
//		ft_putstr_fd("read.c\t\tread_input:\tReturning 1\n", debugfd);
		close(0);
	return (1);
}
