#include "filler.h"

int			main(void)
{
	static t_data	gamedata;

	debugfd = open("debugdump.txt", O_WRONLY); //DEBUGFD
	if(!(read_input(0, &gamedata)))
				return (0);
	write_map_data(&gamedata);

}
