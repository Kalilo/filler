/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 13:41:25 by khansman          #+#    #+#             */
/*   Updated: 2016/06/07 16:35:47 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* These functions are used to debuf the program.
 * They are to be removed before final submission.
 */

#include "filler.h"

#include <sys/uio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int		write_map_data(t_data data)
{
	int			k;
	int			l;

	k = 0;
//print first line
	ft_putstr_fd("\t\t---ft_test_var---\n", debugfd);
	ft_putstr_fd("This file contains the variable information stored from the filler output.\n", debugfd);
//print player:
	ft_putstr_fd("Player:\t", debugfd);
	ft_putstr_fd(ft_itoa(data.player), debugfd);
//print map size
	ft_putstr_fd("\nMap Size:\t", debugfd);
	ft_putstr_fd(ft_itoa(data.map.y), debugfd);
	ft_putstr_fd("\t", debugfd);
	ft_putstr_fd(ft_itoa(data.map.x), debugfd);
	ft_putstr_fd("\n", debugfd);
//print map
	ft_putstr_fd("Map:\n\t\t", debugfd);
	while(k < data.map.y)
	{
		l = 0;
		while (l < data.map.x)
		{
			ft_putchar_fd(data.map.g[k][l], debugfd);
			l++;
		}
		k++;
	}
//print piece size
	ft_putstr_fd("\nPiece Size\n\t\t", debugfd);
	ft_putstr_fd(ft_itoa(data.piece.y), debugfd);
	ft_putstr_fd("\t\t", debugfd);
	ft_putstr_fd(ft_itoa(data.piece.x), debugfd);
	ft_putstr_fd("\n", debugfd);
//print piece
	ft_putstr_fd("Piece:\n", debugfd);
	k = 0;
	while (k < data.piece.y)
	{
		l = 0;
		while (l < data.piece.x)
		{
			ft_putchar_fd(data.piece.g[k][l], debugfd);
			l++;
		}
		k++;
	}
//printing done
	return (1);
}
