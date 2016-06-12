/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 09:56:24 by khansman          #+#    #+#             */
/*   Updated: 2016/06/12 15:28:33 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_on_map(t_data *info, int y, int x)
{
	if (x < 0 || y < 0)
		return (0);
	if (x >= info->map.x || y >= info->map.y)
		return (0);
	return (1);
}

int		ft_on_piece(t_data *info, int y, int x)
{
	if (x < 0 || y < 0)
		return (0);
	if (x >= info->piece.x || y >= info->piece.y)
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
	return (counts);
}

t_coord	find_furthest_point(t_data *info, t_coord pos, t_coord overlap)
{
	t_coord		counts;
	t_coord		furthest;
	t_coord		temp;

	counts.y = 0;
	furthest.x = overlap.x;
	furthest.y = overlap.y;
	while (counts.y < info->piece.y)
	{
		counts.x = 0;
		while (counts.x < info->piece.x)
		{
			if (ON_PIE2 && PIE_FUL)
			{
				temp.y = counts.y + pos.y;
				temp.x = counts.x + pos.x;
				if (ft_dist(counts, overlap) > ft_dist(furthest, overlap))
					furthest = temp;
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
			if (ON_MAP && ft_is_foe(info->player, M_POS00))
			{
				if ((MTH03) < (MTH04))
					nearest = counts;
			}
			counts.x++;
		}
		counts.y++;
	}
	return (nearest);
}
