/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <hialpagu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:55:40 by hialpagu          #+#    #+#             */
/*   Updated: 2025/03/25 01:01:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx/mlx.h"

# define MSG "Usage: ./fractol mandelbrot | julia <value1> <value2>\n"
# define SIZE 1024

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define COLOR_1 49
# define COLOR_2 50

typedef struct s_fractal
{
	char	*name;
	void	*mlx;
	void	*window;
	void	*img;
	void	*img_ptr;
	int		x;
	int		y;
	int		iteration;
	int		bpp;
	int		end;
	int		line_len;
	int		color;
	double	julia_x;
	double	julia_y;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	cx;
	double	cy;
	double	zx;
	double	zy;
}	t_fractal;

void	controllers(t_fractal *fractal);
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
int		key_hook(int key_code, t_fractal *fractal);
int		close_window(t_fractal *fractal);
void	fractal_init(t_fractal *fractal, char *name);
void	render(t_fractal *fractal);
int		ft_is_double(char *s);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
double	ft_atod(char *s);

#endif