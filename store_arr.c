/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 09:56:44 by khansman          #+#    #+#             */
/*   Updated: 2016/06/12 10:03:05 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_malloc_arr(t_grid *grid)
{
	int			k;

	k = 0;
	grid->g = (char **)ft_strnew((grid->y + 1) * sizeof(char *));
	while (k < grid->y)
	{
		grid->g[k] = (char *)ft_strnew((grid->x + 30) * sizeof(char));
		k++;
	}
	return (1);
}

int		store_arr(t_grid *grid, char *line, int cur_line)
{
	int			k;
	static int	didmalloc;

	k = 0;
	if (cur_line == 0)
	{
		didmalloc++;
		ft_malloc_arr(grid);
	}
	while (k < grid->x)
	{
		grid->g[cur_line][k] = line[k];
		k++;
	}
	return (1);
}
