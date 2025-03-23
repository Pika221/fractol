#include "fractol.h"

static void put_pixel(int x, int y, t_img *img, int color)
{
	int		offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static	void	mandel_or_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	pixel_coord(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, +2, SIZE) * fractol->zoom) + fractol->shift_x;
	z.y = (map(y, +2, -2, SIZE) * fractol->zoom) + fractol->shift_y;
	mandel_or_julia(&z, &c, fractol);
	while (i < fractol->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = map(i, BLACK, WHITE, fractol->iterations_definition);
			put_pixel(x, y, &fractol->img, color);
			return ;
		}
		++i;
	}
	put_pixel(x, y, &fractol->img, BLACK);
}

void	render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			pixel_coord(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window, fractol->img.img_ptr, 0, 0);
}
