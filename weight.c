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

	weight = 0;
	counts.y = pos.y;
	overlap = find_overlap(info, pos);
	weight = ft_est_angle(NE_FOE, overlap, FUR_01);
	while (counts.y < info->piece.y + pos.y)
	{
		counts.x = pos.x;
		while (counts.x < info->piece.x + pos.x)
		{
			if (ON_MAP && ON_PIE && PIE_POS == '*')
				weight += scan_imm_foe(info, counts);
			counts.x++;
		}
		counts.y++;
	}
	if ((weight > *best_weight) || (weight == *best_weight && CLOSER))
	{
		*best_weight = weight;
		*best = pos;
	}
	return (weight);
}
