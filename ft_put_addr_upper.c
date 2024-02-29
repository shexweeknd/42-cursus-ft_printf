/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:35:03 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/29 12:31:34 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_put_addr_upper(void *addr)
{
	unsigned int	i;
	char			b_data[sizeof(int *)];
	char			data[2];
	char			*hex;
	int				printed;

	hex = "0123456789ABCDEF";
	i = 0;
	while (i < sizeof(int *))
	{
		b_data[i] = ((char *)&addr)[i];
		i++;
	}
	i = sizeof(int *);
	printed = 0;
	while (i > 0)
	{
		data[0] = hex[((char)b_data[i - 1] >> 4) & 0xf];
		data[1] = hex[(char)b_data[i - 1] & 0xf];
		printed += write(1, data, 2);
		i--;
	}
	return (printed);
}
