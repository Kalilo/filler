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

int		ft_sqrt(int	num)
{
	int	k;
	
	k = 1;
	while (k * k < num)
		k++;
	return (k - 1);
}

int		ft_mean_pow(int a, int b)
{
	return (ft_abs((a - b) / 2) * ((a - b) / 2));
}

int		ft_est_angle(t_coord a, t_coord b, t_coord c)
{
	int	dis_a;
	int	dis_b;
	int	dis_c;
	
	dis_a = ft_mean_pow(b.x, c.x) + ft_mean_pow(b.y, c.y);
	debug_mess("est angle a weight = ", dis_a);
	dis_b = ft_mean_pow(a.x, c.x) + ft_mean_pow(a.y, c.y);
	debug_mess("est angle b	weight = ", dis_b);
	dis_c = ft_mean_pow(a.x, b.x) + ft_mean_pow(a.y, b.y);
	debug_mess("est angle c weight = ", dis_c);
	
	if (dis_b <= dis_a + dis_c)
		return (2);
	else
		return (1);
}
