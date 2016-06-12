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
	int	k;

	k = 1;
	while (k * k < num)
		k++;
	return (k - 1);
}

int		ft_dist(t_coord a, t_coord b)
{
	return (ft_sqrt(((a.x - b.x) * (a.x - b.x)) +
		((a.y - b.y) * (a.y - b.y))));
}

int		ft_est_angle(t_coord a, t_coord b, t_coord c)
{
	int	dis_a;
	int	dis_b;
	int	dis_c;

	dis_a = ft_dist(b, c);
	dis_b = ft_dist(a, c);
	dis_c = ft_dist(a, b);
	if ((dis_b * dis_b) < (dis_a * dis_a) + (dis_c * dis_c))
		return (2);
	else
		return (1);
}
