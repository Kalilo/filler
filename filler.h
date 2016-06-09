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

int     	write_map_data(t_data data);//debug
