/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:57:13 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/09 11:45:46 by ldermign         ###   ########.fr       */
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

void flag_width(va_list ap, t_flag_len *ntm)
{
	int width;

    width = va_arg(ap, int);
    (void)ntm;
    printf("WIDTH%dWIDTH", width);
}

void flag_precision(va_list ap, t_flag_len *ntm)
{
	va_arg(ap, int);
    (void)ntm;
}