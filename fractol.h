#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> // debugging
# include <stdlib.h> // malloc, free
# include <unistd.h> // write, close
# include <math.h> // sqrt, pow
# include "minilibx-linux/mlx.h"

# define ERROR_MSG "Please enter: ./fractol mandelbrot OR ./fractol julia <value1> <value2>\n"

typedef struct s_img
{
	void	*img_ptr; // pointer to image struct
	char	*pxl; // pointes to the axctual pixels
	int		bits_per_pxl; // bits per pixel
	int		end; // endian
	int		line_length; // size of line in bytes
}				t_img;


typedef struct s_fractol
{
	//MLX
	void	*mlx; // mlx_init
	void	*mlx_window; // mlx_new_window
	// Image
	t_img	img;
	// hooks member variables
	

}				t_fractol;



// string_utils
int		ft_strncmp(char *s1, char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);


#endif