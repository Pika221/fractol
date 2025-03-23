#include "fractol.h"

static int	check_args(int ac, char **av)
{
	if (ac != 2 && ac != 4)
		return (0);
	if ((ac == 2 && ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && ft_strncmp(av[1], "julia", 5)))
		return (0);
	if (ac == 4 && (!ft_is_double(av[2]) || !ft_is_double(av[3])))
	{
		ft_putstr_fd("Use only one decimal seperator if needed.\n", 1);
		ft_putstr_fd("Only use '.' for seperator.\n", 1);
		ft_putstr_fd("Values must be number.\n", 1);
		return (0);
	}
	return (1);
}

int main(int ac, char **av)
{
	t_fractol	fractal;

	if (!check_args(ac, av))
	{
		ft_putstr_fd(MSG, 1);
		return (1);
	}
	fractal.name = av[1];
	if (fractal.name == "julia")
	{
		fractal.julia_x = ft_atod(av[2]);
		fractal.julia_y = ft_atod(av[3]);
	}
	fractol_init(&fractal);
	render(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);
}