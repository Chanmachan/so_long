#include "../includes/so_long.h"

//int	valid_map()

/*void	load_map()
{
	char	**str;
	int 	fd;
	char	**tmp;
	size_t	i;

	fd = open("maps/sample.ber", O_RDONLY);
	i = 0;
	while (1)
	{
		str = (char **) malloc(sizeof(char) * 1);
		if (str == NULL)
			exit(EXIT_FAILURE);
		if (i++ == 0)
			tmp = str;
		*str = get_next_line(fd);
		printf("%s", *str);
		if (*str == NULL)
		{
			break;
		}
		str++;
	}
	close(fd);
}*/

char	**load_map()
{
	char	*str;
	int		fd;
	char	*line;
	char	*tmp;
	char	**ret;

	fd = open("maps/sample.ber", O_RDONLY);
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

	row = 0;
//	column = 0;
	str = load_map();
	while (1)
	{
		printf("str : %s\n", str[row]);
		if (str[row] == NULL)
		{
			free(str[row]);
			break;
		}
		free(str[row]);
		row++;
	}
	free(str);
	return (0);
}
