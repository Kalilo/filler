#include "filler.h"

int		give_result(t_coord best)
{
	dprintf(debugfd, "ft_give_result y=%i x=%i\n", best.y, best.x);
	ft_putstr_fd(ft_itoa(best.y), 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(ft_itoa(best.x), 1);
	ft_putstr_fd("\n", 1);
	return (1);
}
