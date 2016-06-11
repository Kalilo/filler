#include "filler.h"

int	free_g(char ***arr, int rows)
{
	int		k;
	
	k = 0;
	while (k < rows)
	{
		free(**arr[k]);
		k++;
	}
	free(*arr);
	return (1);
}

int free_s(char ***arr)
{
	int		k;
	
	k = 0;
	while ((*arr[0][k] != '\0') && (*arr[0][k] != 0))
	{
		free(*arr[0][k]);
		k++;
	}
	free(*arr);
	return (1);
}