#include "fractol.h"

/*
	generate psychedelic colors for fractals based
	on the number of iterations a fractal point undergoes
	calculates the RGB color values
	24 Bit integer representing the final color
*/

static void	ft_choose_color(double norm, int *red, int *green, int *blue)
{
	*red = (int)(9 * (1 - norm) * norm * norm * norm * 255);
	*green = (int)(8 * (1 - norm) * (1 - norm) * norm * norm * 255);
	*blue = (int)(4 * (1 - norm) * (1 - norm) * (1 - norm) * norm * 255);
}

int	ft_get_color(int itr, int max_itr, int colors)
{
	double	norm;
	int		red;
	int		green;
	int		blue;

	norm = (double)itr / max_itr;
	if (colors == 0)
		ft_choose_color(norm, &red, &green, &blue);
	else if (colors == 1)
	{
		red = (int)(255 * sin(norm * 10 * M_PI) + 128);
		green = (int)(255 * cos(norm * 12 * M_PI) + 128);
		blue = (int)(255 * sin(norm * 8 * M_PI) + 128);
	}
	else if (colors == 2)
	{
		red = (int)(7 * (1 - norm) * norm * norm * norm * 255);
		green = (int)(4 * (1 - norm) * (1 - norm) * norm * norm * 255);
		blue = (int)(10 * (1 - norm) * (1 - norm) * (1 - norm) * norm * 255);
	}
	else
		return (0xFFFFFF);
	return ((red << 16) | (green << 8) | blue);
}

// Mohamad Al-Nakib

/*

Color Options :

red = (int)(127 * sin(norm * 10 * M_PI + 2) + 128);
green = (int)(127 * cos(norm * 15 * M_PI + 4) + 128);
blue = (int)(127 * sin(norm * 20 * M_PI + 6) + 128);

red = (int)(127 * sin(norm * 12 * M_PI + 2) + 128);
green = (int)(127 * cos(norm * 17 * M_PI + 4) + 128);
blue = (int)(127 * sin(norm * 8 * M_PI + 6) + 128);

Black and Blue :
red = (int)(9 * (1 - norm) * norm * norm * norm * 255);
green = (int)(15 * (1 - norm) * (1 - norm) * norm * norm * 255);
blue = (int)(8.5 * (1 - norm) * (1 - norm) * (1 - norm) * norm * 255);

Black and Orange :
red = (int)(9 * (1 - norm) * norm * norm * norm * 255);
green = (int)(8 * (1 - norm) * (1 - norm) * norm * norm * 255);
blue = (int)(2 * (1 - norm) * (1 - norm) * (1 - norm) * norm * 255);

Emerald Green :
red = (int)(2 * (1 - norm) * norm * norm * norm * 255);
green = (int)(14 * (1 - norm) * (1 - norm) * norm * norm * 255);
blue = (int)(5 * (1 - norm) * (1 - norm) * (1 - norm) * norm * 255);

Lavender Dream (Purple-Pink)
red = (int)(7 * (1 - norm) * norm * norm * norm * 255);
green = (int)(4 * (1 - norm) * (1 - norm) * norm * norm * 255);
blue = (int)(10 * (1 - norm) * (1 - norm) * (1 - norm) * norm * 255);

red = (int)(127.5 * (1 + sin(M_PI * norm * 3.0)) * 255);
green = (int)(127.5 * (1 + sin(M_PI * norm * 3.0 + M_PI / 3)) * 255);
blue = (int)(127.5 * (1 + sin(M_PI * norm * 3.0 + 2 * M_PI / 3)) * 255);

 */