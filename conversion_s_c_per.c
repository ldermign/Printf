/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s_c_per.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:37:39 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/24 15:51:18 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    fusion_conv_strflag(char *str, int nbr, t_flag_len *flag)
{
    int len_str;

    len_str = ft_strlen(str);
    if ((flag->conv_c == 1 && flag->padded_zero == 0 && flag->precision == -1)
    || flag->conv_per == 1)
		fusion_c(nbr, flag);
	else if (flag->conv_s == 1 && flag->padded_zero == 0)
		prep_fusion_s(str, flag->nbr_width, flag->nbr_precision, len_str, flag);
	else if (flag->conv_p == 1)
	 	fusion_p(str, flag->nbr_width, len_str, flag);
	else if (flag->conv_d_i == 1 || flag->conv_u == 1 || flag->conv_x == 1)
		fusion_d_i_u(str, nbr, flag);
}

void    conv_s(va_list ap, t_flag_len *flag)
{
    char	*arg_char;
	int		size_arg;

    arg_char = va_arg(ap, char *);
	size_arg = (int)ft_strlen(arg_char);
	if (arg_char == NULL || arg_char == 0)
		arg_char = "(null)";
    if (flag->nbr_width == 0 && flag->nbr_precision == 0 && flag->dot == 1)
        return ;
	else if (ft_no_flag(flag) || flag->padded_zero == 1
	|| (flag->nbr_precision < 0 && flag->width == -1))
    	ft_putstr(arg_char, flag);
	else
	{
		fusion_conv_strflag(arg_char, 0, flag);
		ft_putstr(flag->final_str_flag, flag);
	}
}

void    conv_c(va_list ap, t_flag_len *flag)
{
    int cara;
	
	cara = va_arg(ap, int);
	if (flag->nbr_width <= 1)
		ft_putchar(cara, flag);
	else
	{
		fusion_conv_strflag(NULL, cara, flag);
		if (cara > 31)
			ft_putstr(flag->final_str_flag, flag);
	}
}

void    conv_per(t_flag_len *flag)
{
	const int	charac = '%';

	if ((1 >= flag->nbr_precision) && (1 >= flag->nbr_width))
		ft_putstr("%", flag);
	else
	{
		fusion_conv_strflag(NULL, charac, flag);
		ft_putstr(flag->final_str_flag, flag);
	}
}