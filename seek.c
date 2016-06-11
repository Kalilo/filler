#include "filler.h"

int	ft_on_map(t_data *info, int y, int x)
{
//	dprintf(debugfd, "ft_on_map y = %i ", y);
//	dprintf(debugfd, "ft_on_map x = %i\n", x);
	if (x < 0 || y < 0)
		return (0);
	if 	(x >= info->map.x || y >= info->map.y)
		return (0);
	return (1);
}

t_coord	find_overlap(t_data *info, t_coord pos)
{
	t_coord		counts;
	
	counts.y = pos.y;
	while (counts.y < info->piece.y + pos.y)
	{
		counts.x = pos.x;
		while (counts.x < info->piece.x + pos.x)
		{
			if (ON_MAP && MAP_FUL)
					return (counts);
			counts.x++;
		}
		counts.y++;
	}
//	dprintf(debugfd, "find_overlap\n");
	return (counts);
}

t_coord	find_furthest_point(t_data *info, t_coord pos, t_coord overlap)
{
	t_coord		counts;
	t_coord		furthest;
	t_coord		temp;
	
	//dprintf(debugfd, "find_furthest_point 1\n");
	counts.y = 0;
	furthest.x = overlap.x;
	furthest.y = overlap.y;
	while (counts.y < info->piece.y)
	{
		counts.x = 0;
		while (counts.x < info->piece.x)
		{
			temp.x = counts.x + pos.x;
			temp.y = counts.y + pos.y;
			if (ON_MAP && PIE_FUL)
			{
				if ((MTH01) > (MTH02))
					furthest = counts;
			}
			counts.x++;
		}
		counts.y++;
	}
	return (furthest);
}

t_coord	find_nearest_foe(t_data *info, t_coord pos)
{
	t_coord		counts;
	t_coord		nearest;
	
	counts.y = 0;
	nearest.x = info->map.x;
	nearest.y = info->map.y;
	//dprintf(debugfd, "find_nearest_foe 1\n");
	while (counts.y < info->map.y)
	{
		counts.x = 0;
	//dprintf(debugfd, "find_nearest_foe 2\n");
		while (counts.x < info->map.x)
		{
	//dprintf(debugfd, "find_nearest_foe 3\n");
			if (ON_MAP && ft_is_foe(info->player, M_POS00))
			{
	//dprintf(debugfd, "find_nearest_foe 4\n");
				if ((MTH03) < (MTH04))
					nearest = counts;
			}
			counts.x++;
		}
		counts.y++;
	}
	//dprintf(debugfd, "find_nearest_foe 5\n");
	return (nearest);
}
