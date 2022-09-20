#include "../includes/so_long.h"

int	exit_failure(void)
{
	ft_putendl_fd("Invalid Map", 1);
	exit(EXIT_FAILURE);
}

int	give_error_msg(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

int	up_and_down_frame(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (info->map_info->map[i][j] != '\0')
	{
		if (info->map_info->map[i][j] != '1')
			exit_failure();
		j++;
	}
	j = 0;
	i = info->map_info->column - 1;
	while (info->map_info->map[i][j] != '\0')
	{
		if (info->map_info->map[i][j] != '1')
			exit_failure();
		j++;
	}
	return (0);
}

int	side_frame(t_info *info)
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
					exit_failure();
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	compare_length(t_info *info)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(info->map_info->map[i]);
	while (i < info->map_info->column)
	{
		if (len != ft_strlen(info->map_info->map[i]))
			exit_failure();
		i++;
	}
	info->map_info->row = len;
	return (0);
}

int	valid_map(t_info *info)
{
	compare_length(info);
	up_and_down_frame(info);
	side_frame(info);
	return (0);
}

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
}

void	count_element(t_info *info, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'C')
		{
			printf("hoge\n");
			info->map_info->count_collect += 1;
		}
		else if (str[i] == 'E')
			info->map_info->count_player += 1;
		else if (str[i] == 'P')
			info->map_info->count_exit += 1;
		i++;
	}
}

void	load_map(t_info *info)
{
	int		fd;
	char	*str;
	char	*line;
	char	*tmp;
	char	**ret;

	fd = open("maps/sample.ber", O_RDONLY);
	if (fd == -1)
		give_error_msg();
	init_info(info);
	str = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		free(line);
		info->map_info->column++;
	}
	count_element(info, str);
	ret = ft_split(str, '\n');
	info->map_info->map = ret;
	free(str);
}

void	get_put_image(t_info *info, char c, int x, int y)
{
	void	*mlx_img;
	int		img_width;
	int		img_height;

	if (c == '1')
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, WALL, &img_width, &img_height);
	else if (c == '0')
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, GROUND, &img_width, &img_height);
	else if (c == 'C')
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, COLLECT, &img_width, &img_height);
	else if (c == 'P')
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, P_FRONT_2, &img_width, &img_height);
	else if (c == 'E')
		mlx_img = mlx_xpm_file_to_image(info->mlx_id, EXIT_CLOSE, &img_width, &img_height);
	mlx_put_image_to_window(info->mlx_id, info->mlx_win_id, mlx_img, x * 32, y * 32);
	mlx_destroy_image(info->mlx_id, mlx_img);
}

void	display_map(t_info *info, char *str, int x, int y)
{
	if (*str == '1')
	{
		get_put_image(info, *str, x, y);
	}
	else if (*str == '0')
	{
		get_put_image(info, *str, x, y);
	}
	else if (*str == 'C')
	{
		get_put_image(info, *str, x, y);
	}
	else if (*str == 'P')
	{
		info->element_info->x_player = x;
		info->element_info->y_player = y;
		get_put_image(info, *str, x, y);
	}
	else if (*str == 'E')
	{
		info->element_info->x_player = x;
		info->element_info->y_player = y;
		get_put_image(info, *str, x, y);
	}
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
}

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

void	replace_player(t_info *info, int x, int y)
{
	if (info->map_info->map[info->element_info->y_player + y][info->element_info->x_player] == '1' || \
			info->map_info->map[info->element_info->y_player][info->element_info->x_player + x] == '1')
		return ;
	if (info->map_info->map[info->element_info->y_player + y][info->element_info->x_player] == 'C' || \
			info->map_info->map[info->element_info->y_player][info->element_info->x_player + x] == 'C')
	{
		info->map_info->count_collect -= 1;

	}
	if (info->map_info->count_collect == 0 && \
			info->map_info->map[info->element_info->y_player + y][info->element_info->x_player] == 'E' || \
			info->map_info->map[info->element_info->y_player][info->element_info->x_player + x] == 'E')
		end_window(info);
	else if (info->map_info->count_collect != 0 && \
			info->map_info->map[info->element_info->y_player + y][info->element_info->x_player] == 'E' || \
			info->map_info->map[info->element_info->y_player][info->element_info->x_player + x] == 'E')
		return ;
	info->map_info->map[info->element_info->y_player][info->element_info->x_player] = '0';
	info->element_info->x_player += x;
	info->element_info->y_player += y;
	info->map_info->map[info->element_info->y_player][info->element_info->x_player] = 'P';
	put_map(info);
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == ESC)
		end_window(info);
	else if (keycode == LEFT || keycode == 'a')
		replace_player(info, -1, 0);
	else if (keycode == UP || keycode == 'w')
		replace_player(info, 0, -1);
	else if (keycode == RIGHT || keycode == 'd')
		replace_player(info, 1, 0);
	else if (keycode == DOWN || keycode == 's')
		replace_player(info, 0, 1);
	return (0);
}

void	hook(t_info *info)
{
	mlx_hook(info->mlx_win_id, 2, 1L << 0, key_hook, info);
//	mlx_expose_hook(info->mlx_win_id, )
}

__attribute__((destructor))
static void destructor() {
	system("leaks -q so_long");
}

int	main(void)
{
//	size_t	column;//列(縦)
	t_info	info;

//	column = 0;
	load_map(&info);
	valid_map(&info);
	info.mlx_id = mlx_init();
	info.mlx_win_id = mlx_new_window(info.mlx_id, info.map_info->row * 32, info.map_info->column * 32, "so_long");
	put_map(&info);
	hook(&info);
	mlx_loop(info.mlx_id);
	//free処理
	mlx_destroy_window(info.mlx_id, info.mlx_win_id);
	free(info.map_info);
	free(info.element_info);
//	system("leaks -q so_long");
	return (0);
}
