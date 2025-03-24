/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <hialpagu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:41:13 by hialpagu          #+#    #+#             */
/*   Updated: 2025/03/25 00:16:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color(int x, int y, t_fractal *fractal, int color)
{
	int	*tmp;

	tmp = (int *)fractal->img_ptr;
	tmp[y * (fractal->line_len / 4) + x] = color;
}

static void	m_set(t_fractal *fractal)
{
	int		i;
	double	tmp;

	i = -1;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->shift_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->shift_y;
	while (i < fractal->iteration)
	{
		tmp = (fractal->zx * fractal->zx) - (fractal->zy * fractal->zy)
			+ fractal->cx;
		fractal->zy = 2.0 * fractal->zy * fractal->zx + fractal->cy;
		fractal->zx = tmp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
		i++;
	}
	if (i == fractal->iteration)
		color(fractal->x, fractal->y, fractal, 0);
	else
		color(fractal->x, fractal->y, fractal, fractal->color * i);
}

static void	j_set(t_fractal *fractal)
{
	int		i;
	double	tmp;

	i = 0;
	fractal->cx = fractal->julia_x;
	fractal->cy = fractal->julia_y;
	fractal->zx = (fractal->x / fractal->zoom) + fractal->shift_x;
	fractal->zy = (fractal->y / fractal->zoom) + fractal->shift_y;
	while (i < fractal->iteration)
	{
		tmp = (fractal->zx * fractal->zx) - (fractal->zy * fractal->zy)
			+ fractal->cx;
		fractal->zy = 2.0 * fractal->zy * fractal->zx + fractal->cy;
		fractal->zx = tmp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
		i++;
	}
	if (i == fractal->iteration)
		color(fractal->x, fractal->y, fractal, 0);
	else
		color(fractal->x, fractal->y, fractal, fractal->color * i);
}

void	render(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			if (!ft_strncmp(fractal->name, "mandelbrot", 10))
			{
				m_set(fractal);
				(fractal->y)++;
			}
			else if (!ft_strncmp(fractal->name, "julia", 5))
			{
				j_set(fractal);
				(fractal->y)++;
			}
		}
		fractal->y = 0;
		(fractal->x)++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->img, 0, 0);
}
