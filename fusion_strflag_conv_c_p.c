/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_strflag_conv_c_p.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:48:27 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/25 10:01:14 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_cara_non_imp(int nbr, t_flag_len *flag)
{
    if (flag->minus == 1)
    {
        ft_putchar(nbr, flag);
        while (flag->nbr_width > 1 && flag->nbr_width--)
            ft_putchar(' ', flag);
    }
    else
    {
        while (flag->nbr_width > 1 && flag->nbr_width--)
            ft_putchar(' ', flag);
        ft_putchar(nbr, flag);
    }
}

void    fusion_c(int nbr, t_flag_len *flag)
{
    if (flag->nbr_width > 1)
        if (!(flag->final_str_flag = ft_calloc(flag->nbr_width + 1, sizeof(char))))
            return ;
    if (flag->conv_per == 1 && flag->padded_zero == 1)
        ft_fill_with_c(flag->final_str_flag, '0', flag->nbr_width + 1);
    else
        ft_fill_with_c(flag->final_str_flag, ' ', flag->nbr_width + 1);
    if (nbr <= 31)
    {
        ft_cara_non_imp(nbr, flag);
        return ;
    }
    if (flag->minus == 1)
        flag->final_str_flag[0] = nbr;
    else
        flag->final_str_flag[flag->nbr_width - 1] = nbr;
    
}

void    fusion_p(char *str, int max, int len, t_flag_len *flag)
{
    int i;
    int start;

    i = 0;
    start = max - len;
    if (flag->nbr_width <= flag->nbr_precision)
    {
        start = 0;
        len = flag->nbr_precision;
    }
    if (!(flag->final_str_flag = ft_calloc(max + 1, sizeof(char))))
            return ;
    ft_fill_with_c(flag->final_str_flag, ' ', max + 1);
    if (flag->minus == 0)
    {
        while (str[i] && flag->final_str_flag[start] && start < max)
        {
            flag->final_str_flag[start] = str[i];
            i++;
            start++;
        }
    }
    else
    {
        while (i < len && str[i] && flag->final_str_flag[i])
        {
            flag->final_str_flag[i] = str[i];
            i++;
        }
    }
}

void    fusion_conv_strflag(char *str, int nbr, t_flag_len *flag)
{
    int len_str;

    len_str = ft_strlen(str);
    if ((flag->conv_c == 1 && flag->padded_zero == 0 && flag->precision == -1)
    || flag->conv_per == 1)
		fusion_c(nbr, flag);
	else if (flag->conv_s == 1 && flag->padded_zero == 0)
		prep_fus(str, flag->nbr_width, flag->nbr_precision, len_str, flag);
	else if (flag->conv_p == 1)
	 	fusion_p(str, flag->nbr_width, len_str, flag);
	else if (flag->conv_d_i == 1 || flag->conv_u == 1 || flag->conv_x == 1)
		fusion_d_i_u(str, nbr, flag);
}