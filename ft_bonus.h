/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:59:43 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/06 07:10:53 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BONUS_H
# define FT_BONUS_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char *str;
	va_list ap;
	unsigned int printed;
	char *buffer;
	t_format format;
}		t_data;

typedef struct s_format
{
	//[-+' '0]
	int minus;
	int plus;
	int space;
	int zero;
	int dash;

	//width
	int witdh_amount;

	//precision
	int precision;
}	t_format;

/* BONUS ONE "-0." */
int		ft_format_bonus_one(const char *str, va_list ap);

/* BONUS TWO "# +" */
int		ft_format_bonus_two(const char *str, va_list ap);

#endif