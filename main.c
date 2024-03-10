/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:31:08 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/10 04:38:06 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include "ft_bonus.h"

int	main(void)
{
	int	ret;

	ret = 42;
	// ret = ft_printf("[%15p]", &ret);
	// printf("\n%d\n", ret);
	ret = printf("[%+07d]", ret);
	printf("\n%d\n", ret);
	return (0);
}
