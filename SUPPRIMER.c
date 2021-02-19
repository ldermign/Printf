/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SUPPRIMER.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 09:02:26 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/19 09:08:04 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    printf_structure(t_flag_len *flag)
{
    printf("\n-------------------------------------\n");
    printf("minus = {%d}\n", flag->minus);
    printf("padded_zero = {%d}\n", flag->padded_zero);
    printf("width = {%d}\n", flag->width);
    printf("precision = {%d}\n", flag->precision);
    printf("nbr_width = {%d}\n", flag->nbr_width);
    printf("nbr_precision = {%d}\n", flag->nbr_precision);
    printf("str_precision = {%s}\n", flag->str_precision);
    printf("str_width = {%s}\n", flag->str_width);
    printf("final_str_flag = {%s}\n", flag->final_str_flag);
    printf("conv_u = {%d}\n", flag->conv_u);
    printf("conv_x = {%d}\n", flag->conv_x);
    printf("conv_per = {%d}\n", flag->conv_per);
    printf("-------------------------------------\n");
}