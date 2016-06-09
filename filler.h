#include "libft/libft.h"

#include <sys/uio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int debugfd; //DEBUG GLOBAL VARIABLE

# define MAP_POS info->map.g[pos->y + counts.y][pos->x + counts.x]

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
 * weight piece
 *
 **Todo**
 * shorten test_point function in scan_arr.c
 */

int         read_input(int fd, t_data *map);
int			store_arr(t_grid *grid, char *line, int cur_line);
int			ft_malloc_arr(t_grid *grid);

int     	write_map_data(t_data data);//debug
