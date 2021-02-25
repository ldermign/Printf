/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_strflag_conv_s_d_i_u.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:53:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/25 19:30:05 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int    ft_nbr_inf_zero(int space, int zero, int n, t_flag_len *flag)
{
    (void)n;
    if (flag->nbr_width <= flag->nbr_precision)
    {
        ft_putchar('-', flag);
        return (1);
    }
    else if (flag->padded_zero == 1 && flag->precision == -1)
    {
        flag->final_str_flag[0] = '-';
        return (1);
    }
    else if (flag->nbr_precision < flag->nbr_width)
    {
        if (flag->minus == 0)
        {
            // if (n == 3)
            //     flag->final_str_flag[0] = '-';
            // else
                flag->final_str_flag[--space] = '-';
            return (1);
        }
        else if (flag->minus == 1 && flag->width == 1)
        {
            flag->final_str_flag[0] = '-';
            // printf("test\n");
            if (zero != (int)flag->size_final_str_flag && n < zero)
                flag->final_str_flag[zero] = '0';
            return (1);
        }
    }
    return (0);
}

size_t     check_where_zero_or_space(t_flag_len *flag, char c)
{
    size_t  last_seen;
    size_t  size;
    int     i;

    i = 0;
    last_seen = 0;
    size = flag->size_final_str_flag;
    if ((flag->final_str_flag[size - 1] == c
    && (flag->final_str_flag[0] == c || flag->final_str_flag[0] != c))
    || (flag->final_str_flag[size - 1] != c && flag->final_str_flag[0] != c))
       return (size);
    while (flag->final_str_flag[last_seen] == c)
        last_seen++;
    return (last_seen);
}

void    fusion_d_i_u(char *str, int nbr, t_flag_len *flag)
{
    int ret = 0;
    int     i;
    int     size_nbr;
    int     place_zero;
    int     place_space;

    i = 0;
    size_nbr = ft_strlen(str);
    join_str_width_and_precision(flag);
    place_zero = check_where_zero_or_space(flag, '0');
    place_space = check_where_zero_or_space(flag, ' ');
    // if (flag->nbr_precision < 0)
    // {
    //     // printf("test\n");
    //     flag->nbr_precision *= -1;
    // }
    if (flag->nbr_precision < 0)
        flag->precision *= -1;
    if (nbr == 0 && flag->dot == 1 && flag->nbr_precision == 0)
        str[0] = ' ';
    if (nbr < 0)
    {
        if (flag->minus == 1 && flag->nbr_precision < flag->nbr_width)
            place_zero++;
        ft_nbr_inf_zero(place_space, place_zero, size_nbr, flag);
    }
    if ((flag->minus == 1 && size_nbr && flag->precision == -1)
    || (flag->nbr_precision <= size_nbr
    && flag->precision == 1 && flag->minus == 1))
        place_zero = size_nbr;
    while (size_nbr >= 0 && place_zero >= 0 && size_nbr-- && place_zero--)
    {
        if (str[size_nbr] != '\0' && (ft_is_digit(str[size_nbr])
        || (str[size_nbr] >= 'a' && str[size_nbr] <= 'z')
        || (str[size_nbr] >= 'A' && str[size_nbr] <= 'Z')))
            flag->final_str_flag[place_zero] = str[size_nbr];
        if (str[size_nbr] == '-' && flag->final_str_flag[place_zero] == ' ')
        {
            flag->final_str_flag[place_zero] = str[size_nbr];
            ret = 1;
        }
    }
    // printf("ret = {%d}, nbr_width = {%d}, nbr_preci = {%d}, padd = {%d}, nbrlen = {%d}\n", ret, flag->nbr_width, flag->nbr_precision, flag->padded_zero, size_nbr);
    if (ret == 0 && flag->nbr_width > flag->nbr_precision
    && flag->padded_zero == 1 && size_nbr == 3)
    {
        // printf("test\n");
        flag->final_str_flag[0] = '-';
    }
}

void    fusion_s(char *str, int start, int last, t_flag_len *flag)
{
    int i;

    i = 0;
    if (flag->minus == 1)
    {
        start = 0;
        while (start < last && str[start] && flag->final_str_flag[start])
        {
            flag->final_str_flag[start] = str[start];
            start++;
        }
    }
    else
    {
        last = flag->size_final_str_flag;
        while (str[i] && flag->final_str_flag[start] && start <= last)
        {
            flag->final_str_flag[start] = str[i];
            i++;
            start++;
        }
    }
}