#include "fractol.h"

/*
	handles mouse zoom events
*/

int	ft_mouse_zoom(int button, int x, int y, t_fractol *fractol)
{
	double	zoom_f;

	zoom_f = 1.1 ;
	if (button == 4)
	{
		fractol->zoom *= zoom_f;
		fractol->x = (x - WIDTH / 2.0) / WIDTH / fractol->zoom + fractol->x;
		fractol->y = (y - HEIGHT / 2.0) / HEIGHT / fractol->zoom + fractol->y;
		fractol->max_itr += 5 ;
	}
	else if (button == 5)
	{
		fractol->zoom /= zoom_f;
		fractol->x = (x - WIDTH / 2.0) / WIDTH / fractol->zoom + fractol->x;
		fractol->y = (y - HEIGHT / 2.0) / HEIGHT / fractol->zoom + fractol->y;
		fractol->max_itr -= 5 ;
	}
	ft_render(fractol);
	return (0);
}

//Mohamad Al-Nakib