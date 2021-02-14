/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstructuASUPP.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:55:16 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/14 14:38:14 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    printf_structure(t_flag_len *flag)
{
    printf("\n---------------------------\n");
    printf("minus = {%d}\n", flag->minus);
    printf("padded_zero = {%d}\n", flag->padded_zero);
    printf("width = {%d}\n", flag->width);
    printf("precision = {%d}\n", flag->precision);
    printf("nbr_width = {%d}\n", flag->nbr_width);
    printf("nbr_precision = {%d}\n", flag->nbr_precision);
    printf("str_of_flag = {%s}\n", flag->str_of_flag);
    printf("str_precision = {%s}\n", flag->str_precision);
    printf("str_width = {%s}\n", flag->str_width);
    printf("final_str_flag = {%s}\n", flag->final_str_flag);
    printf("size_final_str_flag = {%zu}\n", flag->size_final_str_flag);
    printf("conv_c = {%d}\n", flag->conv_c);
    printf("conv_s = {%d}\n", flag->conv_s);
    printf("conv_p = {%d}\n", flag->conv_p);
    printf("conv_d_i = {%d}\n", flag->conv_d_i);
    printf("conv_u = {%d}\n", flag->conv_u);
    printf("conv_x = {%d}\n", flag->conv_x);
    printf("conv_per = {%d}\n", flag->conv_per);
    printf("---------------------------\n");
}

void    ft_printf_monuq(t_flag_len ntm)
{
    printf("minus%d\n", ntm.minus);
    printf("padded_zero%d\n", ntm.padded_zero);
    printf("width%d\n", ntm.width);
    printf("precision%d\n", ntm.precision);
}