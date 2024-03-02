/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:34:54 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/02 02:27:30 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

static int ft_isint(char *str)
{
	int ret;

	ret = ft_atoi(str);
	if (!ret)
		return (0);
	return (ret);
}

static int padding_space(char *str)
{
	int printed;

	printed = 0;
	return (printed);
}

int	ft_format_bonus_one(const char *str, va_list ap)
{
	int	printed;

	printed = 0;
	if (*str == ft_isint(str + 1))
		printed += ft_padding_space(str + 1);
	
	// if (*str == '.')
	// 	printed += ft_precision(str + 1);
	// if (*str == '-')
	// 	printed += ft_justify_left(str + 1);
	return (printed);
}
