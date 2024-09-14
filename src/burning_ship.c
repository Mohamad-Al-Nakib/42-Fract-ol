#include "fractol.h"

static void	ft_show(t_fractol *fractol)
{
	int	c;
	int	k;

	c = 10;
	k = 20;
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->img.img, 0, 0);
	mlx_string_put(fractol->mlx, fractol->window, c, k,
		0xFFFFFF, "------------------ Controls ------------------");
	mlx_string_put(fractol->mlx, fractol->window, c, k + 20,
		0xFFFFFF, "Mouse Wheel : zoom in and out on your cursor");
	mlx_string_put(fractol->mlx, fractol->window, c, k + 40,
		0xFFFFFF, "Arrow Keys : navigate around the fractal canva");
	mlx_string_put(fractol->mlx, fractol->window, c, k + 60,
		0xFFFFFF, "'c': change the fractal color scheme");
	mlx_string_put(fractol->mlx, fractol->window, c, k + 80,
		0xFFFFFF, "Esc : close the application");
	mlx_string_put(fractol->mlx, fractol->window, c, k + 100,
		0xFFFFFF, "-------- Done By : Mohamad Al-Nakib ----------");
}

static int	ft_calculate(int x, int y, int iterations, t_fractol *fractol)
{
	double	zx;
	double	zy;
	double	c_x;
	double	c_y;
	double	tmp;

	c_x = (x - WIDTH / 2.0) * 4.0 / WIDTH / fractol->zoom + fractol->x;
	c_y = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / fractol->zoom + fractol->y;
	zx = c_x;
	zy = c_y;
	iterations = 0;
	while (zx * zx + zy * zy < 4 && iterations < fractol->max_itr)
	{
		tmp = zx * zx - zy * zy + c_x;
		zy = fabs(2.0 * zx * zy) + c_y;
		zx = fabs(tmp);
		iterations++;
	}
	return (iterations);
}

void	burning_ship(t_fractol *fractol)
{
	int		x;
	int		y;
	int		iterations;
	int		color;
	char	*pixel;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			iterations = ft_calculate(x, y, iterations, fractol);
			color = ft_get_color(iterations, fractol->max_itr, fractol->colors);
			pixel = fractol->img.addr + (y * fractol->img.line_length
					+ x * (fractol->img.bits_per_pixel / 8));
			*(unsigned int *)pixel = color;
		}
	}
	ft_show(fractol);
}

// Mohamad Al-Nakib