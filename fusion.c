/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:48:27 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/14 22:33:27 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t     check_where_zero_or_space(t_flag_len *flag, char c)
{
    size_t last_seen;

    last_seen = 0;
    while (flag->final_str_flag[last_seen])
    {
        while (flag->final_str_flag[last_seen] != c)
            last_seen++;
        while (flag->final_str_flag[last_seen] == c)
            last_seen++;
        if (flag->final_str_flag[last_seen] != c)
            break ;
    }
    return (last_seen);
}

void    ft_fusion_preci_sup(char *str, int nbr, t_flag_len *flag)
{
    int     i;
    size_t  size_str;
    size_t  place_zero;
    size_t  place_space;

    i = 0;
    size_str = ft_strlen(str);
    place_zero = check_where_zero_or_space(flag, '0');
    place_space = check_where_zero_or_space(flag, ' ');
    if (place_zero != 0)
    {
        if (size_str < flag->size_final_str_flag)
        {
            while (size_str + 1 > 0)
            {
                if (ft_is_digit(str[size_str]) && str[size_str] != '\0')
                    flag->final_str_flag[place_zero] = str[size_str];
                size_str--;
                place_zero--;
            }
        }
    }
    if (nbr < 0 && flag->minus == 0)
        flag->final_str_flag[place_space - 1] = '-';
}

void    ft_fusion_minus(char *str, int nbr, t_flag_len *flag)
{
    (void)str;
    (void)nbr;
    (void)flag;
    int i;

    i = 0;
    // if (nbr < 0)
    
}


void    fusion_conv_strflag(char *str, int nbr, t_flag_len *flag)
{
    (void)str;
    int i;

    i = 0;
    if (nbr < 0)
    {
        if (flag->str_of_flag == NULL || flag->nbr_precision >= flag->nbr_width
        || (flag->nbr_precision >= flag->nbr_width && flag->padded_zero == 1))
            ft_putchar('-', flag);
        if (flag->minus == 1 && flag->precision > 0)
        {
            flag->final_str_flag[0] = '-';
            i = 1;
            while (i < flag->nbr_precision && i++)
                flag->final_str_flag[i] = '0';
        }
    }
    ft_fusion_preci_sup(str, nbr, flag);
}