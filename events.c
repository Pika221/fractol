#include "fractol.h"

int close_window(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(0);
}

int	key_hook(int keycode, t_fractol *fractal)
{
	if (keycode == ESC)
		close_window(fractal);
	if (keycode == UP)
		fractal->shift_y -= (0.5 / fractal->zoom);
	else if (keycode == DOWN)
		fractal->shift_y += (0.5 / fractal->zoom);
	else if (keycode == LEFT)
		fractal->shift_x -= (0.5 / fractal->zoom);
	else if (keycode == RIGHT)
		fractal->shift_x += (0.5 / fractal->zoom);
	else if (keycode == COLOR_1)
		fractal->iterations_definition += 10;
	else if (keycode == COLOR_2)
		fractal->iterations_definition -= 10;
	render(fractal);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == SCROLL_DOWN)
		fractol->zoom *= 0.9;
	else if (button == SCROLL_UP)
		fractol->zoom *= 1.1;
	render(fractol);
	return 0;
}
int	julia_move(int x, int y, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		fractol->julia_x = (map(x, -2, +2, SIZE) * fractol->zoom) + fractol->shift_x;
		fractol->julia_y = (map(y, +2, -2, SIZE) * fractol->zoom) + fractol->shift_y;
		render(fractol);
	}
	return 0;
}
