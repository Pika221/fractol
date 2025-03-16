NAME = fractol

all:
	@gcc *.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o fractol

clean:
	@rm -f *.o

fclean: clean
	@rm -f fractol

re: fclean all

.PHONY: all clean fclean re