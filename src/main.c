#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.mlx = mlx_init();
	fractol.window = mlx_new_window(fractol.mlx, WIDTH, HEIGHT,
			"Mohamad Al-Nakib Fract-ol");
	fractol.zoom = 1.0;
	fractol.x = 0;
	fractol.y = 0;
	fractol.max_itr = 42;
	fractol.julia_x = -0.5;
	fractol.julia_y = 0.42;
	fractol.colors = 0;
	fractol.img.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	fractol.img.addr = mlx_get_data_addr(fractol.img.img,
			&fractol.img.bits_per_pixel,
			&fractol.img.line_length, &fractol.img.endian);
	fractol.type = ft_get_type(ac, av, &fractol);
	ft_render(&fractol);
	mlx_key_hook(fractol.window, ft_key_pressed, &fractol);
	mlx_mouse_hook(fractol.window, ft_mouse_zoom, &fractol);
	mlx_hook(fractol.window, 17, 0, ft_exit, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}

// Mohamad Al-Nakib
