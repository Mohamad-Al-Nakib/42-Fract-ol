#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>

// WIDTH and HEIGHT --> Should be equal
# define WIDTH 800
# define HEIGHT 800

enum
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct fractol
{
	void	*mlx;
	void	*window;
	t_img	img;
	int		max_itr;
	int		colors;
	int		type;
	double	zoom;
	double	x;
	double	y;
	double	julia_x;
	double	julia_y;
}	t_fractol;

void	ft_render(t_fractol *fractol);
void	julia(t_fractol *fractol);
void	mandelbrot(t_fractol *fractol);
void	burning_ship(t_fractol *fractol);

int		ft_key_pressed(int key_code, t_fractol *fractol);
int		ft_mouse_zoom(int button, int x, int y, t_fractol *fractol);
int		ft_get_type(int ac, char **av, t_fractol *fractol);
int		ft_get_color(int iterations, int max_itr, int colors);
int		ft_exit(t_fractol *fractol);

int		ft_printf(const char *format, ...);
int		ft_strcmp(const char *s1, const char *s2);
double	ft_atod(const char *str);

#endif // FRACTOL_H

// Mohamad Al-Nakib
