/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:35:03 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/29 15:20:28 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_put_nil(void)
{
	write(1, "(nil)", 5);
	return (5);
}

int	ft_put_addr(void *addr)
{
	unsigned int	i;
	char			b_data[sizeof(int *)];
	char			data[2];
	char			*hex;
	int				printed;

	hex = "0123456789abcdef";
	i = 0;
	if (!addr)
		return (ft_put_nil());
	while (i < sizeof(int *))
	{
		b_data[i] = ((char *)&addr)[i];
		i++;
	}
	i = sizeof(int *);
	printed = 0;
	printed += write(1, "0x", 2);
	while (i > 0)
	{
		data[0] = hex[((char)b_data[i - 1] >> 4) & 0xf];
		data[1] = hex[(char)b_data[i - 1] & 0xf];
		if (i <= sizeof(int *) - 2)
			printed += write(1, data, 2);
		i--;
	}
	return (printed);
}
