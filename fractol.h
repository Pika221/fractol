#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define MSG "Usage: ./fractol mandelbrot | julia <value1> <value2>\n"
# define SIZE 800

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define COLOR_1 49
# define COLOR_2 50

#define BLACK       0x000000
#define WHITE       0xFFFFFF


typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;


typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int	iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractol;


int			close_window(t_fractol *fractol);
int			key_hook(int keysym, t_fractol *fractol);
int			mouse_hook(int button, int x, int y, t_fractol *fractol);
double		map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		render(t_fractol *fractol);
void		fractol_init(t_fractol *fractol);
int 		ft_is_double(char *s);
int			ft_strncmp(char *s1, char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
double		ft_atod(char *s);
int			julia_move(int x, int y, t_fractol *fractol);

#endif