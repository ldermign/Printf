/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:31:53 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/05 12:05:57 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    conv_s(va_list ap, t_flag_len flag)
{
    char *arg_char;

    arg_char = va_arg(ap, char *);
    ft_putstr(arg_char, &flag);
}

void    conv_c(va_list ap, t_flag_len flag)
{
    char cara;

    cara = va_arg(ap, int);
    ft_putchar(cara, &flag);
}

void    conv_per(t_flag_len flag)
{
    ft_putstr("\%", &flag);
}


void    conv_d_i(va_list ap, t_flag_len flag)
{
    int arg_int;
	char *temp;

    arg_int = va_arg(ap, int);
	temp = ft_itoa(arg_int);
	ft_putstr(temp, &flag);
	free(temp);
}
