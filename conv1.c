/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:31:53 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/13 13:57:25 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    conv_c(char *str_flag, va_list ap, t_flag_len *flag)
{
	str_flag = NULL;
    char cara;

    cara = va_arg(ap, int);
    ft_putchar(cara, flag);
}

void    conv_s(char *str_flag, va_list ap, t_flag_len *flag)
{
	str_flag = NULL;
    char	*arg_char;

    arg_char = va_arg(ap, char *);
    ft_putstr(arg_char, flag);
}

void    conv_p(char *str_flag, va_list ap, t_flag_len *flag)
{
	str_flag = NULL;
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
    int 	arg_int;

	str_flag = NULL;
    arg_int = va_arg(ap, int);
	temp = ft_itoa(arg_int);
	ft_putstr(temp, flag);
}
	// char	*strconv_flags;
	// int		size_str_flag;
	// int		size_str_ap;
	// size_str_flag = ft_strlen(str_flag);
	// size_str_ap = ft_strlen(temp);
	// if (size_str_flag < size_str_ap)
	// 	strconv_flags = ft_itoa(arg_int);
	// if (size_str_flag > size_str_ap)
	// {
	// 	strconv_flags = str_flag;
	// 	if (arg_int < 0 && flag->padded_zero == 1)
	// 		strconv_flags[0] = '-';
	// 	while (size_str_ap >= 0)
	// 	{
	// 		strconv_flags[size_str_flag] = temp[size_str_ap];
	// 		size_str_flag--;
	// 		size_str_ap--;
	// 		if (!ft_is_digit(temp[size_str_ap]) && flag->padded_zero == 1)
	// 		 	break ;
	// 	}

	// }
	// ft_putstr(strconv_flags, flag);
	// if (temp)
	// 	free(temp);
	// if (strconv_flags)
	// 	free(strconv_flags);

void    conv_u(char *str_flag, va_list ap, t_flag_len *flag)
{
	str_flag = NULL;
    unsigned int 	arg_unsdint;

    arg_unsdint = va_arg(ap, unsigned int);
	ft_putnbr(arg_unsdint, flag);
}

void	conv_x_X(char *str_flag, char c, va_list ap, t_flag_len *len)
{
	str_flag = NULL;
	unsigned int	arg_unsdint;
	char			*base;

//	int size_arg;
//	char *temp;

	arg_unsdint = va_arg(ap, unsigned int);

//	temp = ft_itoa(arg_unsdint);
	
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
//	size_arg = ft_strlen(temp);
	ft_putnbr_base_printf(arg_unsdint, base, len);
}

void    conv_per(char *str_flag, t_flag_len *flag)
{
	str_flag = NULL;
    ft_putstr("\%", flag);
}
