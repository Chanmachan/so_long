/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hommayunosuke <hommayunosuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:26:21 by hommayunosu       #+#    #+#             */
/*   Updated: 2022/09/22 13:26:22 by hommayunosu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	end_window(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->map_info->column)
	{
		free(info->map_info->map[i]);
		i++;
	}
	free(info->map_info->map);
	free(info->map_info);
	free(info->element_info);
	mlx_destroy_window(info->mlx_id, info->mlx_win_id);
	exit(EXIT_SUCCESS);
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

void	hook(t_info *info)
{
	mlx_loop_hook(info->mlx_id, run_player, info);
	mlx_hook(info->mlx_win_id, 2, 1L << 0, key_hook, info);
	mlx_hook(info->mlx_win_id, 17, 1L << 0, end_window, info);
	mlx_expose_hook(info->mlx_win_id, put_map, info);
}

int	valid_file_path(char *file_path)
{
	size_t	len;

	len = ft_strlen(file_path);
	if (ft_strncmp(file_path, "maps/", 5) == 0)
	{
		if (len < 10)
			exit_failure(2);
	}
	if (len < 5)
		exit_failure(2);
	if (ft_strncmp(file_path + len - 4, ".ber", 4))
		exit_failure(2);
	return (0);
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
	valid_file_path(argv[1]);
	load_map(&info, argv[1]);
	valid_map(&info);
	info.mlx_id = mlx_init();
	info.mlx_win_id = mlx_new_window(info.mlx_id, \
				info.map_info->row * 32, info.map_info->column * 32, "so_long");
	put_map(&info);
	hook(&info);
	mlx_loop(info.mlx_id);
	end_window(&info);
	return (0);
}
