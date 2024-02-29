/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:31:08 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/29 16:29:43 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	*res;
	int	ret;

	res = &ret;
	ret = printf("%d", LONG_MAX);
	printf("\n%d\n", ret);
	return (0);
}
