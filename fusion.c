/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:48:27 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/16 22:53:44 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_nbr_inf_zero(int place_space, int place_zero, t_flag_len *flag)
{
    if (flag->nbr_precision >= flag->nbr_width)
        ft_putchar('-', flag);
    else if (flag->nbr_precision < flag->nbr_width)
    {
        if (flag->minus == 0)
            flag->final_str_flag[--place_space] = '-';
        else if (flag->minus == 1)
        {
            flag->final_str_flag[0] = '-';
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
       return (size - 1);
    while (flag->final_str_flag[last_seen] == c)
        last_seen++;
    return (last_seen);
}

void    fusion_c(int nbr, t_flag_len *flag)
{
    if (!(flag->final_str_flag = ft_calloc(flag->nbr_width + 1, sizeof(char))))
        return ;
    ft_fill_with_c(flag->final_str_flag, ' ', flag->nbr_width + 1);
    if (flag->minus == 1)
        flag->final_str_flag[0] = nbr;
    else
    flag->final_str_flag[flag->nbr_width - 1] = nbr;
}

void    fusion_s(char *str, int max, int len, t_flag_len *flag)
{
    int i;
    int start;

    i = 0;
    start = max - len;
    if ((flag->final_str_flag = ft_calloc(max + 1, sizeof(char))) == NULL)
        return ;
    ft_fill_with_c(flag->final_str_flag, ' ', max + 1);
    if (flag->minus == 1)
    {
        while (i < len && str[i] && flag->final_str_flag[i])
        {
            flag->final_str_flag[i] = str[i];
            i++;
        }
    }
    else 
    {
        while (start < max && str[i] && flag->final_str_flag[start])
        {
            flag->final_str_flag[start] = str[i];
            i++;
            start++;
        }
    }
}

void    fusion_d_i_u(char *str, int nbr, t_flag_len *flag)
{
    int     i;
    int     size_nbr;
    int     place_zero;
    int     place_space;

    i = 0;
    size_nbr = ft_strlen(str);
    join_str_width_and_precision(nbr, flag);
    place_zero = check_where_zero_or_space(flag, '0');
    place_space = check_where_zero_or_space(flag, ' ');
    // printf("{%s}\n", flag->final_str_flag);
    // printf("size str = {%zu}, place_zero = {%d}\n", flag->size_final_str_flag, place_zero);
    if (nbr == 0 && flag->nbr_precision != 0)
        str[0] = ' ';
    if (nbr < 0)
        ft_nbr_inf_zero(place_space, place_zero, flag);
    if (flag->nbr_precision < flag->nbr_width && flag->minus == 1)
        place_zero++;
    // printf("{%s}\n", flag->final_str_flag);
    size_nbr -= (nbr > 0);
    while (size_nbr >= 0 && place_zero > 0 && nbr != 0)
    {
        printf("{%s}\n", flag->final_str_flag);
        // printf("size str = {%d}, place_zero = {%d}\n", size_nbr, place_zero);
        if (str[size_nbr] != '\0' && ft_is_digit(str[size_nbr]))
            flag->final_str_flag[place_zero] = str[size_nbr];
        size_nbr--;
        place_zero--;
        // printf("test\n");
    }
    // printf("{%s}\n", flag->final_str_flag);
}

void    fusion_conv_strflag(char *str, int nbr, t_flag_len *flag)
{
    if (flag->conv_c == 1 && flag->padded_zero == 0 && flag->precision == -1)
		fusion_c(nbr, flag);
	else if (flag->conv_s == 1 && flag->padded_zero == 0)
		fusion_s(str, flag->nbr_width, flag->nbr_precision, flag);
	else if (flag->conv_p == 1)
	 	fusion_s(str, flag->nbr_width, nbr, flag);
	else if (flag->conv_d_i == 1)
		fusion_d_i_u(str, nbr, flag);
	else if (flag->conv_u == 1)
	 	fusion_d_i_u(str, nbr, flag);
	// else if (flag->conv_x == 1)
	// 	fusion_x(str, nbr, flag);
	// else if (flag->conv_per == 1)
	// 	fusion_per(str, nbr, flag);
}
