NAME = so_long

SRCS_DIR = ./srcs

OBJS_DIR = ./objs

SRCS_FILE = *.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))

LIBFT = ./LIBFT

INCLUDES = ./includes/so_long.h

OBJS = $(patsubst $(SRCS_DIR)/%, $(OBJS_DIR)/%, $(SRCS:.c=.o))

LIBFT_ARC = ./libft/libft.a
MLX_ARC = minilibx-linux/libmlx.a minilibx-linux/libmlx_Darwin.a

CFLAGS = -Wall -Werror -Wextra -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
#MP -MMD

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C $(LIBFT)
		$(CC) $(CFLAGS) $(MLX_ARC) $(LIBFT_ARC) $< -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
		mkdir -p $(OBJS_DIR)
		$(CC) $(CFLLAGS) -c $< -o $@

clean:
		$(RM) -r $(OBJS_DIR)
		$(MAKE) -C $(LIBFT) clean

fclean: clean
		$(MAKE) -C $(LIBFT) fclean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re