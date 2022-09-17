#ifndef SO_LONG_SO_LONG_H
# define SO_LONG_SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "../gnl/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_map_info
{
	char	**map;
	size_t	row;
	size_t	column;
}				t_map_info;

typedef struct s_info
{
	void		*mlx_id;
	void		*mlx_win_id;
	t_map_info	*map_info;
	//	size_t
} 				t_info;

#endif
