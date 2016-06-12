#include "filler.h"

int		test_point(t_data *info, t_coord pos, int *best_weight, t_coord *best)
{
	t_coord		counts;
	int			found;
	counts.y = 0;
	found = 0;
	//dprintf(debugfd, "test_point\n");
	while (counts.y < info->piece.y)
	{
		counts.x = 0;
		while (counts.x < info->piece.x)
		{
			if (info->piece.g[counts.y][counts.x] != '.')
			{
				if (!(ON_MAP01))
					return (0);
				if (ON_MAP01 && MAP_POS != '.')
				{
					if (!(found) && !(ft_is_foe(info->player, MAP_POS)))
						found = 1;
					else
						return (0);
				}
			}
			counts.x++;
		}
		counts.y++;
	}
	if (counts.y == info->piece.y && counts.x == info->piece.x && found)
		return (weight_option(info, pos, best_weight, best));
	return (0);
}

int		scan_arr(t_data *info)
{
	t_coord		best;
	int			best_weight;
	t_coord		counts;
	
	dprintf(debugfd, "scan_arr\n");
    if (info->piece.y == 0)
        return (1);
	counts.y = 1 - info->piece.y;
	best_weight = 0;
	while (counts.y < info->piece.y + info->map.y - 1)
	{
		counts.x = 1 - info->piece.x;
		while (counts.x < info->piece.x + info->map.x -1)
		{
			test_point(info, counts, &best_weight, &best);
			counts.x++;
		}
		counts.y++;
	}
	give_result(best);
	return (best_weight);
}
