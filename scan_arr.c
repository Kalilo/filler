int		test_point(t_data *info, t_coord pos, t_coord *best)
{
	t_coord		counts;
	
	counts.y = 0;
	while (counts.y < info->piece.y)
	{
		counts.x = 0;
		while (counts.x < info->piece.x)
		{
			if (info->piece.g[counts.y][counts.x] != '.')
			{
				//functionality, with weighting algorithm called.
			}
			counts.x++;
		}
		counts.y++;
	}
	if (counts.y == info->piece.y && counts.x == info->piece.x)
		
	return (1);
}

int		scan_arr(t_data info)
{
	t_coord		best;
	t_coord		counts;
	
	counts.y = 1 - info.piece.y;
	while (counts.y < info.piece.y + info.map.y - 1)
	{
		counts.x = 1 - info.piece.x;
		while (counts.x < info.piece.x + info.map.x -1)
		{
			test_point(&info, counts, &best);
			counts.x++;
		}
		counts.y++;
	}	
}