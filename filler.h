/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:24:23 by khansman          #+#    #+#             */
/*   Updated: 2016/06/06 10:43:52 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typefdef struct		s_data
{
	int			player;
	int			map_x;
	int			map_y;
	char		**map;
	int			piece_x;
	int			piece_y;
	char		**piece;
}					t_data;

/*Functions Needed
 * free 2D array
 */
