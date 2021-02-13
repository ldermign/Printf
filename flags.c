/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:57:13 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/13 22:19:19 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    flag_precision(t_flag_len *flag)
{
    int     i;
    int     precision;
    
    i = 0;
    precision = flag->nbr_precision;
    if (!(flag->str_precision = malloc(sizeof(char) * (precision + 1))))
        return ;
    ft_fill_with_c(flag->str_precision, '0', precision + 1);
}

void    flag_width(t_flag_len *flag)
{
    int i;
    int width;

    i = 0;
    width = flag->nbr_width;
    if (!(flag->str_width = malloc(sizeof(char) * (width + 1))))
        return ;
    ft_fill_with_c(flag->str_width, ' ', width + 1);
}

// void flag_minus(t_flag_len *flag)
// {
// 	va_arg(ap, int);
//     (void)ntm;
// }
// char    *flag_padded_zero(t_flag_len *flag)
// {
// 	va_arg(ap, int);
//     (void)ntm;
// }
































void    ft_printf_monuq(t_flag_len ntm)
{
    printf("minus%d\n", ntm.minus);
    printf("padded_zero%d\n", ntm.padded_zero);
    printf("width%d\n", ntm.width);
    printf("precision%d\n", ntm.precision);
}