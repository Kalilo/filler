#include "filler.h"

/*int	free_g(char ***arr, int rows)
{
	int		k;
	
	k = 0;
	while (k < rows)
	{
		free((void *)**arr[k]);
		k++;
	}
	free((void *)*arr);
	return (1);
}

int free_s(char ***arr)
{
	int		k;
	
	k = 0;
	while ((*arr[0][k] != '\0') && (*arr[0][k] != 0))
	{
		free((void *)*arr[0][k]);
		k++;
	}
	free(*arr);
	return (1);
}*/

int reset_info(t_data *info)
{
	info->map.y = 0;
	info->map.x = 0;
	info->piece.y = 0;
	info->piece.x = 0;
	
	//free((void *)info->piece.g);
	//free((void *)info->map.g);
	return (1);
}
