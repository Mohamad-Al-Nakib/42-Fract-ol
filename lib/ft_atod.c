#include "fractol.h"

/*
	convert a string to a double
*/

static double	ft_fraction(const char *str, long *i)
{
	double	fraction;
	double	divisor;

	divisor = 10.0;
	fraction = 0.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			fraction += (str[*i] - '0') / divisor;
			divisor *= 10.0;
			(*i)++;
		}
	}
	return (fraction);
}

double	ft_atod(const char *str)
{
	long	i;
	double	number;
	double	fraction;
	int		sign;

	i = 0;
	number = 0.0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	fraction = ft_fraction(str, &i);
	return (sign * (number + fraction));
}

// Mohamad Al-Nakib