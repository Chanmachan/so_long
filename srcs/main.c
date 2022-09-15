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

int	up_and_down_frame(char **str, t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i][j] != '\0')
	{
		if (str[i][j] != '1')
			exit_failure();
		j++;
	}
	j = 0;
	i = info->column - 1;
	while (str[i][j] != '\0')
	{
		if (str[i][j] != '1')
			exit_failure();
		j++;
	}
	return (0);
}

int	side_frame(char **str, t_info *info)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < info->column - 1)
	{
		j = 0;
		while (j < info->row)
		{
			if (j == 0 || j == info->row - 1)
			{
				if (str[i][j] != '1')
					exit_failure();
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	compare_length(char **str, t_info *info)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str[i]);
	while (i < info->column)
	{
		if (len != ft_strlen(str[i]))
			exit_failure();
		i++;
	}
	info->row = len;
	return (0);
}

int	valid_map(char **str, t_info *info)
{
	compare_length(str, info);
	up_and_down_frame(str, info);
	side_frame(str, info);
	return (0);
}

void	init_info(t_info *info)
{
	info->row = 0;
	info->column = 0;
	info->map = NULL;
}

char	**load_map(t_info *info)
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
		info->column++;
	}
	ret = ft_split(str, '\n');
	info->map = ret;
	printf("strlen : %zu\n", ft_strlen(str));
	free(str);
	return (ret);
}

/*__attribute__((destructor))
static void destructor() {
	system("leaks -q so_long");
}*/

int	main(void)
{
	char	**str;
	size_t	row;//行(横)
//	size_t	column;//列(縦)
	t_info	info;
	void	*mlx_id;
	void	*mlx_win_id;

	row = 0;
//	column = 0;
	str = load_map(&info);
	valid_map(str, &info);
	mlx_id = mlx_init();
	mlx_win_id = mlx_new_window(mlx_id, info.row * 35, info.column * 35, "test");
	mlx_loop(mlx_id);
	//free処理
	while (1)
	{
		if (str[row] == NULL)
		{
			free(str[row]);
			break ;
		}
		free(str[row]);
		row++;
	}
	free(str);
//	system("leaks -q so_long");
	return (0);
}
