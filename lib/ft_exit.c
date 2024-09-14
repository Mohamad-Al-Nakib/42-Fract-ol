#include "fractol.h"

/*
        Free all allocated memory and exit program
*/

int	ft_exit(t_fractol *fractol)
{
	ft_printf("Done By --> Mohamad Al-Nakib \n");
	if (!fractol)
		exit(0);
	if (fractol->img.img)
		mlx_destroy_image(fractol->mlx, fractol->img.img);
	if (fractol->window && fractol->mlx)
		mlx_destroy_window(fractol->mlx, fractol->window);
	if (fractol->mlx)
	{
		mlx_loop_end(fractol->mlx);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	exit (0);
	return (0);
}

//Mohamad Al-Nakib