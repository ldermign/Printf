/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/13 18:58:27 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		which_conv(const char *str, va_list ap, t_flag_len *ntm)
{
	char *str_conv_to_flags;

	str_conv_to_flags = to_flag((char*)str, ap, ntm);
	if (*str == 'c')
		conv_c(str_conv_to_flags, ap, ntm);
	else if (*str == 's')
		conv_s(str_conv_to_flags, ap, ntm);
	else if (*str == 'p')
		conv_p(str_conv_to_flags, ap, ntm);
	else if (*str == 'd')
		conv_d_i(str_conv_to_flags, ap, ntm);
	else if (*str == 'i')
		conv_d_i(str_conv_to_flags, ap, ntm);
	else if (*str == 'u')
		conv_u(str_conv_to_flags, ap, ntm);
	else if (*str == 'x' || *str == 'X')
		conv_x_X(str_conv_to_flags, *str, ap, ntm);
	else if (*str == '%')
		conv_per(str_conv_to_flags, ntm);
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
			if (!ft_check_flag(&str[i]))
			 	return (ntm.final_len);
			i += which_flag(&str[i], &ntm);
			if (ft_is_all(str[i]))
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

void	check_printf(int size_ft_printf, int size_printf)
{
	if (size_ft_printf == size_printf)
		printf(KGRN"OK\n");
	else
		printf(KRED"KO\n");
}

int		main()
{
	// int				test_d_i = -8372;
	// unsigned int	test_u = 42;
	// unsigned int	test_x_X = 420;
	// char 			*test_s = "pouet c'est relou";
	// char			test_c = 'q';
	// int				test_adresse_p = 9999999;
	// int				*test_p = &test_adresse_p;

	// printf(KCYN"\t\t//!\\\\MON PRINTF//!\\\\\n");
	// printf(KGRE"Taille pour test d/i = %d.\n", ft_printf(KCYN"Quelque chose d --------------> [d : %15d].\n", test_d_i));
	// printf(KGRE"Taille pour test c = %d.\n", ft_printf(KCYN"Quelque chose c --------------> [%c].\n", test_c));
	// printf(KGRE"Taille pour test s = %d.\n", ft_printf(KCYN"Quelque chose s --------------> [%s].\n", test_s));
	// printf(KGRE"Taille pour test p = %d.\n", ft_printf(KCYN"Quelque chose p --------------> [%p].\n", test_p));
	// printf(KGRE"Taille pour test d/i = %d.\n", ft_printf(KCYN"Quelque chose d & i ----------> [d : %8.3d] & [i : %i].\n", test_d_i, test_d_i));
	// printf(KGRE"Taille pour test u = %d.\n", ft_printf(KCYN"Quelque chose u --------------> [%u].\n", test_u));
	// printf(KGRE"Taille pour test x et X = %d.\n", ft_printf(KCYN"Quelque chose x & X ----------> [x : %x] & [X : %X].\n", test_x_X, test_x_X));
	// printf(KGRE"Taille pour test percent = %d.\n", ft_printf(KCYN"Quelque chose percent --------> [%%].\n"));
	// printf(KGRN"\n\t\t//!\\\\VRAI PRINTF//!\\\\\n");
	// printf(KGRE"Taille pour test d/i = %d.\n", printf(KGRN"Quelque chose d --------------> [d : %15d].\n", test_d_i));
	// printf(KGRE"Taille pour test c = %d.\n", printf(KGRN"Quelque chose c --------------> [%c].\n", test_c));
	// printf(KGRE"Taille pour test s = %d.\n", printf(KGRN"Quelque chose s --------------> [%s].\n", test_s));
	// printf(KGRE"Taille pour test p = %d.\n", printf(KGRN"Quelque chose p --------------> [%p].\n", test_p));
	// printf(KGRE"Taille pour test d/i = %d.\n", printf(KGRN"Quelque chose d & i ----------> [d : %8.3d] & [i : %i].\n", test_d_i, test_d_i));
	// printf(KGRE"Taille pour test u = %d.\n", printf(KGRN"Quelque chose u --------------> [%u].\n", test_u));
	// printf(KGRE"Taille pour test x et X = %d.\n", printf(KGRN"Quelque chose x & X ----------> [x : %x] & [X : %X].\n", test_x_X, test_x_X));
	// printf(KGRE"Taille pour test percent = %d.\n", ft_printf(KGRN"Quelque chose percent --------> [%%].\n"));

	//test flags

	int test1 = 765;
	int test2 = -765;
	int size_ft_printf;
	int size_printf;
	
	write (1, "\n", 1);
	size_ft_printf = ft_printf(KCYN"positif [030.20] -------> [d : %-*.*d].\n", 30, 20, test1);
	size_printf = printf(KGRN"positif [030.20] -------> [d : %0*.*d].\n", 30, 20, test1);
	check_printf(size_ft_printf, size_printf);
	write (1, "\n", 1);
	size_ft_printf = ft_printf(KCYN"negatif [010] ----------> [d : %010d].\n", test2);
	size_printf = printf(KGRN"negatif [010] ----------> [d : %010d].\n", test2);
	check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [01] -----------> [d : %01d].\n", test1);
	// size_printf = printf(KGRN"positif [01] -----------> [d : %01d].\n", test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [01] -----------> [d : %01d].\n", test2);
	// size_printf = printf(KGRN"negatif [01] -----------> [d : %01d].\n", test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [-10] ----------> [d : %-10d].\n", test1);
	// size_printf = printf(KGRN"positif [-10] ----------> [d : %-10d].\n", test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [-10] ----------> [d : %-10d].\n", test2);
	// size_printf = printf(KGRN"negatif [-10] ----------> [d : %-10d].\n", test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [-1] -----------> [d : %-1d].\n", test1);
	// size_printf = printf(KGRN"positif [-1] -----------> [d : %-1d].\n", test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [-1] -----------> [d : %-1d].\n", test2);
	// size_printf = printf(KGRN"negatif [-1] -----------> [d : %-1d].\n", test2);
	// check_printf(size_ft_printf, size_printf);
	
	return (0);
	}


/*
**	printf("On va tester cette merde = %u", -8); => underflow, unsdint
**	%[flag][min width][precision][length modifier][conversion specifier]
**	a regler :
**	conversion p
*/