/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:31:08 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/29 14:41:08 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	int *res;
	int ret;

	res = &ret;
	ret = printf("%p", res);
	printf("\n%d\n", ret);
	return (0);
}