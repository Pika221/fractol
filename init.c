#include "fractol.h"

static void	exit_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

static void	data_control(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations_definition = 42;
	fractol->shift_x = -0.5;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

static void	controllers(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_window, key_hook, fractol);
	mlx_mouse_hook(fractol->mlx_window, mouse_hook, fractol);
	mlx_hook(fractol->mlx_window, 17, 0L, close_window, fractol);
	mlx_hook(fractol->mlx_window, 6, 0, julia_move, fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (!fractol->mlx_connection)
		exit_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, SIZE, SIZE, fractol->name);
	if (!fractol->mlx_window)
	{
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		exit_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, SIZE, SIZE);
	if (!fractol->img.img_ptr)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		exit_error();
	}
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr, &fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);
	controllers(fractol);
	data_control(fractol);
}
