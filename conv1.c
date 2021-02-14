/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:31:53 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/14 23:14:59 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    conv_c(va_list ap, t_flag_len *flag)
{
	// juste la largeur
    char cara;

    cara = va_arg(ap, int);
	// if (flag->padded_zero == 0)
	// 	flag sinon, non
    ft_putchar(cara, flag);
}

void    conv_s(va_list ap, t_flag_len *flag)
{
	// juste pas 0
    char	*arg_char;

    arg_char = va_arg(ap, char *);
    ft_putstr(arg_char, flag);
}

void    conv_p(va_list ap, t_flag_len *flag)
{
	// pour p, juste gerer la largeur et le minus
	unsigned long 	arg_unsdint;
	void			*adresse_ptr;

    adresse_ptr = va_arg(ap, void*);
	arg_unsdint = (unsigned long)(adresse_ptr);
	ft_putstr("0x", flag);
	ft_putnbr_adr(arg_unsdint, flag);
}

void    conv_d_i(va_list ap, t_flag_len *flag)
{
	char	*temp;
    int 	arg_int;

    arg_int = va_arg(ap, int);
	temp = ft_itoa(arg_int);
	if (flag->size_final_str_flag < ft_strlen(temp))
		ft_putstr(temp, flag);
	else
	{
		fusion_conv_strflag(temp, arg_int, flag);
		ft_putstr(flag->final_str_flag, flag);
	}
}

void    conv_u(va_list ap, t_flag_len *flag)
{
	char			*temp;
    unsigned int 	arg_unsdint;

    arg_unsdint = va_arg(ap, unsigned int);
	temp = ft_itoa(arg_unsdint);
	if (flag->size_final_str_flag < ft_strlen(temp))
		ft_putstr(temp, flag);
	else
	{
		fusion_conv_strflag(temp, arg_unsdint, flag);
		ft_putstr(flag->final_str_flag, flag);
	}
}

void	conv_x_X(char c, va_list ap, t_flag_len *len)
{
	// tous les flags :/
	unsigned int	arg_unsdint;
	char			*base;
	
	arg_unsdint = va_arg(ap, unsigned int);
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	ft_putnbr_base_printf(arg_unsdint, base, len);
}

void    conv_per(t_flag_len *flag)
{
	// tous les flags ce batard
	
    // ft_putstr("\%", flag);
	if (flag->size_final_str_flag < ft_strlen("\%"))
		ft_putstr("\%", flag);
	else
	{
		fusion_conv_strflag("\%", 0, flag);
		ft_putstr(flag->final_str_flag, flag);
	}
}
