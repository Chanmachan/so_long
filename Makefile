NAME = so_long

SRCS_DIR = ./srcs

OBJS_DIR = ./objs

SRCS_FILE = main.c load_map.c error.c init.c put_map.c valid_map.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))

LIBFT = ./libft
GNL = ./gnl

INCLUDES = ./includes/so_long.h

OBJS = $(patsubst $(SRCS_DIR)/%, $(OBJS_DIR)/%, $(SRCS:.c=.o))

LIBFT_ARC = ./libft/libft.a
GNL_ARC = ./gnl/gnl.a
MLX_ARC = ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Darwin.a

CFLAGS = -Wall -Werror -Wextra -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit -fsanitize=address
#MP -MMD

all: $(NAME)

test: $(OBJS)
		$(MAKE) -C $(LIBFT)
		$(MAKE) -C $(GNL)
		$(CC) $(CFLAGS) $(LIBFT_ARC) $(GNL_ARC) $<

$(NAME): $(OBJS)
		$(MAKE) -C $(LIBFT)
		$(MAKE) -C $(GNL)
		$(CC) $(CFLAGS) $(MLX_ARC) $(LIBFT_ARC) $(GNL_ARC) $^ -o $(NAME)
#$(CC) $(CFLAGS) $(GNL_ARC) $(MLX_ARC) $(LIBFT_ARC) $< -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
		mkdir -p $(OBJS_DIR)
		$(CC) $(CFLLAGS) -c $< -o $@

clean:
		$(RM) -r $(OBJS_DIR)
		$(MAKE) -C $(LIBFT) clean
		$(MAKE) -C $(GNL) clean

fclean: clean
		$(MAKE) -C $(LIBFT) fclean
		$(MAKE) -C $(GNL) fclean
		$(RM) $(NAME)

ctest: clean
		$(MAKE) -C $(LIBFT) fclean
		$(MAKE) -C $(GNL) fclean
		$(RM) a.out

re: fclean all

.PHONY: all clean fclean re