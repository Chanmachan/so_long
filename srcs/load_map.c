#include "../includes/so_long.h"

void	count_element(t_info *info, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'C')
			info->map_info->count_collect += 1;
		else if (str[i] == 'E')
			info->map_info->count_player += 1;
		else if (str[i] == 'P')
			info->map_info->count_exit += 1;
		i++;
	}
}

char	*get_line(t_info *info, char *file_path)
{
	int		fd;
	char	*str;
	char	*line;
	char	*tmp;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		give_error_msg();
	str = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] != '1')
			exit_failure(0);
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		free(line);
		info->map_info->column++;
	}
	return (str);
}

void	load_map(t_info *info, char *file_path)
{
	char	*str;
	char	**ret;

	init_info(info);
	str = get_line(info, file_path);
	count_element(info, str);
	ret = ft_split(str, '\n');
	info->map_info->map = ret;
	free(str);
}
