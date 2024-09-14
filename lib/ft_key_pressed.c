#include "fractol.h"

/*
	'j' key for Julia constant Increase
	'k' key for Julia constant Decrease
	'Esc' key for Exit
	'Left Arrow' Move Left
	'Right Arrow' Move Right
	'Up Arrow' Move Up
	'Down Arrow' Move Down
	'c' key to change color scheme
*/

static void	ft_helper(int type, int key_code, t_fractol *fractol)
{
	if (type == JULIA && key_code == 106)
	{
		fractol->julia_x += 0.01;
		fractol->julia_y += 0.01;
	}
	else if (type == JULIA && key_code == 107)
	{
		fractol->julia_x -= 0.01;
		fractol->julia_y -= 0.01;
	}
}

int	ft_key_pressed(int key_code, t_fractol *fractol)
{
	if (key_code == 65307)
		ft_exit(fractol);
	else if (key_code == 65361)
		fractol->x -= 0.1 / fractol->zoom;
	else if (key_code == 65363)
		fractol->x += 0.1 / fractol->zoom;
	else if (key_code == 65362)
		fractol->y -= 0.1 / fractol->zoom;
	else if (key_code == 65364)
		fractol->y += 0.1 / fractol->zoom;
	else if (key_code == 99)
		fractol->colors = (fractol->colors + 1) % 3;
	else if (fractol->type == JULIA)
		ft_helper(fractol->type, key_code, fractol);
	ft_render(fractol);
	return (0);
}

//Mohamad Al-Nakib
