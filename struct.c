/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:46:59 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/31 12:18:09 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct_conversion(t_conversion *conv)
// initialiser structure de conversion
{
	conv->cara_c = 0;
	conv->string_s = 0;
	conv->point_ad_hex_p = 0;
	conv->int_dec_d = 0;
	conv->int_dec_i = 0;
	conv->unsd_int_u = 0;
	conv->unsd_hex_x = 0;
	conv->unsd_hex_X = 0;
	conv->percent = 0;
}

void	ft_init_struct_flag(t_flags *flag)
// initialiser structure de flag
{
	flag->minus = 0;
	flag->padded_zero = -1;
	flag->widht = 0;
	flag->precision = 0;
}

int	ft_which_print(const char *str, t_conversion *conv)
{
	ft_init_struct_conversion(conv);
	if (str)
	{
		str++;
		while (ft_is_flag(*str))
			str++;
		if (*str == 'c')
			conv->cara_c = 1;
		else if (*str == 's')
			conv->string_s = 1;
		else if (*str == 'p')
			conv->point_ad_hex_p = 1; // comme x avec 0x devant
		else if (*str == 'd')
			conv->int_dec_d = 1;
		else if (*str == 'i')
			conv->int_dec_i = 1;
		else if (*str == 'u')
			conv->unsd_int_u = 1;
		else if (*str == 'x')
			conv->unsd_hex_x = 1;
		else if (*str == 'X')
			conv->unsd_hex_X = 1;
		else if (*str == '%')
			conv->percent = 1;
	}
	afficher_struct_conv(*conv); //////////////////////////////////////////////
	return (1);
}

int ft_which_flag(const char *str, t_flags *flag)
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
				flag->widht = 1;
				while (*str == '*' || ft_is_digit(*str))
					str++;
				if ((*str == '.' && ft_is_digit(*str + 1))
				|| *(str + 1) == '*')
					flag->precision = 1;
			}
			str++;
		}
	}
	afficher_struct_flags(*flag);
	return (avancement -= ft_strlen(str));
}