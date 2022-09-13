#include "../includes/so_long.h"

//int	valid_map()

void	load_map()
{
	char	**str;
	int 	fd;
	char	**tmp;
	char	*tmp2;

	fd = open("maps/sample.ber", O_RDONLY);
	tmp = str;
	while (1)
	{
		str = (char **) malloc(sizeof(char) * 1);
		if (str == NULL)
			exit(EXIT_FAILURE);
		*str = get_next_line(fd);
		printf("%s", *str);
		tmp2 = *str;
		tmp = str;
		if (*str == NULL)
		{
			free(tmp);
			break;
		}
		str++;
		free(tmp2);
		free(tmp);
	}
	close(fd);
}

int	main(void)
{
//	size_t	i;
//	size_t	row;//行(横)
//	size_t	column;//列(縦)

//	row = 0;
//	column = 0;
	load_map();
	system("leaks -q so_long");
	return (0);
}
