#include "../includes/so_long.h"

static void	null_surplus(t_info *info)
{
	void	*mlx_img;
	int		img_width;
	int		img_height;

	if (info->element_info->direction == LEFT)
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_LEFT_1, &img_width, &img_height);
	if (info->element_info->direction == UP)
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_BACK_1, &img_width, &img_height);
	if (info->element_info->direction == RIGHT)
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_RIGHT_1, &img_width, &img_height);
	if (info->element_info->direction == DOWN)
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_FRONT_1, &img_width, &img_height);
	mlx_put_image_to_window(info->mlx_id, info->mlx_win_id, \
						mlx_img, info->element_info->x_player * 32, \
								info->element_info->y_player * 32);
	mlx_destroy_image(info->mlx_id, mlx_img);
}

static void	eins_surplus(t_info *info)
{
	void	*mlx_img;
	int		img_width;
	int		img_height;

	if (info->element_info->direction == LEFT)
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_LEFT_2, &img_width, &img_height);
	if (info->element_info->direction == UP)
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_BACK_2, &img_width, &img_height);
	if (info->element_info->direction == RIGHT)
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_RIGHT_2, &img_width, &img_height);
	if (info->element_info->direction == DOWN)
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_FRONT_2, &img_width, &img_height);
	mlx_put_image_to_window(info->mlx_id, info->mlx_win_id, \
						mlx_img, info->element_info->x_player * 32, \
								info->element_info->y_player * 32);
	mlx_destroy_image(info->mlx_id, mlx_img);
}

static void	zwei_surplus(t_info *info)
{
	void	*mlx_img;
	int		img_width;
	int		img_height;

	if (info->element_info->direction == LEFT)
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_LEFT_3, &img_width, &img_height);
	if (info->element_info->direction == UP)
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_BACK_3, &img_width, &img_height);
	if (info->element_info->direction == RIGHT)
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_RIGHT_3, &img_width, &img_height);
	if (info->element_info->direction == DOWN)
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_FRONT_3, &img_width, &img_height);
	mlx_put_image_to_window(info->mlx_id, info->mlx_win_id, \
						mlx_img, info->element_info->x_player * 32, \
								info->element_info->y_player * 32);
	mlx_destroy_image(info->mlx_id, mlx_img);
}

int	run_player(t_info *info)
{
	if (info->func_count % 25000 == 0)
		eins_surplus(info);
	else if (info->func_count % 50000 == 1)
		null_surplus(info);
	else if (info->func_count % 100000 == 2)
		zwei_surplus(info);
	info->func_count++;
	if (info->func_count > 200000)
		info->func_count = 0;
	return (0);
}
