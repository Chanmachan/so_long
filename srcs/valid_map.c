/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hommayunosuke <hommayunosuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:26:34 by hommayunosu       #+#    #+#             */
/*   Updated: 2022/09/22 13:26:35 by hommayunosu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	up_and_down_frame(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (info->map_info->map[i][j] != '\0')
	{
		if (info->map_info->map[i][j] != '1')
			exit_failure(0);
		j++;
	}
	j = 0;
	i = info->map_info->column - 1;
	while (info->map_info->map[i][j] != '\0')
	{
		if (info->map_info->map[i][j] != '1')
			exit_failure(0);
		j++;
	}
	return (0);
}

static int	side_frame(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < info->map_info->column - 1)
	{
		j = 0;
		while (j < info->map_info->row)
		{
			if (j == 0 || j == info->map_info->row - 1)
			{
				if (info->map_info->map[i][j] != '1')
					exit_failure(0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	compare_length(t_info *info)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(info->map_info->map[i]);
	while (i < info->map_info->column)
	{
		if (len != ft_strlen(info->map_info->map[i]))
			exit_failure(0);
		i++;
	}
	info->map_info->row = len;
	return (0);
}

int	valid_map(t_info *info)
{
	if (info->map_info->count_collect < 1 || \
		info->map_info->count_player != 1 || \
		info->map_info->count_exit != 1)
		exit_failure(0);
	compare_length(info);
	up_and_down_frame(info);
	side_frame(info);
	return (0);
}
