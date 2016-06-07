/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:24:23 by khansman          #+#    #+#             */
/*   Updated: 2016/06/06 16:46:38 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct		s_grid
{
	char		**g;
	int			y;
	int			x;
}					t_grid;

typefdef struct		s_data
{
	int			player;
	t_grid		map;
	t_grid		piece;
}					t_data;

/*Functions Needed
 * free 2D array
 * store arr
 */

int         read_input(int fd, t_data *map);
int			store_arr(s_grid *grid, char **line, int cur_line);
int			ft_malloc_arr(t_grid *grid);
