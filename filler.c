#include "filler.h"

int			main(void)
{	
	static t_data	gamedata;
	int		k;
	
	k = 1;
	debugfd = open("debugdump.txt", O_WRONLY); //DEBUGFD
	get_player(&gamedata);
	while (k)
	{
		//if(!(read_input(0, &gamedata)))
		//	return (0);
		sleep(1);
		if (read_input(0, &gamedata))
		{
			write_map_data(&gamedata);
			k = scan_arr(&gamedata);
			reset_info(&gamedata);
		}
	}
	return (0);
}
