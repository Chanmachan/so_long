#ifndef SO_LONG_SO_LONG_H
# define SO_LONG_SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "../gnl/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_info
{
	size_t	row;
	size_t	column;
	char	**map;
//	size_t
} 				t_info;

#endif
