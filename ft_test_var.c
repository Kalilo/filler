/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 13:41:25 by khansman          #+#    #+#             */
/*   Updated: 2016/06/06 14:53:00 by khansman         ###   ########.fr       */
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
	int			fd;

	k = 0;
	fd = open("map_data.txt", O_CREAT | O_WRONLY);
//print first line
	ft_putstr_fd("This file containsoptput from the data variables\n", fd);
//print player:
	ft_putstr_fd("Player: ", fd);
	ft_putstr_fd(ft_itoa(data.player), fd);
//print map size
	ft_putstr_fd("\nMap Size: ", fd);
	ft_putstr_fd(ft_itoa(data.map.y), fd);
	ft_putchar_fd(' ', fd);
	ft_putstr_fd(ft_itoa(data.map.x), fd);
	ft_putchar_fd('\n', fd);
//print map
	ft_putstr_fd("Map:\n", fd);
	while(k < data.map.y)
	{
		l = 0;
		while (l < data.map.x)
		{
			ft_putchar_fd(data.map.g[k][l], fd);
			l++;
		}
		k++;
	}
//print piece size
	ft_putstr_fd("\nPiece Size\n", fd);
	ft_putstr_fd(ft_itoa(data.piece.y), fd);
	ft_putchar_fd(' ', fd);
	ft_putstr_fd(ft_itoa(data.piece.x), fd);
	ft_putchar_fd('\n', fd);
//print piece
	ft_putstr_fd("Piece:\n", fd);
	k = 0;
	while (k < data.piece.y)
	{
		l = 0;
		while (l < data.piece.x)
		{
			ft_putchar_fd(data.piece.g[k][l], fd);
			l++;
		}
		k++;
	}
//printing done
	close(fd);
	return (1);
}
