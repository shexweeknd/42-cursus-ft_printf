/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:31:08 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/09 09:32:03 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include "ft_bonus.h"

int	main(void)
{
	int	ret;

	ret = 42;
	ret = ft_printf("[%p]", "ret");
	printf("\n%d\n", ret);
	ret = printf("[%-15p]", "ret");
	printf("\n%d\n", ret);
	return (0);
}
