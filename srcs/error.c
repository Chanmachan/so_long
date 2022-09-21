#include "../includes/so_long.h"

int	exit_failure(int num)
{
	if (num == 1)
		ft_putendl_fd("\tusage: ./so_long [file_path]", 1);
	else if (num == 2)
		ft_putendl_fd("Error: Invalid Filepath", 1);
	else
		ft_putendl_fd("Error: Invalid Map", 1);
	exit(EXIT_FAILURE);
}

int	give_error_msg(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}
