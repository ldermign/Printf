/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:31:53 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/23 19:28:36 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    conv_s(va_list ap, t_flag_len *flag)
{
    char	*arg_char;
	int		size_arg;

    arg_char = va_arg(ap, char *);
	size_arg = (int)ft_strlen(arg_char);
	if (arg_char == NULL || arg_char == 0)
		arg_char = "(null)";
    if (flag->nbr_width == 0 && flag->nbr_precision == 0 && flag->dot == 1)
        return ;
	else if (ft_no_flag(flag) || (flag->nbr_precision < 0 && flag->width == -1))
    	ft_putstr(arg_char, flag);
	else
	{
		fusion_conv_strflag(arg_char, 0, flag);
		ft_putstr(flag->final_str_flag, flag);
	}
}

void    conv_p(va_list ap, t_flag_len *flag)
{
	unsigned long 	arg_unsdint;
	void			*adresse_ptr;
	char			*temp;
	char			*str_adresse;

    adresse_ptr = va_arg(ap, void*);
	arg_unsdint = (unsigned long)(adresse_ptr);
	str_adresse = ft_itoa_base(arg_unsdint, "0123456789abcdef");
	temp = ft_strjoin("0x", str_adresse);
	if (ft_no_flag(flag) || flag->nbr_width < (int)ft_strlen(temp))
    	ft_putstr(temp, flag);
	else
	{
		fusion_conv_strflag(temp, ft_strlen(temp), flag);
		ft_putstr(flag->final_str_flag, flag);
	}
	free(str_adresse);
}

void    conv_d_i(va_list ap, t_flag_len *flag)
{
	int 	arg_int;
	int		size_temp;
	char	*temp;

    arg_int = va_arg(ap, int);
	temp = ft_itoa(arg_int);
	size_temp = ft_strlen(temp);
	if (flag->nbr_width == 0 && flag->nbr_precision == 0 && flag->dot == 1)
        return ;
	if ((size_temp >= flag->nbr_precision) && (size_temp >= flag->nbr_width))
		ft_putstr(temp, flag);
	else
	{
		fusion_conv_strflag(temp, arg_int, flag);
		ft_putstr(flag->final_str_flag, flag);
	}
	free(temp);
}

void    conv_c(va_list ap, t_flag_len *flag)
{
    int cara;
	
	cara = va_arg(ap, int);
	// printf("flag->nbr_width = {%d}\n", flag->nbr_width);
	// if (cara == '\0')
	// 	cara = '\x00';
	if (flag->nbr_width <= 1)
		ft_putchar(cara, flag);
	else
	{
		fusion_conv_strflag(NULL, cara, flag);
		if (cara > 31)
			ft_putstr(flag->final_str_flag, flag);
	}
}

void    conv_u(va_list ap, t_flag_len *flag)
{
	unsigned int 	arg_unsdint;
	int				size_temp;
	char			*temp;

    arg_unsdint = va_arg(ap, unsigned int);
	temp = ft_itoa_unsd(arg_unsdint);
	size_temp = ft_strlen(temp);
	if (arg_unsdint == 0
	&& ((flag->dot == 1 && flag->precision == -1 && flag->width == -1)
	|| (flag->dot == 1 && flag->precision == 1 && flag->width == -1)))
	// || (flag->dot == 1 && flag->width == -1 && flag->nbr_precision == 0))
        return ;
	if ((size_temp >= flag->nbr_precision) && (size_temp >= flag->nbr_width))
		ft_putstr(temp, flag);
	else
	{
		fusion_conv_strflag(temp, arg_unsdint, flag);
		ft_putstr(flag->final_str_flag, flag);
	}
	free(temp);
}

void	conv_x_X(char c, va_list ap, t_flag_len *flag)
{
	unsigned int	arg_unsdint;
	int				size_temp;
	char			*base;
	char			*temp;

	arg_unsdint = va_arg(ap, unsigned int);
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	temp = ft_itoa_base(arg_unsdint, base);
	size_temp = ft_strlen(temp);
	if (arg_unsdint == 0
	&& ((flag->dot == 1 && flag->precision == -1 && flag->width == -1)
	|| (flag->dot == 1 && flag->precision == 1 && flag->width == -1)))
	// || (flag->dot == 1 && flag->width == -1 && flag->nbr_precision == 0))
        return ;
	if ((size_temp >= flag->nbr_precision) && (size_temp >= flag->nbr_width))
		ft_putstr(temp, flag);
	else
	{
		fusion_conv_strflag(temp, arg_unsdint, flag);
		ft_putstr(flag->final_str_flag, flag);
	}
	free (temp);
}

void    conv_per(t_flag_len *flag)
{
	const int	charac = '%';

	if ((1 >= flag->nbr_precision) && (1 >= flag->nbr_width))
		ft_putstr("%", flag);
	else
	{
		fusion_conv_strflag(NULL, charac, flag);
		ft_putstr(flag->final_str_flag, flag);
	}
}	