/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:36:26 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/29 11:57:28 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	recurse_nbr(int nbr, char *base)
{
	int	base_size;
	int printed;

	base_size = 0;
	while (base[base_size])
		base_size++;
	if (base_size == 0)
		return (0);
	if (nbr >= base_size)
	{
		printed += recurse_nbr(nbr / base_size, base);
		write(1, nbr % base_size, 1);
	}
	else if (nbr < base_size)
		printed += write(1, nbr % base_size, 1);
	return (printed);
}

static int	verify_errors(char *base)
{
	int	y;
	int	x;

	if (!base || !base[1])
		return (0);
	y = 0;
	while (base[y])
	{
		if (base[y] == '+' || base[y] == '-' || base[y] <= 32)
			return (0);
		y++;
	}
	x = 0;
	while (base[y])
	{
		x = y + 1;
		while (base[x])
		{
			if (base[x] == base[y])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	x;
	int	y;
	int printed;

	if (!verify_errors(base))
		return ;
	y = 0;
	while (base[y])
	{
		x = y + 1;
		while (base[x])
		{
			if (base[x] == base[y])
				return ;
			x++;
		}
		y++;
	}
	printed = 0;
	if (nbr < 0)
	{
		printed += write(1, "-", 1);
		nbr *= -1;
	}
	printed += recurse_nbr(nbr, base);
}
