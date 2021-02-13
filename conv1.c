/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:31:53 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/13 23:55:46 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    conv_c(char *str_flag, va_list ap, t_flag_len *flag)
{
    char cara;

    cara = va_arg(ap, int);
    ft_putchar(cara, flag);
}

void    conv_s(char *str_flag, va_list ap, t_flag_len *flag)
{
    char	*arg_char;

    arg_char = va_arg(ap, char *);
    ft_putstr(arg_char, flag);
}

void    conv_p(char *str_flag, va_list ap, t_flag_len *flag)
{
	unsigned long 	arg_unsdint;
	void			*adresse_ptr;

    adresse_ptr = va_arg(ap, void*);
	arg_unsdint = (unsigned long)(adresse_ptr);
	ft_putstr("0x", flag);
	ft_putnbr_adr(arg_unsdint, flag);
}

void    conv_d_i(char *str_flag, va_list ap, t_flag_len *flag)
{
	char	*temp;
	char	*final_conv;
    int 	arg_int;

    arg_int = va_arg(ap, int);
	temp = ft_itoa(arg_int);
	final_conv = fusion_conv_strflag(temp, arg_int, flag);
	ft_putstr(temp, flag);
}

void    conv_u(char *str_flag, va_list ap, t_flag_len *flag)
{
    unsigned int 	arg_unsdint;

    arg_unsdint = va_arg(ap, unsigned int);
	ft_putnbr(arg_unsdint, flag);
}

void	conv_x_X(char *str_flag, char c, va_list ap, t_flag_len *len)
{
	unsigned int	arg_unsdint;
	char			*base;
	
	arg_unsdint = va_arg(ap, unsigned int);
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	ft_putnbr_base_printf(arg_unsdint, base, len);
}

void    conv_per(char *str_flag, t_flag_len *flag)
{
	str_flag = NULL;
    ft_putstr("\%", flag);
}
