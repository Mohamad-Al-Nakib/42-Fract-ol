/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-naki <mal-naki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:32:08 by mal-naki          #+#    #+#             */
/*   Updated: 2024/06/23 13:07:12 by mal-naki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t ptr)
{
	int			count;
	const char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (ptr >= 16)
		count += ft_putptr(ptr / 16);
	count += ft_putchar(base[ptr % 16]);
	return (count);
}

int	ft_putp(uintptr_t value)
{
	int	count;

	count = 0;
	if (value == 0)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putptr(value);
	}
	return (count);
}
