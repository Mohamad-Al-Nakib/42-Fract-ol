/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-naki <mal-naki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:27:25 by mal-naki          #+#    #+#             */
/*   Updated: 2024/06/23 13:07:44 by mal-naki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putptr(uintptr_t ptr);
int	ft_putp(uintptr_t value);
int	ft_putstr(const char *str);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned int n, int i);
int	ft_printf(const char *format, ...);
int	ft_format(const char *format, va_list args);
int	ft_format_cases(const char format, va_list args);

#endif
