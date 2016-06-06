#include "filler.h"

int		ft_malloc_arr(t_grid *grid)
{
	int		k;

	k = 0;
	grid->g = (char **)malloc((grid->y + 1) * sizeof(char *));
	while (k < grid->y)
	{
		grid->g[k] = (char *)malloc((grid->x + 1) * sizeof(char));
		k++;
	}
	return (1);
}
//store_arr(char **arr, int columns, int rows, int cur_line)
int		store_arr(t_grid *grid, char *line, int cur_line)
{
	int		k;

	k = 0;
	if (cur_line == 0)
		ft_malloc_arr(grid);
	while (k < grid->x)
	{
		grid->g[cur_line - 1][k] = line[k];
		k++;
	}
	return (1);
}
