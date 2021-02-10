/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/10 21:46:54 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		which_conv(const char *str, va_list ap, t_flag_len *ntm)
{
//	to_flag(ap, ntm);
	if (*str == 'c')
		conv_c(ap, ntm);
	else if (*str == 's')
		conv_s(ap, ntm);
	else if (*str == 'p')
		conv_p(ap, ntm);
	else if (*str == 'd')
		conv_d_i(ap, ntm);
	else if (*str == 'i')
		conv_d_i(ap, ntm);
	else if (*str == 'u')
		conv_u(ap, ntm);
	else if (*str == 'x' || *str == 'X')
		conv_x_X(*str, ap, ntm);
	else if (*str == '%')
		conv_per(ntm);
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
	int				test_d_i;
	unsigned int	test_u;
	unsigned int	test_x_X;
	char 			*test_s;
	char			test_c;
	char			*test_p;

	test_d_i = 420;
	test_u = -428510;
	test_x_X = 0xFFFFFFFF;
	test_s = "pouet c'est relou";
	test_c = 'c';
	test_p = "nique ta race, adresse a la con, j'y arrive pas putain";
	printf(KCYN"\t//!\\\\MON PRINTF//!\\\\\n");
	printf("Taille retournee = %d.\n", ft_printf("Testons cette merde = %p, %d.\n", test_p, 123456789));
	printf(KGRN"\n\t//!\\\\VRAI PRINTF//!\\\\\n");
	printf("Taille retournee = %d.\n", printf("Testons cette merde = %p, %d.\n", test_p, 123456789));
	return (0);
}

/*
**	printf("On va tester cette merde = %u", -8); => underflow, unsdint
**	%[flag][min width][precision][length modifier][conversion specifier]
**	a regler :
**	conversion u
*/