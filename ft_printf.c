/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/14 10:13:25 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		which_conv(const char *str, va_list ap, t_flag_len *flag)
{
	string_of_flags(ap, flag);
	printf("{{{{%c}}}}", *str);
	if (*str == 'c')
		conv_c(ap, flag);
	else if (*str == 's')
		conv_s(ap, flag);
	else if (*str == 'p')
		conv_p(ap, flag);
	else if (*str == 'd')
		conv_d_i(ap, flag);
	else if (*str == 'i')
		conv_d_i(ap, flag);
	else if (*str == 'u')
		conv_u(ap, flag);
	else if (*str == 'x' || *str == 'X')
		conv_x_X(*str, ap, flag);
	else if (*str == '%')
		conv_per(flag);
	return (1);
}

int		chaipas(const char *str, va_list ap)
{
	t_flag_len	flag;
	int			i;

	i = 0;
	flag.final_len = 0;
	while (str[i])
	{
		if (str[i] == '%' && ++i)
		{
			if (!ft_check_flag(&str[i]))
			 	return (flag.final_len);
			i += which_flag(&str[i], &flag);
			if (ft_is_conv(str[i]))
				i += which_conv(&str[i], ap, &flag);
		}
		else if (str[i] != '%')
		{
			ft_putchar(str[i], &flag);
			i++;
		}
	}
	return (flag.final_len);
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
	// int test2 = -765;
	int size_ft_printf;
	int size_printf;
	
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [20.10] -------> [d : %*.*d].\n", 20, 10, test1);
	// size_printf = printf(KGRN"positif [20.10] -------> [d : %*.*d].\n", 20, 10, test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [10.20] -------> [d : %*.*d].\n", 10, 20, test1);
	// size_printf = printf(KGRN"positif [10.20] -------> [d : %*.*d].\n", 10, 20, test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [10.10] -------> [d : %*.*d].\n", 10, 10, test1);
	// size_printf = printf(KGRN"positif [10.10] -------> [d : %*.*d].\n", 10, 10, test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);

	size_ft_printf = ft_printf(KCYN"positif [-20.10] -------> [d : %-*.*d].\n", 20, 10, test1);
	size_printf = printf(KGRN"positif [-20.10] -------> [d : %-*.*d].\n", 20, 10, test1);
	check_printf(size_ft_printf, size_printf);
	write (1, "\n", 1);
	size_ft_printf = ft_printf(KCYN"positif [-10.20] -------> [d : %-*.*d].\n", 10, 20, test1);
	size_printf = printf(KGRN"positif [-10.20] -------> [d : %-*.*d].\n", 10, 20, test1);
	check_printf(size_ft_printf, size_printf);
	write (1, "\n", 1);
	size_ft_printf = ft_printf(KCYN"positif [-10.10] -------> [d : %-*.*d].\n", 10, 10, test1);
	size_printf = printf(KGRN"positif [-10.10] -------> [d : %-*.*d].\n", 10, 10, test1);
	check_printf(size_ft_printf, size_printf);
	write (1, "\n", 1);

	
	// size_ft_printf = ft_printf(KCYN"negatif [20.10] -------> [d : %*.*d].\n", 20, 10, test2);
	// size_printf = printf(KGRN"negatif [20.10] -------> [d : %*.*d].\n", 20, 10, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [10.20] -------> [d : %*.*d].\n", 10, 20, test2);
	// size_printf = printf(KGRN"negatif [10.20] -------> [d : %*.*d].\n", 10, 20, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [10.10] -------> [d : %*.*d].\n", 10, 10, test2);
	// size_printf = printf(KGRN"negatif [10.10] -------> [d : %*.*d].\n", 10, 10, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [020.10] -------> [d : %0*.*d].\n", 20, 10, test1);
	// size_printf = printf(KGRN"positif [020.10] -------> [d : %0*.*d].\n", 20, 10, test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [010.20] -------> [d : %0*.*d].\n", 10, 20, test1);
	// size_printf = printf(KGRN"positif [010.20] -------> [d : %0*.*d].\n", 10, 20, test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"positif [010.10] -------> [d : %0*.*d].\n", 10, 10, test1);
	// size_printf = printf(KGRN"positif [010.10] -------> [d : %0*.*d].\n", 10, 10, test1);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [020.10] -------> [d : %0*.*d].\n", 20, 10, test2);
	// size_printf = printf(KGRN"negatif [020.10] -------> [d : %0*.*d].\n", 20, 10, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [010.20] -------> [d : %0*.*d].\n", 10, 20, test2);
	// size_printf = printf(KGRN"negatif [010.20] -------> [d : %0*.*d].\n", 10, 20, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [010.10] -------> [d : %0*.*d].\n", 10, 10, test2);
	// size_printf = printf(KGRN"negatif [010.10] -------> [d : %0*.*d].\n", 10, 10, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// write (1, "\n", 1);



	// size_ft_printf = ft_printf(KCYN"negatif [-20.10] -------> [d : %-*.*d].\n", 20, 10, test2);
	// size_printf = printf(KGRN"negatif [-20.10] -------> [d : %-*.*d].\n", 20, 10, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [-10.20] -------> [d : %-*.*d].\n", 10, 20, test2);
	// size_printf = printf(KGRN"negatif [-10.20] -------> [d : %-*.*d].\n", 10, 20, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// size_ft_printf = ft_printf(KCYN"negatif [-10.10] -------> [d : %-*.*d].\n", 10, 10, test2);
	// size_printf = printf(KGRN"negatif [-10.10] -------> [d : %-*.*d].\n", 10, 10, test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
	// 	size_ft_printf = ft_printf(KCYN"negatif [10] ----------> [d : %10d].\n", test2);
	// size_printf = printf(KGRN"negatif [10] ----------> [d : %10d].\n", test2);
	// check_printf(size_ft_printf, size_printf);
	// write (1, "\n", 1);
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