#include "filler.h"

int	ft_on_map(t_data *info, t_coord pos)
{
	if (pos.x < 0 || pos.y < 0)
		return (0);
	if 	(pos.x >= info->map.x || pos.y >= info->map.y)
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
			if (counts.y >= 0 && counts.x >= 0 && MAP_FUL)
					return (counts);
			counts.x++;
		}
		counts.y++;
	}
	return (0);
}

t_coord	find_furthest_point(t_data *info, t_coord pos, t_coord overlap)
{
	t_coord		counts;
	t_coord		furthest;
	
	counts.y = 0;
	furthest.x = overlap.x;
	furthest.y = overlap.y;
	while (counts.y < info->piece.x + pos.y)
	{
		counts.x = 0;
		while (counts.x < info->piece.x + pos.x)
		{
			if (counts.y >= 0 && counts.x >= 0 && PIE_FUL)
			{
				if ((MTH01 + MTH02) > (MTH03 + MTH04))
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
	while (counts.y < info->map.y)
	{
		counts.x = 0;
		while (counts.x < info->map.x)
		{
			if (ft_is_foe(info->player, info->map.g[counts.y][counts.x]))
			{
				if ((MTH05 + MTH06) < (nearest.x + nearest.y))
					nearest = counts;
			}
			counts.x++;
		}
		counts.y++;
	}
	return (nearest);
}
