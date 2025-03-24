NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
HEADER = -Iheader -Iminilibx
MLX = ./minilibx/libmlx.a
SRCS = controllers.c init.c main.c render.c utils.c
OBJS = $(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -L minilibx -lmlx -lX11 -lm -lXext -o $(NAME)
	@echo "Fractol compiled!"

clean:
	@$(RM) $(OBJS)
	@echo "Fractol cleaned!"

minilibx:
	@git clone -s https://github.com/42Paris/minilibx-linux.git ./minilibx > /dev/null 2>&1
	@make -C minilibx > /dev/null 2>&1
	@echo "Minilibx installed!"

fclean: clean
	@$(RM) $(NAME) > /dev/null 2>&1

uninstall:
	@$(RM) ./minilibx > /dev/null 2>&1
	@echo "Minilibx uninstalled!"

re: fclean all

.PHONY: all clean fclean re minilibx