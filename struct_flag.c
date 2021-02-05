/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:46:59 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/05 12:01:31 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_flag(t_flag_len flag, va_list ap)
{
	if (flag.minus == 1)
		flag_minus(ap);
	if (flag.padded_zero == 1)
		flag_padded_zero(ap);
	if (flag.width == 1)
		flag_width(ap, &flag);	
	if (flag.precision == 1)
		flag_precision(ap);
}

void	ft_init_struct_flag(t_flag_len *flag)
{
	flag->minus = 0;
	flag->padded_zero = 0;
	flag->width = 0;
	flag->precision = 0;
}

int which_flag(const char *str, t_flag_len *flag)
{
	int avancement;

	avancement = ft_strlen(str);
	ft_init_struct_flag(flag);
	if (str)
	{
		str++;
		while (ft_is_flag(*str))
		{
			if (*str == '-')
				flag->minus = 1;
			if (*str == '0')
				flag->padded_zero = 1;
			if (*str == '*' || (ft_is_digit(*str) && *(str + 1) == '.'))
			{
				flag->width = 1;
				while (*str == '*' || ft_is_digit(*str))
					str++;
				if ((*str == '.' && ft_is_digit(*str + 1))
				|| *(str + 1) == '*')
					flag->precision = 1;
			}
			str++;
		}
	}
	return (avancement - ft_strlen(str) - 1);
}

int		ft_check_flag(const char *str, t_flag_len *flag)
{
	str++;
	if (flag->minus == 1 && flag->padded_zero == 1)
		flag->padded_zero = 0;
	if (!ft_is_flag(*str) || !ft_is_conv(*str))
		return (-1);
	while (ft_is_flag(*str) || ft_is_conv(*str))
	{
		if (ft_is_digit(*str) && *(str + 1) == '*')
			return (-1);
		if (*str == '*' && ft_is_digit(*(str + 1)))
			return (-1);
		str++;
	}
	return (1);
}