/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 09:59:45 by khansman          #+#    #+#             */
/*   Updated: 2016/06/12 14:23:07 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KHANSMAN_FILLER_H
# define KHANSMAN_FILLER_H

# include "libft/libft.h"

# include <sys/uio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>

# define MAP_POS info->map.g[pos.y + counts.y][pos.x + counts.x]
# define M_POS00 info->map.g[counts.y][counts.x]
# define M_POS01 info->map.g[pos.y - 1][pos.x - 1 + counts.x]
# define PL1 info->player == 1
# define PL2 info->player == 2
# define MAP_FUL info->map.g[counts.y][counts.x] != '.'
# define ON_MAP ft_on_map(info, counts.y, counts.x)
# define ON_MAP01 ft_on_map(info, pos.y + counts.y, pos.x + counts.x)
# define ON_MAP02 ft_on_map(info, pos.y, pos.x)
# define ON_MAP03 ft_on_map(info, pos.y - 1, pos.x - 1 + counts.x)
# define MTH01 ft_dist(temp, overlap)
# define MTH02 ft_dist(temp, furthest)
# define MTH03 ft_dist(pos, counts)
# define MTH04 ft_dist(pos, nearest)
# define PIE_FUL info->piece.g[counts.y][counts.x] == '*'
# define PIE_POS info->piece.g[counts.y - pos.y][counts.x - pos.x]
# define ON_PIE ft_on_piece(info, counts.y - pos.y, counts.x - pos.x)
# define ON_PIE2 ft_on_piece(info, counts.y, counts.x)
# define NE_FOE find_nearest_foe(info, FUR_01)
# define NE_FOE2 find_nearest_foe(info, *best)
# define CLOSER (ft_dist(NE_FOE, pos) < ft_dist(*best, NE_FOE2))
# define FUR_01 find_furthest_point(info, pos, overlap)

# define QUIT_CON01 if (!(ON_MAP01)) return (0)
# define ONE_POINT found = 1; else return (0)
# define OLAP_CON !(found) && !(ft_is_foe(info->player, MAP_POS))
# define N_NUL_CON ON_MAP01 && MAP_POS != '.'
# define EXIT_CON if (N_NUL_CON) { if (OLAP_CON) ONE_POINT; }

# define ON_MA00 ft_on_map(info, pos.y - 1, pos.x)
# define ON_MA01 ft_on_map(info, pos.y + 1, pos.x)
# define ON_MA02 ft_on_map(info, pos.y, pos.x - 1)
# define ON_MA03 ft_on_map(info, pos.y, pos.x + 1)
# define ON_MA04 ft_on_map(info, pos.y - 1, pos.x - 1)
# define ON_MA05 ft_on_map(info, pos.y - 1, pos.x + 1)
# define ON_MA06 ft_on_map(info, pos.y + 1, pos.x - 1)
# define ON_MA07 ft_on_map(info, pos.y + 1, pos.x + 1)

typedef struct	s_grid
{
	char		**g;
	int			y;
	int			x;
}				t_grid;

typedef struct	s_data
{
	int			player;
	t_grid		map;
	t_grid		piece;
}				t_data;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

int				read_input(int fd, t_data *map);
int				get_player(t_data *info);
int				store_arr(t_grid *grid, char *line, int cur_line);
int				ft_malloc_arr(t_grid *grid);
int				test_point(t_data *info, t_coord pos, int *best_weight, \
					t_coord *best);
int				scan_arr(t_data *info);
int				scan_imm_foe(t_data *info, t_coord pos);
int				weight_option(t_data *info, t_coord pos, int *best_weight, \
					t_coord *best);
int				ft_on_map(t_data *info, int y, int x);
int				ft_on_piece(t_data *info, int y, int x);
t_coord			find_overlap(t_data *info, t_coord pos);
t_coord			find_furthest_point(t_data *info, t_coord pos, t_coord overlap);
t_coord			find_nearest_foe(t_data *info, t_coord pos);
int				ft_abs(int num);
int				ft_is_foe(int player, char pos);
int				ft_sqrt(int	num);
int				ft_dist(t_coord a, t_coord b);
int				ft_est_angle(t_coord a, t_coord b, t_coord c);
int				give_result(t_coord best);
int				free_g(char ***arr, int rows);
int				free_s(char ***arr);
int				reset_info(t_data *info);

#endif
