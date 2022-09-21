#include "../includes/so_long.h"

/*void	*init_player(t_info *info)

void	init_mlx_img(t_info *info)
{
	int		img_width;
	int		img_height;

	info->mlx_img = (t_mlx_img *) malloc(sizeof(t_mlx_img));
	if (info->mlx_img == NULL)
		give_error_msg();
	*P_B_1 = mlx_xpm_file_to_image(info->mlx_id, P_BACK_1, &img_width, &img_height);
	*P_B_2 = mlx_xpm_file_to_image(info->mlx_id, P_BACK_2, &img_width, &img_height);
	*P_B_3 = mlx_xpm_file_to_image(info->mlx_id, P_BACK_3, &img_width, &img_height);
	*P_F_1 = mlx_xpm_file_to_image(info->mlx_id, P_FRONT_1, &img_width, &img_height);
	*P_F_2 = mlx_xpm_file_to_image(info->mlx_id, P_FRONT_2, &img_width, &img_height);
	*P_F_3 = mlx_xpm_file_to_image(info->mlx_id, P_FRONT_3, &img_width, &img_height);
	*P_L_1 = mlx_xpm_file_to_image(info->mlx_id, P_LEFT_1, &img_width, &img_height);
	*P_L_2 = mlx_xpm_file_to_image(info->mlx_id, P_LEFT_2, &img_width, &img_height);
	*P_L_3 = mlx_xpm_file_to_image(info->mlx_id, P_LEFT_3, &img_width, &img_height);
	*P_R_1 = mlx_xpm_file_to_image(info->mlx_id, P_RIGHT_1, &img_width, &img_height);
	*P_R_2 = mlx_xpm_file_to_image(info->mlx_id, P_RIGHT_2, &img_width, &img_height);
	*P_R_3 = mlx_xpm_file_to_image(info->mlx_id, P_RIGHT_3, &img_width, &img_height);
}

void	init_info(t_info *info)
{
	info->mlx_id = NULL;
	info->mlx_win_id = NULL;
	info->img_path = P_FRONT_2;
	info->func_count = 0;
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
	info->element_info->direction = DOWN;
	info->element_info->x_player = 0;
	info->element_info->y_player = 0;
	info->element_info->x_exit = 0;
	info->element_info->y_exit = 0;
	init_mlx_img(info);
}*/

void	init_info(t_info *info)
{
	info->mlx_id = NULL;
	info->mlx_win_id = NULL;
	info->img_path = P_FRONT_2;
	info->func_count = 0;
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
	info->element_info->direction = DOWN;
	info->element_info->x_player = 0;
	info->element_info->y_player = 0;
	info->element_info->x_exit = 0;
	info->element_info->y_exit = 0;
}
