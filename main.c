/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:31:08 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/09 07:39:35 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include "ft_bonus.h"

int	main(void)
{
	int	ret;

	ret = 42;
	ret = ft_printf("[%-5.2s]", "bjr");
	printf("\n%d\n", ret);
	ret = printf("[%-5.2s]", "bjr");
	printf("\n%d\n", ret);
	return (0);
}
