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

void	load_map()
{
	char	*str;
	int		fd;
	char	*line;
	char	*tmp;

	fd = open("maps/sample.ber", O_RDONLY);
	printf("fd = %d\n", fd);
	str = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			printf("here : %s", line);
			break ;
		}
		printf("line : %s", line);
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		free(line);
	}
	printf("str : %s", str);
	free(str);
}

__attribute__((destructor))
static void destructor() {
	system("leaks -q so_long");
}

int	main(void)
{
	char	**str;
//	size_t	row;//行(横)
//	size_t	column;//列(縦)

//	row = 0;
//	column = 0;
	load_map();
	return (0);
}
