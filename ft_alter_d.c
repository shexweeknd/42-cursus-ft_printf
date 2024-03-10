/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alter_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 03:57:41 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/10 04:39:21 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

static void	ft_fullfill_d(t_data *data, int nbr)
{
}

void	ft_alter_d(t_data *data)
{
	//[-+ 0][width][precision]
	ft_fullfill_d(data, va_arg(data->ap, int));
	return ;
}

// exceptionnnels
/*
' ' avec '+' est interdit
'0' avec '-' est interdit
'0' avec precision est interdit
*/

//' ' ajoute un seul espace espace > (0 + width)
//' ' > '-'
//'0' seul ne fait rien (width >= 1)
// precision > width (width ne fait rien si ft_strlen(buffer) > width)
// precision agit comme '0' il ajoute des zeros dans le buffer
//width sans '0' ajoute des espaces
//with avec '0' ajoute des zero a la place des espaces

// (' ' | +) > precision > justify > width
// (' ' | +) > (0 + width) ==> si on a un ' ' alors le nombre de zero est de len_nbr(nbr) - (width - 1) sinon si on a pas un ' ' alors le nombre de zero est de len_nbr(nbr) - width