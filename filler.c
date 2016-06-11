#include "filler.h"

int			main(void)
{	
	static t_data	gamedata;
	int		k;
	
	k = 1;
	debugfd = open("debugdump.txt", O_WRONLY); //DEBUGFD
	while (k > 0)
	{
		if(!(read_input(0, &gamedata)))
			return (0);
		write_map_data(&gamedata);
		k = scan_arr(&gamedata);
	}
	return (0);
}
