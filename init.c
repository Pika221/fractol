/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hialpagu <hialpagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:55:10 by hialpagu          #+#    #+#             */
/*   Updated: 2025/03/26 14:05:22 by hialpagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	exit_n_error(t_fractal *fractal)
{
	mlx_destroy_display(fractal->mlx);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

static void	fractal_data(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->iteration = 40;
	fractal->color = 0x3435FF;
}

void	fractal_init(t_fractal *fractal, char *name)
{
	fractal_data(fractal);
	fractal->name = name;
	fractal->mlx = mlx_init();
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "JULIA SET");
		fractal->shift_x = -1.45;
		fractal->shift_y = -1.45;
		fractal->zoom = 350;
	}
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE,
				"MANDELBROT SET");
		fractal->shift_x = -2;
		fractal->shift_y = -1.35;
		fractal->zoom = 380;
	}
	fractal->img = mlx_new_image(fractal->mlx, SIZE, SIZE);
	if (!fractal->mlx || !fractal->window || !fractal->img)
		exit_n_error(fractal);
	fractal->img_ptr = mlx_get_data_addr(fractal->img, &fractal->bpp,
			&fractal->line_len, &fractal->end);
}
