/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_str_flag_str_conv_s.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:00:28 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/24 15:56:11 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     alloc_if_w_and_p(int width, int prec, int len_str, t_flag_len *flag)
{
    if (width >= prec || prec == 0)
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
    else if ((len_str <= width && flag->precision == -1)
    || (flag->dot == 1 && prec == 0 && width > 0))
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

void    ft_final_size(int width, int prec, int len_str, t_flag_len *flag)
{
    if ((len_str <= width && flag->precision == -1)
    || (flag->dot == 1 && prec == 0 && width > 0))
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

int    where_to_begin(int width, int prec, int len_str, t_flag_len *flag)
{
    int start;
    int min;
    
    start = 0;
    min = which_is_smaller(width, prec, len_str);
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
    return (start);
}


void    prep_fusion_s(char *str, int width, int prec, int len_str, t_flag_len *flag)
{
    int start;
    int last;
    int ret;

    ret = prec;
    if (ret < 0)
		prec *= -1;
    if (alloc_size(width, prec, len_str, flag) == 0)
        return ;
    ft_final_size(width, prec, len_str, flag);
    ft_fill_with_c(flag->final_str_flag, ' ', flag->size_final_str_flag + 1);
    if ((flag->precision == 1 && flag->nbr_precision == 0)
    || (flag->dot == 1 && prec == 0 && width > 0))
        return ;
    start = where_to_begin(width, prec, len_str, flag);
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
