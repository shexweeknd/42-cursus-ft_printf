/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:22:20 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/05 11:37:40 by hramaros         ###   ########.fr       */
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

static int	ft_putformat(const char *str, t_data *data)
{
	int		printed;
	char	*set;

	set = "cspdiuxX%";
	if (!ft_isset(*str, set))
		return (0);
	printed = 0;
	if (*str == 'c')
		printed += ft_putchar_i(va_arg(data->ap, int));
	else if (*str == 's')
		printed += ft_putstr(va_arg(data->ap, char *));
	else if (*str == 'p')
		printed += ft_put_addr(va_arg(data->ap, void *));
	else if (*str == 'd' || *str == 'i')
		printed += ft_putnbr_base(va_arg(data->ap, int), "0123456789");
	else if (*str == 'u')
		printed += ft_put_unsigned_nbr(va_arg(data->ap, unsigned int));
	else if (*str == 'x')
		printed += ft_putx(va_arg(data->ap, int), "0123456789abcdef");
	else if (*str == 'X')
		printed += ft_putx(va_arg(data->ap, int), "0123456789ABCDEF");
	else if (*str == '%')
		printed += write(1, "%", 1);
	return (printed);
}

static void	ft_init_data(t_data *data, char *str)
{
	data->s_len = ft_strlen(str);
	data->str = str;
	data->cursor = str;
	data->printed = 0;
	return ;
}

static int	ft_isflag(char *str)
{
	if (ft_isint(str))
		return (1) return (0);
}

//TODO fonction ft_get_format, fonction qui check data->str puis set the flags associated with it
static void ft_get_format(t_data *data)
{	
	//check flags

	//check width

	//check precision

	return ;
}

static unsigned int	ft_flush(t_data *data)
{
	int	i;

	i = 0;
	while (*(data->buffer + i))
		data->printed += write(1, (data->buffer + i++), 1);
	free(data->buffer);
	return (data->printed);
}

static void	ft_init_data(t_data data, char *str, char *buffer)
{
	data->str = str;
	printed = 0;
	data->buffer = buffer;
	ft_memset(data->format, 0, sizeof(t_format));
	return ;
}

int	ft_printf(const char *str, ...)
{
	t_data			*data;
	char			*buffer;
	unsigned int	printed;

	buffer = (char *)malloc(sizeof(char) * 4096);
	if (!buffer)
		return (NULL);
	va_start(data->ap, str);
	ft_init_data(data, str, buffer);
	while (*data->str)
	{
		if (*data->str == '%' && *(++data->str))
			ft_get_format(data);
		*buffer++ = *data->str++;
	}
	printed = ft_flush(data);
	va_end(data->ap);
	free(data);
	return (printed);
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