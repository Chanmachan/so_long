#include "../includes/so_long.h"

void	init_info(t_info *info)
{
	info->mlx_id = NULL;
	info->mlx_win_id = NULL;
	info->map_info = (t_map_info *) malloc(sizeof(t_map_info));
	if (info->map_info == NULL)
		give_error_msg();
	info->map_info->count_collect = 0;
	info->map_info->count_player = 0;
	info->map_info->count_exit = 0;
	info->map_info->map = NULL;
	info->map_info->row = 0;
	info->map_info->column = 0;
	info->element_info = (t_element_info *) malloc(sizeof(t_element_info));
	if (info->element_info == NULL)
		give_error_msg();
	info->element_info->x_player = 0;
	info->element_info->y_player = 0;
	info->element_info->x_exit = 0;
	info->element_info->y_exit = 0;
}
