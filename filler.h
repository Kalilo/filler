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
# define MTH01 ft_abs(count.y + pos.y - overlap.y)
# define MTH02 ft_abs(count.x + pos.x - overlap.x)
# define MTH03 ft_abs(furthest.y + pos.y - overlap.y)
# define MTH04 ft_abs(furthest.x + pos.x - overlap.x)

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
 * weight_option(PROTOTYPED) -
 * give_result
 *
 **Todo**
 * shorten test_point function in scan_arr.c
 */

int         read_input(int fd, t_data *map);
int			store_arr(t_grid *grid, char *line, int cur_line);
int			ft_malloc_arr(t_grid *grid);

int			scan_arr(t_data info);
int			test_point(t_data *info, t_coord pos, int *best_weight);

int			weight_option(t_data *info, t_coord pos, int *best_weight);

t_coord		find_overlap(t_data *info, t_coord pos);
t_coord		find_furthest(t_data *info, t_coord pos, t_coord overlap);
t_coord		find_nearest_foe(t_data *info, t_coord pos);

int			ft_abs(int num);

int     	write_map_data(t_data data);//debug
