/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 13:41:25 by khansman          #+#    #+#             */
/*   Updated: 2016/06/11 13:44:20 by ghavenga         ###   ########.fr       */
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

int		write_map_data(t_data *data)
{
	int			k;
	int			l;

	k = 0;
	while(k < data->map.y)
	{
		l = 0;
		while (l < data->map.x)
		{
			l++;
		}
		k++;
	}
	k = 0;
	while (k < data->piece.y)
	{
		l = 0;
		while (l < data->piece.x)
		{
			l++;
		}
		k++;
	}

	return (1);
}
