/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hommayunosuke <hommayunosuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:26:24 by hommayunosu       #+#    #+#             */
/*   Updated: 2022/09/22 13:26:25 by hommayunosu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_put_image(t_info *info, char c, int x, int y)
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
			info->img_path, &img_width, &img_height);
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

static void	display_map(t_info *info, char *str, int x, int y)
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

int	put_map(t_info *info)
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
	return (0);
}
