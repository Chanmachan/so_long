#include "../includes/so_long.h"

static void	if_move_to_c(t_info *info, int x, int y)
{
	if (info->map_info->map[info->element_info->y_player + y] \
							[info->element_info->x_player] == 'C' || \
			info->map_info->map[info->element_info->y_player] \
								[info->element_info->x_player + x] == 'C')
		info->map_info->count_collect -= 1;
}

static int	if_move_to_o(t_info *info, int x, int y)
{
	if (info->map_info-> \
			map[info->element_info->y_player + y] \
				[info->element_info->x_player] == 'O' || \
			info->map_info->map[info->element_info->y_player] \
								[info->element_info->x_player + x] == 'O')
		end_window(info);
	else if (info->map_info->count_collect != 0 && \
			info->map_info->map[info->element_info->y_player + y] \
								[info->element_info->x_player] == 'E' || \
			info->map_info-> \
				map[info->element_info->y_player] \
								[info->element_info->x_player + x] == 'E')
		return (1);
	return (0);
}

void	replace_player(t_info *info, int x, int y, char *img_path)
{
	if (info->map_info->count_collect == 0)
		info->map_info-> \
			map[info->element_info->y_exit] \
				[info->element_info->x_exit] = 'O';
	if (info->map_info-> \
			map[info->element_info->y_player + y] \
				[info->element_info->x_player] == '1' || \
			info->map_info-> \
				map[info->element_info->y_player] \
					[info->element_info->x_player + x] == '1')
		return ;
	if_move_to_c(info, x, y);
	if (if_move_to_o(info, x, y))
		return ;
	info->map_info-> \
		map[info->element_info->y_player] \
			[info->element_info->x_player] = '0';
	info->element_info->x_player += x;
	info->element_info->y_player += y;
	info->map_info-> \
		map[info->element_info->y_player] \
			[info->element_info->x_player] = 'P';
	info->img_path = img_path;
	put_map(info);
}