#include "../includes/so_long.h"

int	main(void)
{
//	size_t	i;
	char	*str;
	int		fd;

	fd = open("../maps/sample.ber", O_RDONLY);
	printf("%d\n", fd);
//	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
		if (str == NULL)
		{
			free(str);
			break;
		}
		free(str);
	}
	return (0);
}
