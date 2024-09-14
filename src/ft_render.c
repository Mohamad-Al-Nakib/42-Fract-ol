#include "fractol.h"

void	ft_render(t_fractol *fractol)
{
	if (fractol->type == MANDELBROT)
		mandelbrot(fractol);
	else if (fractol->type == JULIA)
		julia(fractol);
	else if (fractol->type == BURNING_SHIP)
		burning_ship(fractol);
}

// Mohamad Al-Nakib
