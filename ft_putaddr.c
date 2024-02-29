/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:35:03 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/29 11:40:47 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_put_addr(void *addr)
{
	unsigned int	i;
	char			b_data[sizeof(int *)];
	char			data[2];
	char			*hex;
	int				printed;

	hex = "0123456789abcdef";
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
