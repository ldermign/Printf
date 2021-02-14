/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:48:27 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/14 19:41:33 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t     check_if_zero_in_str(t_flag_len *flag)
{
    size_t last_seen;

    last_seen = 0;
    while (flag->final_str_flag[last_seen])
    {
        while (flag->final_str_flag[last_seen] != '0')
            last_seen++;
        while (flag->final_str_flag[last_seen] == '0')
            last_seen++;
        if (flag->final_str_flag[last_seen] != '0')
            break ;
    }
    return (last_seen);
}

void    fusion_conv_strflag(char *str, int nbr, t_flag_len *flag)
{
    int     i;
    size_t  size_str;
    size_t  place_zero;

    i = 0;
    size_str = ft_strlen(str);
    place_zero = check_if_zero_in_str(flag);
    if (nbr < 0)
    {
        if (flag->str_of_flag == NULL || flag->nbr_precision >= flag->nbr_width
        || (flag->nbr_precision >= flag->nbr_width && flag->padded_zero == 1))
        {
            ft_putchar('-', flag);
            nbr *= -1;
        }
    }
    if (place_zero != 0)
    {
        if (size_str < flag->size_final_str_flag)
        { 
            place_zero--;
            size_str--;
            while (size_str >= 0)
            {
                printf("final_str_flag place_zero = {%c}\n", flag->final_str_flag[place_zero]);
                // flag->final_str_flag[place_zero] = str[size_str];
                printf("test\n");
                place_zero--;
                size_str--;
            }



            
            printf("final_str_flag place_zero = {%c}\n", flag->final_str_flag[place_zero]);
            // printf("str size_str = {%c}\n", str[size_str]);
            // printf("zero = {%zu}\n", place_zero);
            // printf("final_str_flag = {%s}\n", flag->final_str_flag);
        }
    }
    // printf("place_zero = {%zu}\n", place_zero);
    // printf("final_str_flag = {%s}\n", flag->final_str_flag);
}