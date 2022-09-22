/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hommayunosuke <hommayunosuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:34:16 by hommayunosu       #+#    #+#             */
/*   Updated: 2022/09/22 13:34:17 by hommayunosu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

//run_player
# define MIDDLE_LEG 25000
# define LEFT_LEG_UP 50000
# define RIGHT_LEG_UP 100000
# define RESET_COUNT 200000

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
	int		direction;
	int		x_player;
	int		y_player;
	int		x_exit;
	int		y_exit;
}				t_element_info;

typedef struct s_info
{
	void			*mlx_id;
	void			*mlx_win_id;
	char			*img_path;
	size_t			pedometer;
	size_t			func_count;
	t_map_info		*map_info;
	t_element_info	*element_info;
}				t_info;

//error.c
int		exit_failure(int num);
int		give_error_msg(void);
//valid_map.c
int		check_invalid_char(char *str);
int		valid_map(t_info *info);
//load_map.c
void	load_map(t_info *info, char *file_path);
//init.c
void	init_info(t_info *info);
//put_map.c
int		put_map(t_info *info);
//run_player.c
int		run_player(t_info *info);
//replace_player.c
void	replace_player(t_info *info, int x, int y, char *img_path);

int		end_window(t_info *info);
int		key_hook(int keycode, t_info *info);
void	hook(t_info *info);

#endif
