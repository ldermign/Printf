/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_str_flag_str_conv.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:48:27 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/24 15:54:09 by ldermign         ###   ########.fr       */
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

void    ft_nbr_inf_zero(int place_space, int place_zero, t_flag_len *flag)
{
    if (flag->padded_zero == 1 && flag->precision == -1)
        flag->final_str_flag[0] = '-';
    if (flag->nbr_precision >= flag->nbr_width)
        ft_putchar('-', flag);
    else if (flag->nbr_precision < flag->nbr_width)
    {
        if (flag->minus == 0)
            flag->final_str_flag[--place_space] = '-';
        else if (flag->minus == 1 && flag->width == 1)
        {
            flag->final_str_flag[0] = '-';
            if (place_zero != (int)flag->size_final_str_flag)
                flag->final_str_flag[place_zero] = '0';
        }
    }
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
    int     i;
    int     size_nbr;
    int     place_zero;
    int     place_space;

    i = 0;
    size_nbr = ft_strlen(str);
    join_str_width_and_precision(flag);
    place_zero = check_where_zero_or_space(flag, '0');
    place_space = check_where_zero_or_space(flag, ' ');
    if (nbr == 0 && flag->dot == 1 && flag->nbr_precision == 0)
        str[0] = ' ';
    if (nbr < 0)
    {
        ft_nbr_inf_zero(place_space, place_zero, flag);
        if (flag->minus == 1 && flag->nbr_precision < flag->nbr_width)
            place_zero++;
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
            flag->final_str_flag[place_zero] = str[size_nbr];
    }
}
