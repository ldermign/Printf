/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:48:27 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/15 22:16:59 by ldermign         ###   ########.fr       */
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

void    ft_fusion_minus(char *str, int nbr, t_flag_len *flag)
{
    (void)str;
    (void)nbr;
    (void)flag;
    int i;

    i = 0;
    // if (nbr < 0)
    
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

void    fusion_d_i(char *str, int nbr, t_flag_len *flag)
{
    (void)str;
    (void)nbr;
    (void)flag;
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
		fusion_d_i(str, nbr, flag);
	// else if (flag->conv_u == 1)
	// 	fusion_u(str, nbr, flag);
	// else if (flag->conv_x == 1)
	// 	fusion_x(str, nbr, flag);
	// else if (flag->conv_per == 1)
	// 	fusion_per(str, nbr, flag);


}

    // ft_fusion_preci_sup(str, nbr, flag);

// void    ft_fusion_preci_sup(char *str, int nbr, t_flag_len *flag)
// {
//     int     i;
//     len_t  size_str;
//     size_t  place_zero;
//     size_t  place_space;

//     i = 0;
//     size_str = ft_strlen(str);
//     place_zero = check_where_zero_or_space(flag, '0');
//     place_space = check_where_zero_or_space(flag, ' ');
//     if (place_zero != 0)
//     {
//         if (size_str < flag->size_final_str_flag)
//         {
//             while (size_str + 1 > 0)
//             {
//                 if (ft_is_digit(str[size_str]) && str[size_str] != '\0')
//                     flag->final_str_flag[place_zero] = str[size_str];
//                 size_str--;
//                 place_zero--;
//             }
//         }
//     }
//     if (nbr < 0 && flag->minus == 0)
//         flag->final_str_flag[place_space - 1] = '-';
// }
    // int i;
    // i = 0;
    // if (nbr < 0)
    // {
    //     if (flag->str_of_flag == NULL || flag->nbr_precision >= flag->nbr_width
    //     || (flag->nbr_precision >= flag->nbr_width && flag->padded_zero == 1))
    //         ft_putchar('-', flag);
    //     if (flag->minus == 1 && flag->precision > 0)
    //     {
    //         flag->final_str_flag[0] = '-';
    //         i = 1;
    //         while (i < flag->nbr_precision && i++)
    //             flag->final_str_flag[i] = '0';
    //     }
    // }