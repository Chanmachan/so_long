#include "../includes/so_long.h"

/*void	get_put_image(t_info *info, char c, int x, int y)
{
	void	*mlx_img;
	int		img_width;
	int		img_height;

	if (c == '1')
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			WALL, &img_width, &img_height);
	else if (c == '0')
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			GROUND, &img_width, &img_height);
	else if (c == 'C')
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			COLLECT, &img_width, &img_height);
	else if (c == 'P')
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_FRONT_2, &img_width, &img_height);
	else if (c == 'E')
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			EXIT_CLOSE, &img_width, &img_height);
	else if (c == 'O')
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			EXIT_OPEN, &img_width, &img_height);
	mlx_put_image_to_window(info->mlx_id, info->mlx_win_id, \
						mlx_img, x * 32, y * 32);
	mlx_destroy_image(info->mlx_id, mlx_img);
}

void	display_map(t_info *info, char *str, int x, int y)
{
	if (*str == '1')
		get_put_image(info, *str, x, y);
	else if (*str == '0')
		get_put_image(info, *str, x, y);
	else if (*str == 'C')
		get_put_image(info, *str, x, y);
	else if (*str == 'P')
	{
		info->element_info->x_player = x;
		info->element_info->y_player = y;
		get_put_image(info, *str, x, y);
	}
	else if (*str == 'E')
	{
		info->element_info->x_exit = x;
		info->element_info->y_exit = y;
		get_put_image(info, *str, x, y);
	}
	else if (*str == 'O')
		get_put_image(info, *str, x, y);
}

void	put_map(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->map_info->column)
	{
		j = 0;
		while (j < info->map_info->row)
		{
			display_map(info, &info->map_info->map[i][j], j, i);
			j++;
		}
		i++;
	}
}*/

/*void	destroy_imgs(t_info *info)
{
	mlx_destroy_image(info->mlx_id, info->mlx_img->WALL_IMG);
	mlx_destroy_image(info->mlx_id, info->mlx_img->GROUND_IMG);
	mlx_destroy_image(info->mlx_id, info->mlx_img->COLLECT_IMG);
	mlx_destroy_image(info->mlx_id, info->mlx_img->EXIT_C_IMG);
	mlx_destroy_image(info->mlx_id, info->mlx_img->EXIT_O_IMG);
	mlx_destroy_image(info->mlx_id, info->mlx_img->P_B_1);
	mlx_destroy_image(info->mlx_id, info->mlx_img->P_B_2);
	mlx_destroy_image(info->mlx_id, info->mlx_img->P_B_3);
	mlx_destroy_image(info->mlx_id, info->mlx_img->P_F_1);
	mlx_destroy_image(info->mlx_id, info->mlx_img->P_F_2);
	mlx_destroy_image(info->mlx_id, info->mlx_img->P_F_3);
	mlx_destroy_image(info->mlx_id, info->mlx_img->P_L_1);
	mlx_destroy_image(info->mlx_id, info->mlx_img->P_L_2);
	mlx_destroy_image(info->mlx_id, info->mlx_img->P_L_3);
	mlx_destroy_image(info->mlx_id, info->mlx_img->P_B_1);
	mlx_destroy_image(info->mlx_id, info->mlx_img->P_R_1);
	mlx_destroy_image(info->mlx_id, info->mlx_img->P_R_2);
	mlx_destroy_image(info->mlx_id, info->mlx_img->P_R_3);
}*/

int	end_window(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->map_info->column)
	{
		free(info->map_info->map[i]);
		i++;
	}
//	destroy_imgs(info);
	free(info->map_info->map);
	free(info->map_info);
	free(info->element_info);
//	free(info->mlx_img);
	mlx_destroy_window(info->mlx_id, info->mlx_win_id);
	exit(EXIT_SUCCESS);
}

void	if_move_to_C(t_info *info, int x, int y)
{
	if (info->map_info->map[info->element_info->y_player + y] \
							[info->element_info->x_player] == 'C' || \
			info->map_info->map[info->element_info->y_player] \
								[info->element_info->x_player + x] == 'C')
		info->map_info->count_collect -= 1;
}

int	if_move_to_O(t_info *info, int x, int y)
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
	if_move_to_C(info, x, y);
	if (if_move_to_O(info, x, y))
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

int	key_hook(int keycode, t_info *info)
{
	if (keycode == ESC)
		end_window(info);
	else if (keycode == LEFT || keycode == 'a')
	{
		info->element_info->direction = LEFT;
		replace_player(info, -1, 0, P_LEFT_1);
	}
	else if (keycode == UP || keycode == 'w')
	{
		info->element_info->direction = UP;
		replace_player(info, 0, -1, P_BACK_1);
	}
	else if (keycode == RIGHT || keycode == 'd')
	{
		info->element_info->direction = RIGHT;
		replace_player(info, 1, 0, P_RIGHT_1);
	}
	else if (keycode == DOWN || keycode == 's')
	{
		info->element_info->direction = DOWN;
		replace_player(info, 0, 1, P_FRONT_1);
	}
	return (0);
}

void null_surplus(t_info *info)
{
	void	*mlx_img;
	int		img_width;
	int		img_height;

	if (info->element_info->direction == LEFT)
	{
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_LEFT_1, &img_width, &img_height);
	}
	if (info->element_info->direction == UP)
	{
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_BACK_1, &img_width, &img_height);
	}
	if (info->element_info->direction == RIGHT)
	{
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_RIGHT_1, &img_width, &img_height);
	}
	if (info->element_info->direction == DOWN)
	{
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_FRONT_1, &img_width, &img_height);
	}
	mlx_put_image_to_window(info->mlx_id, info->mlx_win_id, \
						mlx_img, info->element_info->x_player * 32, info->element_info->y_player * 32);
	mlx_destroy_image(info->mlx_id, mlx_img);
}

void eins_surplus(t_info *info)
{
	void	*mlx_img;
	int		img_width;
	int		img_height;

	if (info->element_info->direction == LEFT)
	{
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_LEFT_2, &img_width, &img_height);;;
	}
	if (info->element_info->direction == UP)
	{
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_BACK_2, &img_width, &img_height);
	}
	if (info->element_info->direction == RIGHT)
	{
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_RIGHT_2, &img_width, &img_height);
	}
	if (info->element_info->direction == DOWN)
	{
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_FRONT_2, &img_width, &img_height);
	}
	mlx_put_image_to_window(info->mlx_id, info->mlx_win_id, \
						mlx_img, info->element_info->x_player * 32, info->element_info->y_player * 32);
	mlx_destroy_image(info->mlx_id, mlx_img);
}

void zwei_surplus(t_info *info)
{
	void	*mlx_img;
	int		img_width;
	int		img_height;

	if (info->element_info->direction == LEFT)
	{
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_LEFT_3, &img_width, &img_height);
	}
	if (info->element_info->direction == UP)
	{
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_BACK_3, &img_width, &img_height);
	}
	if (info->element_info->direction == RIGHT)
	{
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_RIGHT_3, &img_width, &img_height);
	}
	if (info->element_info->direction == DOWN)
	{
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, \
			P_FRONT_3, &img_width, &img_height);
	}
	mlx_put_image_to_window(info->mlx_id, info->mlx_win_id, \
						mlx_img, info->element_info->x_player * 32, info->element_info->y_player * 32);
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

void	hook(t_info *info)
{
	mlx_loop_hook(info->mlx_id, run_player, info);
	mlx_hook(info->mlx_win_id, 2, 1L << 0, key_hook, info);
//	mlx_expose_hook(info->mlx_win_id, )
}

/*__attribute__((destructor))
static void destructor() {
	system("leaks -q so_long");
}*/

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		exit_failure(1);
	load_map(&info, argv[1]);
	valid_map(&info);
	info.mlx_id = mlx_init();
	info.mlx_win_id = mlx_new_window(info.mlx_id, \
				info.map_info->row * 32, info.map_info->column * 32, "so_long");
	put_map(&info);
//	mlx_loop_hook(info.mlx_id, run_player, &info);
	hook(&info);
	mlx_loop(info.mlx_id);
	//free処理
	mlx_destroy_window(info.mlx_id, info.mlx_win_id);
	free(info.map_info);
	free(info.element_info);
//	system("leaks -q so_long");
	return (0);
}
