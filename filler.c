#include "filler.h"

int			main(void)
{
	t_data	gamedata;

	if(!(read_input(0, &gamedata)))
				return (0);
	write_map_data(gamedata);

}
