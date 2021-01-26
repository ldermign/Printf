/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/26 11:34:26 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	afficher_flags_struct(t_flags flags)
	//simplement afficher la structure en fonction du flag
{
	printf("\nStructure = \n");
	printf("	minus = %d\n", flags.minus);
	printf("	padded_zero = %d\n", flags.padded_zero);
	printf("	widht = %d\n", flags.widht);
	printf("	precision = %d\n", flags.precision);
}

void	ft_init_struct_conversion(t_conversion *conv)
{
	conv->cara_c = 0;
	conv->string_s = 0;
	conv->point_ad_p = 0;
	conv->int_deci_d = 0;
	conv->int_deci_hexa_i = 0;
	conv->unsd_int_u = 0;
	conv->unsd_hexa_x = 0;
	conv->unsd_hexa_X = 0;
}

void	ft_init_struct_flag(t_flags *flag)
{
	flag->minus = 0;
	flag->padded_zero = -1;
	flag->widht = 0;
	flag->precision = 0;
}

void	ft_which_conv(char c)
{
	t_conversion *conv;

	conv = NULL;
	ft_init_struct_conversion(conv);
	if (c == 'c')
		conv->cara_c = 1;
	else if (c == 's')
		conv->string_s = 1;
	else if (c == 'p')
		conv->point_ad_p = 1;
	else if (c == 'd')
		conv->int_deci_d = 1;
	else if (c == 'i')
		conv->int_deci_hexa_i = 1;
	else if (c == 'u')
		conv->unsd_int_u = 1;
	else if (c == 'x')
		conv->unsd_hexa_x = 1;
	else if (c == 'X')
		conv->unsd_hexa_X = 1;
}

char	*ft_which_flag(const char *str, t_flags *flag)
{
	ft_init_struct_flag(flag);
	if (str)
	{
		str++;
		while (*str == '-' || *str == '0' || *str == '*'
		|| (*str >= '0' && *str <= '9'))
		{
			if (*str == '-')
				flag->minus = 1;
			if (*str == '0')
				flag->padded_zero = 1;
			if ((*str >= '0' && *str <= '9') || *str == '*' || *str == '.')
			{
				flag->widht = 1;
				while ((*str >= '0' && *str <= '9') || *str == '*')
					str++;
				if (*str == '.' && ((*(str + 1) >= '0' && *(str + 1) <= '9')
				|| *(str + 1) == '*'))
					flag->precision = 1;
			}
			str++;
		}
	}
	return (&str);
}


int		ft_printf(const char *str, ...)
{ 
	int	i;

	i = 0;
	va_list ap;
	va_start (ap, str);
	t_flags flags;
	while (str[i])
	{
		if (str[i] == '%' && str[i] != '\0')
		{
			ft_which_flag(&str[i], &flags);
			afficher_flags_struct(flags); /////////////////////////////////////
			if (str[i] == 'c' || str[i] == 's' || str[i] == 'p'
			|| str[i] == 'd' || str[i] == 'i' || str[i] == 'u' || str[i] == 'x'
			|| str[i] == 'X')
				ft_which_conv(&str[i]);
	//		va_arg(ap, str);
		}
		if (str[i] != '%')
			ft_putchar(str[i]);	
		i++;
	}
	va_end(ap);
	return (ft_strlen((char*)str));
}

int		main()
{
	int test_d;

	test_d = 42;
	ft_printf("On va tester cette merde = %d", 8);
	printf("On va tester cette merde = %d", 8);
//	printf("%# -10.1d", -8, 10);
	return (0);
}

