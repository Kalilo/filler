/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 11:16:07 by khansman          #+#    #+#             */
/*   Updated: 2016/06/06 14:37:10 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_malloc_arr(t_grid *grid)
{
	int		k;

	k = 0;
	grid.g = (char **)malloc((grid.y + 1) * sizeof(char *));
	while (k < grid.y)
	{
		grid.g[k] = (char *)malloc((grid.x + 1) * sizeof(char));
		k++;
	}
	return (1);
}
//store_arr(char **arr, int columns, int rows, int cur_line)
int		store_arr(s_grid *grid, char **line, int cur_line)
{
	int		k;

	k = 0;
	if (cur_line == 0)
		ft_malloc_arr(*grid);
	while (k < grid.x)
	{
		arr[cur_line - 1][k] = line[k];
		k++;
	}
	return (1);
}
