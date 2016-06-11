#include "libft/libft.h"

#include <sys/uio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h> //DEBUG - REMOVE BEFORE SUBMIT

int debugfd; //DEBUG GLOBAL VARIABLE

# define MAP_POS info->map.g[pos.y + counts.y][pos.x + counts.x]
# define M_POS00 info->map.g[counts.y][counts.x]
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
# define NE_FOE find_nearest_foe(info, overlap)

typedef struct		s_grid
{
	char		**g;
	int			y;
	int			x;
}					t_grid;

typedef struct		s_data
{
	int			player;
	t_grid		map;
	t_grid		piece;
}					t_data;

typedef struct		s_coord
{
	int			x;
	int			y;
}					t_coord;

/**Functions Needed**
 * free 2D array
 *
 **Todo**
 * shorten test_point function in scan_arr.c
 */


/*read.c*/
int         read_input(int fd, t_data *map);
int			get_player(t_data *info);
/*store_arr.c*/
int			store_arr(t_grid *grid, char *line, int cur_line);
int			ft_malloc_arr(t_grid *grid);
/*scan_arr.c*/
int			test_point(t_data *info, t_coord pos, int *best_weight, t_coord *best);
int			scan_arr(t_data *info);
/*weight.c*/
int			scan_imm_foe(t_data *info, t_coord pos);
int			weight_option(t_data *info, t_coord pos, int *best_weight, t_coord *best);
/*seek.c*/
int			ft_on_map(t_data *info, int y, int x);
int			ft_on_piece(t_data *info, int y, int x);
t_coord		find_overlap(t_data *info, t_coord pos);
t_coord		find_furthest_point(t_data *info, t_coord pos, t_coord overlap);
t_coord		find_nearest_foe(t_data *info, t_coord pos);
/*basic_math.c*/
int			ft_abs(int num);
int			ft_is_foe(int player, char pos);
int			ft_sqrt(int	num);
int			ft_dist(t_coord a, t_coord b);
int			ft_est_angle(t_coord a, t_coord b, t_coord c);
/*result.c*/
int			give_result(t_coord best);
/*free_arr.c*/
int	free_g(char ***arr, int rows);
int free_s(char ***arr);
int reset_info(t_data *info);
/*ft_test_var.c*/
int     	write_map_data(t_data *data);//debug
void		debug_mess(char *str, int nbr);
int			mock_read(void);
