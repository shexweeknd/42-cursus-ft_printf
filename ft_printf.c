/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:22:20 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/29 12:15:58 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_isset(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_putformat(char *str, va_list ap)
{
	int		printed;
	char	*set;

	set = "cspdiuxX%";
	if (!ft_isset(*(str + 1), set))
		return (0);
	printed = 0;
	if (*(str + 1) == 'c')
		printed += write(1, va_args(ap, int), 1);
	if (*(str + 1) == 's')
		printed += ft_putstr(va_args(ap, char *));
	if (*(str + 1) == 'p')
		printed += ft_putaddr(va_args(ap, void *), sizeof(void *));
	if (*(str + 1) == 'd' || *(str + 1) == 'i')
		printed += ft_putnbr_base(va_args(ap, int), "0123456789");
	if (*(str + 1) == 'u')
		printed += ft_put_unsigned(va_args(ap, unsigned int));
	if (*(str + 1) == 'x')
		printed += ft_putnbr_base(va_args(ap, int), "0123456789abcdef");
	if (*(str + 1) == 'X')
		printed += ft_putnbr_base(va_args(ap, int), "0123456789ABCDEF");
	if (*(str + 1) == '%')
		printed += write(1, 37, 1);
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printed;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			printed += ft_putformat((char *)str, ap);
		else
			printed += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (printed);
}
