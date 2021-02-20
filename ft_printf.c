/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/20 15:14:24 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	make_flags_right(t_flag_len *flag)
{
	if (flag->conv_d_i == 1 && flag->width == -1 && flag->precision == 1)
		flag->nbr_precision = 0;
	if (flag->padded_zero == 1 && flag->minus == 1)
		flag->padded_zero = 0;
	if (flag->nbr_width < 0)
	{
		flag->nbr_width *= -1;
		flag->minus = 1;
	}
	if (flag->nbr_precision < 0)
		flag->nbr_precision *= -1;
}

static void	ft_struct_conv(char c, t_flag_len *flag)
{
	if (c == 'c')
		flag->conv_c = 1;
	if (c == 's')
		flag->conv_s = 1;
	if (c == 'p')
		flag->conv_p = 1;
	if (c == 'd' || c == 'i')
		flag->conv_d_i = 1;
	if (c == 'u')
		flag->conv_u = 1;
	if (c == 'x' || c == 'X')
		flag->conv_x = 1;
	if (c == '%')
		flag->conv_per = 1;
}

static int		which_conv(const char *str, va_list ap, t_flag_len *flag)
{
	ft_struct_conv(*str, flag);
	make_flags_right(flag);
	flag_width(flag);
	flag_precision(flag);
	if (flag->conv_c == 1)
		conv_c(ap, flag);
	else if (flag->conv_s == 1)
		conv_s(ap, flag);
	else if (flag->conv_p == 1)
		conv_p(ap, flag);
	else if (flag->conv_d_i == 1)
		conv_d_i(ap, flag);
	else if (flag->conv_u == 1)
		conv_u(ap, flag);
	else if (flag->conv_x == 1)
		conv_x_X(*str, ap, flag);
	else if (flag->conv_per == 1)
		conv_per(flag);
	if (flag->str_width != NULL)
		free(flag->str_width);
	if (flag->str_precision != NULL)
		free(flag->str_precision);
	if (flag->final_str_flag != NULL)
		free(flag->final_str_flag);
	return (1);
}

static int		ft_printf_inside_job(const char *str, va_list ap)
{
	t_flag_len	flag;
	int			i;

	i = 0;
	flag.final_len = 0;
	while (str[i])
	{
		if (str[i] == '%' && ++i)
		{
			i += which_flag(&str[i], ap, &flag);
			if (ft_is_conv(str[i]))
				i += which_conv(&str[i], ap, &flag);
		}
		else if (str[i] != '%')
		{
			ft_putchar(str[i], &flag);
			i++;
		}
	}
	return (flag.final_len);
}

int		ft_printf(const char *str, ...)
{
	int			final_length;

	va_list ap;
	va_start(ap, str);
	final_length = ft_printf_inside_job(str, ap);
	va_end(ap);
	return (final_length);
}
