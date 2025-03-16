#include "fractol.h"

/*
	INIT
	MLX
	Listening events
	hooks data
*/

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->mlx_window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fractol");
	fractol->img.img_ptr = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img.pxl = mlx_get_data_addr(fractol->img.img_ptr, &fractol->img.bits_per_pxl, &fractol->img.line_length, &fractol->img.end);
}