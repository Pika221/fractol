/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <hialpagu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:55:05 by hialpagu          #+#    #+#             */
/*   Updated: 2025/03/26 00:45:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	exit(0);
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		close_window(fractal);
	return (0);
}

static void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.4;
	if (zoom == 1)
	{
		fractal->shift_x = (x / fractal->zoom + fractal->shift_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->shift_y = (y / fractal->zoom + fractal->shift_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->shift_x = (x / fractal->zoom + fractal->shift_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->shift_y = (y / fractal->zoom + fractal->shift_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	if (button == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (button == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	render(fractal);
	return (0);
}

void	controllers(t_fractal *fractal)
{
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, close_window, fractal);
}
