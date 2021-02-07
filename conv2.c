/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:31:53 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/07 14:31:55 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    conv_s(va_list ap, t_flag_len flag)
{
    char *arg_char;

    arg_char = va_arg(ap, char *);
    printf("avant%d---", flag.final_len);
    ft_putstr(arg_char, &flag);
    printf("apres%d---", flag.final_len);
}

void    conv_c(va_list ap, t_flag_len flag)
{
    char cara;

    cara = va_arg(ap, int);
    printf("avant%d---", flag.final_len);
    ft_putchar(cara, &flag);
    printf("apres%d---", flag.final_len);
}

void    conv_per(t_flag_len flag)
{
    printf("avant%d---", flag.final_len);
    ft_putstr("\%", &flag);
    printf("apres%d---", flag.final_len);
}


void    conv_d_i(va_list ap, t_flag_len *flag)
{
    int arg_int;
	char *temp;

    arg_int = va_arg(ap, int);
    // printf("//avant%d---", flag->final_len);
    //ERR(__FILE__, __func__, __LINE__);
	temp = ft_itoa(arg_int);
	ft_putstr(temp, flag);
    // printf("%s: %zu\n", temp, ft_strlen(temp));
    // printf("apres%d---", flag->final_len);
	free(temp);
}
