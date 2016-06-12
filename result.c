/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 09:56:19 by khansman          #+#    #+#             */
/*   Updated: 2016/06/12 09:57:43 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		give_result(t_coord best)
{
	ft_putstr_fd(ft_itoa(best.y), 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(ft_itoa(best.x), 1);
	ft_putstr_fd("\n", 1);
	return (1);
}
