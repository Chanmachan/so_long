#include "../includes/so_long.h"

int	exit_failure()
{
	ft_putendl_fd("Invalid map", 1);
	exit(EXIT_FAILURE);
}

int	give_error_msg()
{
	perror("Error");
	exit(EXIT_FAILURE);
}

int	compare_length(char **str, t_info *info)
{
	size_t	row;
	size_t	len;

	row = 0;
	len = ft_strlen(str[row]);
	while (row < info->array)
	{
		if (len != ft_strlen(str[row]))
			exit_failure();
		row++;
	}
	return (0);
}

int	valid_map(char **str, t_info *info)
{
	size_t	row;
	size_t	column;
	size_t	*len;
	size_t	index;

	row = 0;
	column = 0;
	index = 0;
	compare_length(str, info);
	while (str[row][column] != '\0')
	{
		if (str[row][column] != '1')
			exit_failure();
		column++;
	}
	return (0);
}

void	init_info(t_info *info)
{
	info->len = NULL;
	info->array = 0;
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
		info->array++;
	}
	ret = ft_split(str, '\n');
	free(str);
	return (ret);
}

__attribute__((destructor))
static void destructor() {
	system("leaks -q so_long");
}

int	main(void)
{
	char	**str;
	size_t	row;//行(横)
//	size_t	column;//列(縦)
	t_info	info;

	row = 0;
//	column = 0;
	str = load_map(&info);
	valid_map(str, &info);
	while (1)
	{
		if (str[row] == NULL)
		{
			free(str[row]);
			break;
		}
		free(str[row]);
		row++;
	}
	free(str);
//	system("leaks -q so_long");
	return (0);
}
