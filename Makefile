NAME = so_long

SRCS_DIR = ./srcs

OBJS_DIR = ./objs

SRCS_FILE = *.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))

LIBFT = ./LIBFT

INCLUDES = so_long.h

OBJS = $(patsubst $(SRCS_DIR)/%, $(OBJS_DIR)/%, $(SRCS:=.c=.o))

LIBFT_ARC = ./libft/libft.a

CFLAGS = -Wall -Werror -Wextra
#MP -MMD

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C $(LIBFT)
		$(CC) $(CFLAGS) $(LIBFT_ARC) $< -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
		mkdir -p $(OBJS_DIR)
		$(CC) $(CFLLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS_DIR)
		$(MAKE) -C $(LIBFT) clean

fclean: clean
		$(MAKE) -C $(LIBFT) fclean
		$(RM) $(NAME)
