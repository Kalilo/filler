#include "libft/libft.h"

#include <sys/uio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int debugfd; //DEBUG GLOBAL VARIABLE

# define MAP_POS info->map.g[pos.y + counts.y][pos.x + counts.x]
# define MP1 (MAP_POS == 'o' || MAP_POS == 'O')
# define MP2 (MAP_POS == 'x' || MAP_POS == 'X')
# define PL1 info->player == 1
# define PL2 info->player == 2
# define MAP_FUL info->map.g[counts.y][counts.x] != '.'
# define MTH01 ft_abs(counts.y + pos.y - overlap.y)
# define MTH02 ft_abs(counts.x + pos.x - overlap.x)
# define MTH03 ft_abs(furthest.y + pos.y - overlap.y)
# define MTH04 ft_abs(furthest.x + pos.x - overlap.x)
# define MTH05 ft_abs(pos.y - counts.y)
# define MTH06 ft_abs(pos.x - counts.x)
# define PIE_FUL info->piece.g[counts.y][counts.x] == '*'
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
int			ft_on_map(t_data *info, t_coord pos);
t_coord		find_overlap(t_data *info, t_coord pos);
t_coord		find_furthest_point(t_data *info, t_coord pos, t_coord overlap);
t_coord		find_nearest_foe(t_data *info, t_coord pos);
/*basic_math.c*/
int			ft_abs(int num);
int			ft_is_foe(int player, char pos);
int			ft_sqrt(int	num);
int			ft_mean_pow(int a, int b);
int			ft_est_angle(t_coord a, t_coord b, t_coord c);
/*result.c*/
int			give_result(t_coord best);
/*ft_test_var.c*/
int     	write_map_data(t_data *data);//debug
