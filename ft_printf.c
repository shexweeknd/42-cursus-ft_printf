/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:22:20 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/28 19:45:39 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_free(char **buffer)
{
	int	count;

	count = 0;
	while (*(buffer + count))
	{
		free(*(buffer + count));
		count++;
	}
	free(buffer);
	return ;
}

int	ft_printf(const char *str, ...)
{
	char	*set;
	char	**buffer2d;
	size_t	count;

	set = "cspdiuxX%";
	// split avec le caractere %
	buffer2d = ft_split(str, "%");
	// ft_putstr chaque element du buffer
	count = 0;
	while (*(buffer2d + count))
	{
		ft_putstr_fd(*(buffer2d + count), 1);
		count++;
	}
    //recuperer la liste des va_list
	// free le buffer
	ft_free(buffer2d);
	return (0);
}
