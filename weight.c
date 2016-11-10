/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 09:56:52 by khansman          #+#    #+#             */
/*   Updated: 2016/06/12 15:36:46 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		scan_imm_foe(t_data *info, t_coord pos)
{
	int			weight;

	weight = 0;
	if (ON_MA00 && ft_is_foe(info->player, info->map.g[pos.y - 1][pos.x]))
		weight += 10;
	if (ON_MA01 && ft_is_foe(info->player, info->map.g[pos.y + 1][pos.x]))
		weight += 10;
	if (ON_MA02 && ft_is_foe(info->player, info->map.g[pos.y][pos.x - 1]))
		weight += 10;
	if (ON_MA03 && ft_is_foe(info->player, info->map.g[pos.y][pos.x + 1]))
		weight += 10;
	if (ON_MA04 && ft_is_foe(info->player, info->map.g[pos.y - 1][pos.x - 1]))
		weight += 7;
	if (ON_MA05 && ft_is_foe(info->player, info->map.g[pos.y - 1][pos.x + 1]))
		weight += 7;
	if (ON_MA06 && ft_is_foe(info->player, info->map.g[pos.y + 1][pos.x - 1]))
		weight += 7;
	if (ON_MA07 && ft_is_foe(info->player, info->map.g[pos.y + 1][pos.x + 1]))
		weight += 7;
	return (weight);
}

int		weight_option(t_data *info, t_coord pos,
		int *best_weight, t_coord *best)
{
	t_coord		counts;
	int			weight;
	t_coord		overlap;
	static int	best_dist = 2147483647;

	weight = 1;
	counts.y = pos.y;
	overlap = find_overlap(info, pos);
	while (counts.y < info->piece.y + pos.y)
	{
		counts.x = pos.x;
		while (counts.x < info->piece.x + pos.x)
		{
			if (ON_MAP && ON_PIE && PIE_POS == '*') {
				weight += scan_imm_foe(info, counts);
				t_coord tmp;
				tmp.x = pos.x + counts.x;
				tmp.y = pos.y + counts.y;
				if ((weight < 5 && *best_weight < 5) && (BEST_DIST) {
					weight = 2;
					*best = pos;
					*best_weight = weight;
					best_dist = ft_dist(tmp, find_nearest_foe(info, tmp));
				}
			}
			counts.x++;
		}
		counts.y++;
	}
	if ((weight > *best_weight))
	{
		*best_weight = weight;
		*best = pos;
	}
	return (weight);
}
