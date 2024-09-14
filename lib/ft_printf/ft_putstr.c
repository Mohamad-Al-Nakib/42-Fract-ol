/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-naki <mal-naki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:33:20 by mal-naki          #+#    #+#             */
/*   Updated: 2024/06/23 12:49:49 by mal-naki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
		count += ft_putchar(str[i++]);
	return (count);
}
