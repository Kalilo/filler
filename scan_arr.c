/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:19:05 by khansman          #+#    #+#             */
/*   Updated: 2016/06/12 10:34:10 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		test_point(t_data *info, t_coord pos, int *best_weight, t_coord *best)
{
	t_coord		counts;
	int			found;

	counts.y = 0;
	found = 0;
	while (counts.y < info->piece.y)
	{
		counts.x = 0;
		while (counts.x < info->piece.x)
		{
			if (info->piece.g[counts.y][counts.x] != '.')
			{
				QUIT_CON01;
				EXIT_CON;
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

	if (info->piece.y == 0)
		return (1);
	counts.y = 1 - info->piece.y;
	best_weight = 0;
	while (counts.y < info->piece.y + info->map.y - 1)
	{
		counts.x = 1 - info->piece.x;
		while (counts.x < info->piece.x + info->map.x - 1)
		{
			test_point(info, counts, &best_weight, &best);
			counts.x++;
		}
		counts.y++;
	}
	give_result(best);
	return (best_weight);
}
