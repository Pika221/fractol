/*
	Julia and Mandelbrot
	Infinite zoom
	Able to take command line args to disipline
		which fractal render
	Able to take command line args to shape Julia, i.e x y coordinates
	ESC closes the process with no leaks
	Click on the X window, closes the process leaks free
*/

#include "fractol.h"

int main(int ac, char **av)
{
	t_fractol	fractol;


	if ((ac == 4 && !ft_strncmp(av[1], "julia", 5))
		|| (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)))
	{
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx);
		// Julia Mandelbrot
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, 1);
		exit(1);
	}
	return (0);
}