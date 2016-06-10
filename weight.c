#include "filler.h"

int		scan_imm_foe(t_data *info, t_coord pos)
{
	t_coord		counts;
	int			weight;
	
	weight = 0;
	counts.x = -1;
	while (++counts.x < 3)
	{
		if (pos.y - 1 >= 0 && pos.x - 1 + counts.x >= 0)
			if (ft_is_foe(info->player, info->map.g[pos.y - 1][pos - 1 + counts.x]))
				weight += 5;
	}
	if ((pos.x - 1 >= 0 && ft_is_foe(info->player, info->map.g[pos.y][pos.x - 1]))
		weight += 5;
	if (ft_is_foe(info->player, info->map.g[pos.y][pos.x + 1]))
		weight += 5;
		counts.x = -1
	while(++counts.x < 3)
	{
		if (pos.y - 1 >= 0 && pos.x - 1 + counts.x >= 0)
			if (ft_is_foe(info->player, info->map.g[pos.y - 1][pos - 1 + counts.x]))
				weight += 5;
		counts.x++;
	}
	return (weight);
}

int		weight_option(t_data *info, t_coord pos, int *best_weight)
{
	t_coord		counts;
	int			weight;
	t_coord		overlap;
	
	counts.y = pos.y;
	overlap = find_overlap(&info, pos);
	weight = ft_est_angle(find_nearest_foe(&info, overlap), overlap, 
		find_furthest_point(&info, pos, overlap));
	while (counts.y < info->piece.y + pos.y)
	{
		counts.x = pos.x;
		while (counts.x < info->piece.x + pos.y)
		{
			if (ft_on_map(&info, counts) && 
				info->piece[counts.y - pos.y][counts.x - pos.x] == '*')
					weight += scan_imm_foe(&info, counts);
			counts.x++;
		}
		counts.y++;
	}
}