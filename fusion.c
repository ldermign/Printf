/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:48:27 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/23 19:03:13 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_nbr_inf_zero(int place_space, int place_zero, t_flag_len *flag)
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
    // printf("pouet\n");
    // printf("width = {%d}\n", flag->nbr_width);
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

void    ft_final_size(int width, int prec, int len_str, t_flag_len *flag)
{
    if (len_str <= width && flag->precision == -1)
        flag->size_final_str_flag = width;
    else if ((len_str >= width && flag->precision == -1)
    || (len_str <= prec && flag->width == -1))
        flag->size_final_str_flag = len_str;
    else if (len_str > prec && flag->width == -1)
        flag->size_final_str_flag = prec;
    if (flag->precision == 1 && flag->width == 1)
    {
        if (width >= prec)
            flag->size_final_str_flag = width;
        if (prec > width)
        {
            if (width >= len_str)
                flag->size_final_str_flag = width;
            else if (prec >= len_str)
                flag->size_final_str_flag = len_str;
            else if (prec < len_str)
                flag->size_final_str_flag = prec;
        }
    }
}

int     which_is_smaller(int width, int prec, int len_str)
{
    // if (prec < 0)
    //     prec *= -1;
    if (width <= prec && width <= len_str && width != 0)
        return (width);
    else if (prec <= width && prec <= len_str && prec != 0)
        return(prec);
    return (len_str);
}

int    where_to_begin(int width, int prec, int len_str, t_flag_len *flag)
{
    int start;
    int min;
    
    start = 0;
    min = which_is_smaller(width, prec, len_str);
    // printf("which is smaller = {%d}, start = {%d}\n", min);
    if (flag->width == 1 && flag->precision == -1)
        start = flag->size_final_str_flag - min;
    else if (width > len_str && flag->precision == -1)
        start = flag->size_final_str_flag - min;
    else if (flag->width == 1 && flag->precision == 1)
    {
        if (width >= prec || (prec >= width && width >= len_str))
            start = flag->size_final_str_flag - min;
        else
            start = 0;
    }
    // printf("which is smaller = {%d}, start = {%d}\n", min, start);
    // printf("start = {%d}\n", start);
    return (start);
}

int     alloc_if_w_and_p(int width, int prec, int len_str, t_flag_len *flag)
{
    if (width >= prec)
    {
        if (!(flag->final_str_flag = ft_calloc(width + 1, sizeof(char))))
            return (0);
    }
    else if (prec > width)
    {
        if (width >= len_str)
        {
            if (!(flag->final_str_flag = ft_calloc(width + 1, sizeof(char))))
                return (0);
        }
        else if (prec >= len_str)
        {
            if (!(flag->final_str_flag = ft_calloc(len_str + 1, sizeof(char))))
                return (0);
        }
        else if (prec < len_str)
        {
            if (!(flag->final_str_flag = ft_calloc(prec + 1, sizeof(char))))
                return (0);
        }
    }
    return (1);
}

int    alloc_size(int width, int prec, int len_str, t_flag_len *flag)
{
    if (flag->precision == 1 && flag->width == 1)
    {
        if (alloc_if_w_and_p(width, prec, len_str, flag) == 0)
            return (0);
    }
    else if (flag->dot == 1 && prec == 0 && width > 0)
    {
        if (!(flag->final_str_flag = ft_calloc(width + 1, sizeof(char))))
            return (0);
        ft_fill_with_c(flag->final_str_flag, ' ', width + 1);
        return (0);
    }
    else if (len_str <= width && flag->precision == -1)
    {
        if (!(flag->final_str_flag = ft_calloc(width + 1, sizeof(char))))
            return (0);
    }
    else if ((len_str >= width && flag->precision == -1)
    || (len_str <= prec && flag->width == -1))
    {
        if (!(flag->final_str_flag = ft_calloc(len_str + 1, sizeof(char))))
            return (0);
    }
    else if ((len_str >= prec && flag->width == -1))
        if (!(flag->final_str_flag = ft_calloc(prec + 1, sizeof(char))))
            return (0);
    return (1);
}

void    fusion_s(char *str, int start, int last, t_flag_len *flag)
{
    int i;

    i = 0;
    // printf("precision = {%d}\n", flag->nbr_precision);
    // printf("last = {%d}\n", last);
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

void    prep_fusion_s(char *str, int width, int prec, int len_str, t_flag_len *flag)
{
    int start;
    int last;
    int ret;

    ret = prec;
    if (ret < 0)
		prec *= -1;
        // printf("prec = {%d}\n", prec);
    if (alloc_size(width, prec, len_str, flag) == 0)
        return ;
    ft_final_size(width, prec, len_str, flag);
    ft_fill_with_c(flag->final_str_flag, ' ', flag->size_final_str_flag + 1);
    start = where_to_begin(width, prec, len_str, flag);
    // printf("start = {%d}\n", start);
    if ((len_str >= prec && prec >= width) || flag->precision == -1
    || (prec >= len_str && len_str >= width))
        last = flag->size_final_str_flag;
    else if (len_str >= prec && width >= prec)
        last = prec;
    else
        last = which_is_smaller(width, prec, len_str);
    if (ret < 0)
        last = len_str;
    fusion_s(str, start, last, flag);
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
    // if (nbr < 0 && flag->minus == 1 && flag->nbr_precision < flag->nbr_width)
    //     last_seen++;
        // printf("last_seen = {%zu}\n", last_seen);
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
            // printf("place_zero = {%d}\n", place_zero);
    if (nbr == 0 && flag->dot == 1 && flag->nbr_precision == 0)
        str[0] = ' ';
    if (nbr < 0)
    {
        ft_nbr_inf_zero(place_space, place_zero, flag);
        if (flag->minus == 1 && flag->nbr_precision < flag->nbr_width)
            place_zero++;
    }
    if ((flag->minus == 1 && size_nbr && flag->precision == -1)
    || (flag->nbr_precision <= size_nbr && flag->precision == 1 && flag->minus == 1))
        place_zero = size_nbr;
        // place_zero++;
    // printf("place_zero = {%d}, size_nbr = {%d}\n", place_zero, size_nbr);
    while (size_nbr >= 0 && place_zero >= 0 && size_nbr-- && place_zero--)
    {
        // if (str[size_nbr] == '\0')
        //     size_nbr--;
        // printf("str[size_nbr] = {%c}\n", str[size_nbr]);
        if (str[size_nbr] != '\0' && (ft_is_digit(str[size_nbr])
        || (str[size_nbr] >= 'a' && str[size_nbr] <= 'z')
        || (str[size_nbr] >= 'A' && str[size_nbr] <= 'Z')))
            flag->final_str_flag[place_zero] = str[size_nbr];
        if (str[size_nbr] == '-' && flag->final_str_flag[place_zero] == ' ')
            flag->final_str_flag[place_zero] = str[size_nbr];
        // size_nbr--;
        // place_zero--;
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
		prep_fusion_s(str, flag->nbr_width, flag->nbr_precision, len_str, flag);
	else if (flag->conv_p == 1)
	 	fusion_p(str, flag->nbr_width, len_str, flag);
	else if (flag->conv_d_i == 1 || flag->conv_u == 1 || flag->conv_x == 1)
		fusion_d_i_u(str, nbr, flag);
}
