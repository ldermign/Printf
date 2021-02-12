/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:57:13 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/12 11:30:51 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void flag_minus(va_list ap, t_flag_len *ntm)
{
	va_arg(ap, int);
    (void)ntm;
}

void flag_padded_zero(va_list ap, t_flag_len *ntm)
{
	va_arg(ap, int);
    (void)ntm;
}

// void flag_width(va_list ap, t_flag_len *ntm)
// {
// 	int width;

//     width = va_arg(ap, int);
//     (void)ntm;
//     printf("WIDTH%dWIDTH", width);
// }

void flag_precision(va_list ap, t_flag_len *ntm)
{
	va_arg(ap, int);
    (void)ntm;
}


































void    ft_printf_monuq(t_flag_len ntm)
{
    printf("minus%d\n", ntm.minus);
    printf("padded_zero%d\n", ntm.padded_zero);
    printf("width%d\n", ntm.width);
    printf("precision%d\n", ntm.precision);
}