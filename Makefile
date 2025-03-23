NAME = fractol

all:
	@gcc *.c -Lminilibx -lmlx -lX11 -lXext -o fractol

clean:
	@rm -f *.o

fclean: clean
	@rm -f fractol

re: fclean all

.PHONY: all clean fclean re