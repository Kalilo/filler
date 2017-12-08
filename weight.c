/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 09:56:52 by khansman          #+#    #+#             */
/*   Updated: 2016/11/10 09:39:17 by khansman         ###   ########.fr       */
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
			if (ON_MAP && ON_PIE && PIE_POS == '*')
			{
				weight += scan_imm_foe(info, counts);
				if ((weight < 5 && *best_weight < 5) && (CUR_DIST <= best_dist))
					SET_BEST;
			}
			counts.x++;
		}
		counts.y++;
	}
	SET_BEST2;
	return (weight);
}
