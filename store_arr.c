#include "filler.h"

int		ft_malloc_arr(t_grid *grid)
{
	int		k;

	k = 0;
	grid->g = (char **)ft_strnew((grid->y + 1) * sizeof(char *));
//	ft_putstr_fd("ft_malloc_arr:\tAllocated grid->g\n", debugfd);
//		ft_putstr_fd("ft_malloc_arr:\tAllocating grid->g[", debugfd);
	while (k < grid->y)
	{
//		ft_putstr_fd(" ", debugfd);
//		ft_putnbr_fd(k, debugfd);
//		ft_putstr_fd(" ", debugfd);
		grid->g[k] = (char *)ft_strnew((grid->x + 30) * sizeof(char));
		k++;
	}
//		ft_putstr_fd("]\n", debugfd);
//		ft_putstr_fd("ft_malloc_arr:\tReturning 1\n", debugfd);
	return (1);
}

int				store_arr(t_grid *grid, char *line, int cur_line)
{
	int			k;
	static int	didmalloc;

//		ft_putstr_fd("\nENTERING FILE:store_arr.c\n", debugfd);
	k = 0;
//		ft_putstr_fd("store_arr:\tint 'cur_line' = ", debugfd);
//		ft_putnbr_fd(cur_line, debugfd);
//		ft_putstr_fd("\n", debugfd);
	//didmalloc++;
	if (cur_line == 0 /*&& (didmalloc % 2 == 0 || didmalloc < 2)*/)
	{
		didmalloc++;
		ft_malloc_arr(grid);
	}
//	ft_putstr_fd("line[k] = ", debugfd);
//	ft_putstr_fd(&line[k], debugfd);
//	ft_putstr_fd("\n", debugfd);
//	ft_putstr_fd("store_arr:\tReading line[k] to grid->g[", debugfd);
	while (k < grid->x)
	{
		grid->g[cur_line][k] = line[k];
//		ft_putstr_fd(" ", debugfd);
//		ft_putnbr_fd(k, debugfd);
//		ft_putstr_fd(" ", debugfd);

		k++;
	}
		ft_putstr_fd("]\n", debugfd);
//	ft_putstr_fd("store_arr:\tReturning 1\n", debugfd);
	ft_putstr_fd("EXITING FILE:store_arr.c\n\n", debugfd);
	return (1);
}
