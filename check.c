/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:01:04 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/31 15:19:40 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_flag(char c)
{
	if (c == '-' || c == '*' || c == '.' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int		ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_is_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
	|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int 	ft_is_width(char c)
{
	if ((c >= '0' && c <= '9') || c == '.' || c == '*')
		return (1);
	return (0);
}

/*

int		ft_check_flag(const char *str)
{
	str++;
	if (!ft_is_flag(*str) || !ft_is_conv(*str))
		return (-1);
	if (flag->minus == 1 && flag->padded_zero == 1)
		flag->padded_zero = -1;
	return (1);
}*/