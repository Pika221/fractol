/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <hialpagu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:32:09 by hialpagu          #+#    #+#             */
/*   Updated: 2025/03/25 01:58:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (ac == 4 && (ft_atod(av[3]) > __DBL_MAX__
			|| ft_atod(av[2]) > __DBL_MAX__
			|| ft_atod(av[2]) < ((__DBL_MAX__ + 1) * -1)
			|| ft_atod(av[3]) < ((__DBL_MAX__ + 1) * -1)))
		return (0);
	return (1);
}

static void	julia_recommend(void)
{
	ft_putstr_fd("Recomended Julia Values: -0.7  ,  0.27015\n", 1);
	ft_putstr_fd("\t\t\t    0  ,  0.8\n", 1);
	ft_putstr_fd("\t\t\t 0.37  ,  0.1\n", 1);
	ft_putstr_fd("\t\t\t0.355  , -0.355\n", 1);
	ft_putstr_fd("\t\t\t-0.54  ,  0.54\n", 1);
	ft_putstr_fd("\t\t\t 0.34  , -0.05\n", 1);
}

int	main(int ac, char **av)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (0);
	if (!check_args(ac, av))
	{
		ft_putstr_fd(MSG, 1);
		julia_recommend();
		free(fractal);
		exit(1);
	}
	fractal_init(fractal, av[1]);
	if (ac == 4)
	{
		fractal->julia_x = ft_atod(av[2]);
		fractal->julia_y = ft_atod(av[3]);
	}
	render(fractal);
	controllers(fractal);
	mlx_loop(fractal->mlx);
	free(fractal);
	return (0);
}
