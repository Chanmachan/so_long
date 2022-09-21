#ifndef SO_LONG_SO_LONG_H
# define SO_LONG_SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "../gnl/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"

//1
# define WALL "imgs/tiles/map_ground_rock.xpm"
//0
# define GROUND "imgs/tiles/map_ground.xpm"
//C
# define COLLECT "imgs/tiles/map_collect.xpm"
//E
# define EXIT_CLOSE "imgs/exit/map_exit_close.xpm"
# define EXIT_OPEN "imgs/exit/map_exit_open.xpm"
//P
# define P_BACK_1 "imgs/player/map_person_back_1.xpm"
# define P_BACK_2 "imgs/player/map_person_back_2.xpm"
# define P_BACK_3 "imgs/player/map_person_back_3.xpm"
# define P_FRONT_1 "imgs/player/map_person_front_1.xpm"
# define P_FRONT_2 "imgs/player/map_person_front_2.xpm"
# define P_FRONT_3 "imgs/player/map_person_front_3.xpm"
# define P_LEFT_1 "imgs/player/map_person_left_1.xpm"
# define P_LEFT_2 "imgs/player/map_person_left_2.xpm"
# define P_LEFT_3 "imgs/player/map_person_left_3.xpm"
# define P_RIGHT_1 "imgs/player/map_person_right_1.xpm"
# define P_RIGHT_2 "imgs/player/map_person_right_2.xpm"
# define P_RIGHT_3 "imgs/player/map_person_right_3.xpm"

//key_event

# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
typedef struct s_map_info
{
	int		count_collect;
	int		count_player;
	int		count_exit;
	char	**map;
	size_t	row;
	size_t	column;
}				t_map_info;

typedef struct s_element_info
{
	int		x_player;
	int		y_player;
	int		x_exit;
	int		y_exit;
}				t_element_info;

typedef struct s_info
{
	void			*mlx_id;
	void			*mlx_win_id;
	t_map_info		*map_info;
	t_element_info	*element_info;
	//	size_t
} 				t_info;

//error.c
int	exit_failure(int num);
int	give_error_msg(void);
//valid_map.c
int	up_and_down_frame(t_info *info);
int	side_frame(t_info *info);
int	compare_length(t_info *info);
int	valid_map(t_info *info);
//load_map.c
void	count_element(t_info *info, char *str);
char	*get_line(t_info *info, char *file_path);
int	valid_file_path(char *file_path);
void	load_map(t_info *info, char *file_path);
void	get_put_image(t_info *info, char c, int x, int y);
//init.c
void	init_info(t_info *info);
//put_map.c
void	display_map(t_info *info, char *str, int x, int y);
void	put_map(t_info *info);
int	end_window(t_info *info);
void	replace_player(t_info *info, int x, int y);
int	key_hook(int keycode, t_info *info);
void	hook(t_info *info);

#endif
