/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 09:57:07 by khansman          #+#    #+#             */
/*   Updated: 2016/06/12 15:43:19 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_abs(int num)
{
	if (num > 0)
		return (num);
	return (-num);
}

int		ft_is_foe(int player, char pos)
{
	if (player == 1 && (pos == 'x' || pos == 'X'))
		return (1);
	if (player == 2 && (pos == 'o' || pos == 'O'))
		return (1);
	if (!(player == 1 || player == 2))
		return (-1);
	return (0);
}

int		ft_sqrt(int num)
{
	int		k;

	k = 1;
	while (k * k < num)
		k++;
	return (k - 1);
}

float	ft_sqrtf(float num)
{
	float	a;
	float	b;
	int		k;

	a = 10;
	k = 0;
	while (k < 100)
	{
		b = a;
		a = a - (a * a - num) / (2 * a);
		if (b == a)
			break ;
		k++;
	}
	return (a);
}

float	ft_dist(t_coord a, t_coord b)
{
	return (ft_sqrtf(((a.x - b.x) * (a.x - b.x)) +
		((a.y - b.y) * (a.y - b.y))));
}

t_coord	ft_add_coord(t_coord a, t_coord b)
{
	t_coord	tmp;

	tmp.x = a.x + b.x;
	tmp.y = a.y + b.y;
	return (tmp);
}
