#include "filler.h"

int	ft_abs(int num)
{
	if (num > 0)
		return (num);
	return (-num);
}

int	ft_is_foe(int player, char pos)
{
	if (player == 1 && (pos == 'x' || pos == 'X'))
		return (1);
	if (player == 2 && (pos == 'o' || pos == 'O')
		return (1);
	if (!(player == 1 || player == 2))
		return (-1);
	return (0);
}