/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:31:08 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/01 11:22:48 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	ret;
	float entry;

	entry = 7.6;
	ret = printf("%f", entry);
	printf("\n%d\n", ret);
	return (0);
}
