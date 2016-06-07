#include "filler.h"

int			main(void)
{
	t_data	gamedata;

	debugfd = open("debugdump.txt", O_APPEND | O_WRONLY); //DEBUGFD
	if(!(read_input(0, &gamedata)))
				return (0);
	write_map_data(gamedata);

}
