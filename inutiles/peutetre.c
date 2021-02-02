/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peutetre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:04:57 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/01 16:07:11 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// peut-etre ??

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

int	ft_which_print(const char *str, t_conversion *conv)
{
	ft_init_struct_conversion(conv);
	if (str)
	{
		str++;
		while (ft_is_ntm(*str))
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

int		ft_check_flag(const char *str)
{
	str++;
	if (!ft_is_flag(*str) || !ft_is_conv(*str))
		return (-1);
	if (flag->minus == 1 && flag->padded_zero == 1)
		flag->padded_zero = -1;
	return (1);
}

/*typedef struct		ft_conversion
{
	int cara_c;
	int string_s;
	int point_ad_hex_p;
	int int_dec_d;
	int int_dec_i;
	int unsd_int_u;
	int unsd_hex_x;
	int unsd_hex_X;
	int percent;
}					t_conversion;*/



//int					ft_which_print(const char *str, t_conversion *conv);
//void				ft_init_struct_conversion(t_conversion *conv);