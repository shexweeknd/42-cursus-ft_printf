/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:22:20 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/05 07:38:44 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	ft_putformat(const char *str, t_obj *obj)
{
	int		printed;
	char	*set;

	set = "cspdiuxX%";
	if (!ft_isset(*str, set))
		return (0);
	printed = 0;
	if (*str == 'c')
		printed += ft_putchar_i(va_arg(obj->ap, int));
	else if (*str == 's')
		printed += ft_putstr(va_arg(obj->ap, char *));
	else if (*str == 'p')
		printed += ft_put_addr(va_arg(obj->ap, void *));
	else if (*str == 'd' || *str == 'i')
		printed += ft_putnbr_base(va_arg(obj->ap, int), "0123456789");
	else if (*str == 'u')
		printed += ft_put_unsigned_nbr(va_arg(obj->ap, unsigned int));
	else if (*str == 'x')
		printed += ft_putx(va_arg(obj->ap, int), "0123456789abcdef");
	else if (*str == 'X')
		printed += ft_putx(va_arg(obj->ap, int), "0123456789ABCDEF");
	else if (*str == '%')
		printed += write(1, "%", 1);
	return (printed);
}

static void	ft_init_obj(t_obj *obj, char *str)
{
	obj->s_len = ft_strlen(str);
	obj->str = str;
	obj->cursor = str;
	obj->printed = 0;
	return ;
}

static int	ft_isflag(char *str)
{
	if (ft_isint(str))
		return (1) return (0);
}

int	ft_printf(const char *str, ...)
{
	t_obj	*obj;

	obj = (t_obj *)malloc(sizeof(t_obj));
	ft_init_obj(obj, (char *)str);
	va_start(obj->ap, str);
	while (*str)
	{
		if (*str == '%')
			obj->printed += ft_putformat(++str, obj);
		else
			obj->printed += write(1, str, 1);
		str++;
	}
	va_end(obj->ap);
	free(obj);
	return (obj->printed);
}

// algorithm
/*

1 - create struct to store data
	actual pointer
	the ap
	the chars written
	the buffer
	the buffer index
	the format associated with the actual iteration in it

2 - create a struct to store flags, width, and precision
	0 for each flag is unset
	1 for each flag is set
	!! width flag must be different than zero
	precision can be zero but must be seen after '.'

3 - create a buffer that stores the char and its already printed value

4 - store into the buffer until you see the % sign

5 - parse the flags if incountered % sign

6 - flush the buffer at the end of the day

*/