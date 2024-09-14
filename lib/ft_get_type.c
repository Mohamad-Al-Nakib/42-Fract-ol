#include "fractol.h"

/*
	determine the type of the fractal from the user input
*/

static void	ft_check_julia(t_fractol *fractol, char **av)
{
	if (ft_atod(av[2]) && ft_atod(av[3]))
	{
		fractol->julia_x = ft_atod(av[2]);
		fractol->julia_y = ft_atod(av[3]);
	}
	else
	{
		ft_printf("Error --> Invalid Juila Values\n");
		ft_exit(fractol);
	}
}

int	ft_get_type(int ac, char **av, t_fractol *fractol)
{
	if (ac < 2 || ac > 4 || ac == 3)
	{
		ft_printf("-- Fractals --\nMandelbrot[1]\nJulia[2]\nBurning_ship[3]\n");
		ft_exit(fractol);
		exit(1);
	}
	if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1], "1") == 0)
		return (MANDELBROT);
	if (ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], "2") == 0)
	{
		if (ac == 4)
			ft_check_julia(fractol, av);
		return (JULIA);
	}
	if (ft_strcmp(av[1], "Burning_ship") == 0 || ft_strcmp(av[1], "3") == 0)
		return (BURNING_SHIP);
	else
	{
		ft_printf(" -- Invalid Fractal -- \n");
		ft_printf("-- Fractals --\nMandelbrot[1]\nJulia[2]\nBurning_ship[3]\n");
		ft_exit(fractol);
		exit(1);
	}
}

// Mohamad Al-Nakib
