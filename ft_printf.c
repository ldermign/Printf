/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/07 14:46:56 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		which_conv(const char *str, va_list ap, t_flag_len *ntm)
{
//	to_flag(ap, ntm);
	if (*str == 'c')
		conv_c(ap, *ntm);
	else if (*str == 's')
		conv_s(ap, *ntm);
//	else if (*str == 'p')
//		conv_p(va_arg(ap, *ptr), ntm); // unsdint
	else if (*str == 'd')
		conv_d_i(ap, ntm);
	else if (*str == 'i')
		conv_d_i(ap, ntm);
//	else if (*str == 'u')
//		conv_d_u(va_arg(ap, int), ntm); // unsdint
//	else if (*str == 'x' || *str == 'X')
//		conv_x_X(va_arg(ap, int), ntm); // unsdint
	else if (*str == '%')
		conv_per(*ntm);
	return (1);
}

int		chaipas(const char *str, va_list ap)
{
	t_flag_len	ntm;
	int			i;

	i = 0;
	ntm.final_len = 0;
	while (str[i])
	{
		if (str[i] == '%' && ++i)
		{
			 if (!ft_check_flag(&str[i], &ntm))
			 	return (ntm.final_len);
			i += which_flag(&str[i], &ntm) + 1;
			if (ft_is_conv(str[i]))
				i += which_conv(&str[i], ap, &ntm);
		}
		else if (str[i] != '%')
		{
			ft_putchar(str[i], &ntm);
			i++;
		}
	}
	return (ntm.final_len);
}

int		ft_printf(const char *str, ...)
{
	int			final_length;

	va_list ap;

	va_start(ap, str);
	final_length = chaipas(str, ap);
	va_end(ap);
	return (final_length);
}

int		main()
{
	int		test_d;
	char 	*test_char;

	test_d = 420;
	test_char = "pouet";
	printf(KCYN"	//!\\\\MON PRINTF//!\\\\\n");
	printf("Taille retournee = %d.\n", ft_printf("Testons cette merde = %d.\n", test_d));
	printf(KGRN"\n	//!\\\\VRAI PRINTF//!\\\\\n");
	printf("Taille retournee = %d.\n", printf("Testons cette merde = %d.\n", test_d));
	return (0);
}

/*
**	printf("On va tester cette merde = %u", -8); => underflow, unsdint
**	a regler :
**	check_flag a revoir
**	caractere % pas compte ???????????? WTFFFFFFFF
*/