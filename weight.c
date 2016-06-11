#include "filler.h"

int		scan_imm_foe(t_data *info, t_coord pos)
{
	t_coord		counts;
	int			weight;
	
	weight = 0;
	counts.y = 0;
	counts.x = -1;
	while (++counts.x < 3)
	{
		if (ON_MAP01)
			if (ft_is_foe(info->player, info->map.g[pos.y - 1][pos.x - 1 + counts.x]))
				weight += 10;
	debug_mess("imm_foe 1 weight = ", weight);
	}
	counts.x = -1;
	if (ON_MAP01 && ft_is_foe(info->player, info->map.g[pos.y][pos.x - 1]))
		weight += 10;
	debug_mess("imm_foe 2 weight = ", weight);
	counts.x = 1;
	if (ON_MAP01 && ft_is_foe(info->player, info->map.g[pos.y][pos.x + 1]))
		weight += 10;
	counts.x = -1;
	debug_mess("imm_foe 3 weight = ", weight);
	while(++counts.x < 3)
	{
		if (ON_MAP01)
			if (ft_is_foe(info->player, info->map.g[pos.y - 1][pos.x - 1 + counts.x]))
				weight += 10;
		counts.x++;
	}
	debug_mess("imm_foe 4 weight = ", weight);
	return (weight);
}

int		weight_option(t_data *info, t_coord pos, int *best_weight, t_coord *best)
{
	t_coord		counts;
	int			weight;
	t_coord		overlap;
	
	weight = 0;
	counts.y = pos.y;
	overlap = find_overlap(info, pos);
	weight = ft_est_angle(NE_FOE, overlap, find_furthest_point(info, pos, overlap));
	debug_mess("weight option 1 weight = ", weight);
	while (counts.y < info->piece.y + pos.y)
	{
		counts.x = pos.x;
		while (counts.x < info->piece.x + pos.y)
		{
			if (ON_MAP && info->piece.g[counts.y - pos.y][counts.x - pos.x] == '*')
					weight += scan_imm_foe(info, counts);
			counts.x++;
	debug_mess("weight option 2 weight = ", weight);
		}
		counts.y++;
	}
	if (weight >= *best_weight)
	{
		*best_weight = weight;
		*best = pos;
	}
	debug_mess("weight_option 1 weight = ", weight);
	return (weight);
}
