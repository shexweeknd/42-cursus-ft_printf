/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alter_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:40:23 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/07 15:21:39 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

static void	ft_fullfill_s(t_data *data, char *s)
{
	int		i;
	size_t	padding_size;
	char	tmp[4096];

	// precision sur s truncate when presicion < strlen(s)
	i = 0;
	while (i < data->format.precision && s[i] && data->format.dot)
		tmp[i] = s[i++];
	tmp[i] = '\0';
	padding_size = data->format.width - i;
	// justify left
	if (data->format.minus)
	{
		i = 0;
		while (tmp[i])
			data->buffer[data->buffer_index++] = tmp[i++];
		while (padding_size--)
			data->buffer[data->buffer_index++] = ' ';
	}
	else if (!data->format.minus)
	{
		i = 0;
		while (padding_size--)
			data->buffer[data->buffer_index++] = ' ';
		while (tmp[i])
			data->buffer[data->buffer_index++] = tmp[i++];
	}
	return ;
}

void	ft_alter_s(t_data *data)
{
	// precision > justify > width
	//[-+][width][precision]
	ft_fullfill_s(data, va_arg(data->ap, char *));
	return ;
}
