/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-naki <mal-naki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:38:57 by mal-naki          #+#    #+#             */
/*   Updated: 2024/06/23 13:07:16 by mal-naki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_cases(const char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (format == 'p')
		count += ft_putp(va_arg(args, uintptr_t));
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_format(const char *format, va_list args)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += ft_format_cases(*format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	return (count);
}
