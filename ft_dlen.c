/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:23:38 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/11 08:24:36 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

size_t	ft_ullen(unsigned long nbr)
{
	size_t	res;

	res = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		res++;
	}
	return (res);
}

size_t ft_intlen(int nbr)
{
	size_t size;

	size = 1;
	if (nbr < 0)
		size++;
	size += ft_ullen (-nbr);
}