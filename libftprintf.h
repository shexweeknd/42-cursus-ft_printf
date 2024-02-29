/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:15:13 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/29 15:23:03 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_put_addr(void *addr);
int	ft_putnbr_base(int nbr, char *base);
int	ft_put_unsigned_nbr(unsigned int nb);
int	ft_putchar_i(char c);
int	ft_putstr(char *str);

#endif
