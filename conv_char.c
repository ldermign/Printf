/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:31:53 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/04 09:30:19 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    conv_s(va_list ap, t_struct flag)
{
    char *arg_char;

    arg_char = va_arg(ap, char *);
    ft_putstr(arg_char, &flag);
}

void    conv_c(va_list ap, t_struct flag)
{
    char cara;

    cara = va_arg(ap, int);
    ft_putchar(cara, &flag);
}

