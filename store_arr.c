#include "filler.h"

int		ft_malloc_arr(t_grid *grid)
{
	int		k;

	k = 0;
	grid->g = (char **)ft_strnew((grid->y + 1) * sizeof(char *));
	ft_putstr_fd("store_arr.c\tft_malloc_arr:\tAllocated grid->g\n", debugfd);
	while (k < grid->y)
	{
		ft_putstr_fd("store_arr.c\tft_malloc_arr:\tAllocating grid->g[", debugfd);
		ft_putnbr_fd(k, debugfd);
		ft_putstr_fd("]\n", debugfd);
		grid->g[k] = (char *)ft_strnew((grid->x + 1) * sizeof(char));
		k++;
	}
		ft_putstr_fd("store_arr.c\tft_malloc_arr:\tReturning 1\n\n", debugfd);
	return (1);
}
//store_arr(char **arr, int columns, int rows, int cur_line)
int		store_arr(t_grid *grid, char *line, int cur_line)
{
	int		k;

	k = 0;
		ft_putstr_fd("store_arr.c\tstore_arr:\tint 'cur_line' = ", debugfd);
		ft_putnbr_fd(cur_line, debugfd);
		ft_putstr_fd("\n", debugfd);
	if (cur_line == 0)
		ft_malloc_arr(grid);
	while (k < grid->x)
	{
		grid->g[cur_line][k] = line[k];
		ft_putstr_fd("store_arr.c\tstore_arr:\tReading line[k] to grid->g[", debugfd);
		ft_putnbr_fd(k, debugfd);
		ft_putstr_fd("]\n", debugfd);
		k++;
	}
	ft_putstr_fd("store_arr.c\tstore_arr:\tReturning 1\n\n", debugfd);
	return (1);
}
