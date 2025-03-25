NAME = fractol
NAME_BONUS = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
HEADER = -Iheader -Iminilibx
MLX = ./LIB/minilibx/libmlx.a
SRCS = SRCS/controllers.c SRCS/fractol.c SRCS/init.c SRCS/render.c SRCS/utils.c
BNS_SRCS = BNS/controllers_bonus.c BNS/fractol_bonus.c BNS/init_bonus.c  BNS/render_bonus.c BNS/utils_bonus.c
OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS_SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -L LIB/minilibx -lmlx -lX11 -lm -lXext -o $(NAME)
	@echo "Fractol compiled!"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BNS_OBJS)
	@$(CC) $(CFLAGS) $(BNS_OBJS) $(MLX) -L LIB/minilibx -lmlx -lX11 -lm -lXext -o $(NAME_BONUS)
	@echo "Fractol Bonus compiled!"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(BNS_OBJS)
	@echo "Fractol cleaned!"

install:
	@git clone -s https://github.com/42Paris/minilibx-linux.git ./LIB/minilibx > /dev/null 2>&1
	@make -C ./LIB/minilibx > /dev/null 2>&1
	@echo "Minilibx installed!"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS) > /dev/null 2>&1

uninstall:
	@$(RM) ./LIB/minilibx > /dev/null 2>&1
	@echo "Minilibx uninstalled!"

re: fclean all

.PHONY: all clean fclean re install