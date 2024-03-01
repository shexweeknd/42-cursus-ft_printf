/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:59:43 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/01 13:20:45 by hramaros         ###   ########.fr       */
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

typedef struct s_obj
{
	int	width = 0;
	int	precision = 0;
}		t_obj;

/* BONUS ONE "-0." */
int		ft_format_bonus_one(const char *str, va_list ap);

/* BONUS TWO "# +" */
int		ft_format_bonus_two(const char *str, va_list ap);

#endif