#include "filler.h"

int			main(void)
{	
	static t_data	gamedata;
	int		k;
	int		l;

	k = 1;
	debugfd = open("debugdump.txt", O_WRONLY); //DEBUGFD
	get_player(&gamedata);
	while (k)
	{
		//if(!(read_input(0, &gamedata)))
		//	return (0);
		l = 0;
		while (l > 0)
			l++;
		if (read_input(0, &gamedata))
		{
			write_map_data(&gamedata);
			k = scan_arr(&gamedata);
			reset_info(&gamedata);
		}
	}
	return (0);
}
