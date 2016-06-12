/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 09:38:35 by khansman          #+#    #+#             */
/*   Updated: 2016/06/12 13:12:54 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	static t_data	gamedata;
	int				k;

	k = 1;
	get_player(&gamedata);
	while (k)
	{
		if (read_input(0, &gamedata))
		{
			k = scan_arr(&gamedata);
			reset_info(&gamedata);
		}
	}
	return (0);
}
