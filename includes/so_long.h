#ifndef SO_LONG_SO_LONG_H
# define SO_LONG_SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "../gnl/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"

# define EXIT_CLOSE "imgs/exit/map_exit_close.xpm"
# define EXIT_OPEN "imgs/exit/map_exit_open.xpm"
# define P_BACK_1 "imgs/player/map_person_back_1.xpm"
# define P_BACK_2 "imgs/player/map_person_back_2.xpm"
# define P_BACK_3 "imgs/player/map_person_back_3.xpm"
# define P_FRONT_1 "imgs/player/map_person_front_1.xpm"
# define P_FRONT_2 = "imgs/player/map_person_front_2.xpm"
# define P_FRONT_3 = "imgs/player/map_person_front_3.xpm"
# define P_LEFT_1 "imgs/player/map_person_left_1.xpm"
# define P_LEFT_2 "imgs/player/map_person_left_2.xpm"
# define P_LEFT_3 "imgs/player/map_person_left_3.xpm"
# define P_RIGHT_1 "imgs/player/map_person_right_1.xpm"
# define P_RIGHT_2 "imgs/player/map_person_right_2.xpm"
# define P_RIGHT_3 "imgs/player/map_person_right_3.xpm"

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
