/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:07:46 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/19 11:42:54 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_printf(int size_ft_printf, int size_printf)
{
	if (size_ft_printf == size_printf)
		printf(KGRN"OK\n");
	else
		printf(KRED"KO\n");
}

int main()
{

	unsigned int	test_u = 42;
	unsigned int	test_x_X = 666666;
	char 			*test_s = "pouet c'est relou";
	char				test_c = 'q';
	int				test_adresse_p = 9999999;
	int				*test_p = &test_adresse_p;
	int test1 = 765;
	int test2 = -765;
	int size_ft_printf;
	int size_printf;
	// d


	size_printf = printf(KGRN"c [10] -------> [%*c].\n", 10, test_c);
	size_ft_printf = ft_printf(KCYN"c [10] -------> [%*c].\n", 10, test_c);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"c [-10] ------> [%-*c].\n", 10, test_c);
	size_ft_printf = ft_printf(KCYN"c [-10] ------> [%-*c].\n", 10, test_c);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"s [30.10] -------> [%*.*s].\n", 30, 11, test_s);
	size_ft_printf = ft_printf(KCYN"s [30.10] -------> [%*.*s].\n", 30, 11, test_s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"s [-30.10] ------> [%-*.*s].\n", 30, 11, test_s);
	size_ft_printf = ft_printf(KCYN"s [-30.10] ------> [%-*.*s].\n", 30, 11, test_s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"s [10.30] -------> [%*.*s].\n", 11, 30, test_s);
	size_ft_printf = ft_printf(KCYN"s [10.30] -------> [%*.*s].\n", 11, 30, test_s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"s [-10.30] ------> [%-*.*s].\n", 11, 30, test_s);
	size_ft_printf = ft_printf(KCYN"s [-10.30] ------> [%-*.*s].\n", 11, 30, test_s);
	check_printf(size_ft_printf, size_printf);


	size_printf = printf(KGRN"p [30] -------> [%*.p].\n", 30, test_p);
	size_ft_printf = ft_printf(KCYN"p [30] -------> [%*.p].\n", 30, test_p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"p [-30] ------> [%-*p].\n", 30, test_p);
	size_ft_printf = ft_printf(KCYN"p [-30] ------> [%-*p].\n", 30, test_p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"p [6] -------> [%*p].\n", 6, test_p);
	size_ft_printf = ft_printf(KCYN"p [6] -------> [%*p].\n", 6, test_p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"p [-6] ------> [%-*p].\n", 6, test_p);
	size_ft_printf = ft_printf(KCYN"p [-6] ------> [%-*p].\n", 6, test_p);
	check_printf(size_ft_printf, size_printf);




	
	size_printf = printf(KGRN"positif [-10.5] -------> [d : %*.*d].\n", -10, 5, test1);
	size_ft_printf = ft_printf(KCYN"positif [-10.5] -------> [d : %*.*d].\n", -10, 5, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [10.20] -------> [d : %*.*d].\n", 10, 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [10.20] -------> [d : %*.*d].\n", 10, 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-10.20] ------> [d : %-*.*d].\n", 10, 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [-10.20] ------> [d : %-*.*d].\n", 10, 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [-10.20] ------> [d : %-*.*d].\n", 10, 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [-10.20] ------> [d : %-*.*d].\n", 10, 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [010.20] ------> [d : %0*.*d].\n", 10, 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [010.20] ------> [d : %0*.*d].\n", 10, 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [010.20] ------> [d : %0*.*d].\n", 10, 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [010.20] ------> [d : %0*.*d].\n", 10, 20, test2);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"positif [20.10] -------> [d : %*.*d].\n", 20, 10, test1);
	size_ft_printf = ft_printf(KCYN"positif [20.10] -------> [d : %*.*d].\n", 20, 10, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [20.10] -------> [d : %*.*d].\n", 20, 10, test2);
	size_ft_printf = ft_printf(KCYN"negatif [20.10] -------> [d : %*.*d].\n", 20, 10, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20.10] ------> [d : %-*.*d].\n", 20, 10, test1);
	size_ft_printf = ft_printf(KCYN"positif [-20.10] ------> [d : %-*.*d].\n", 20, 10, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [-20.10] ------> [d : %-*.*d].\n", 20, 10, test2);
	size_ft_printf = ft_printf(KCYN"negatif [-20.10] ------> [d : %-*.*d].\n", 20, 10, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020.10] ------> [d : %0*.*d].\n", 20, 10, test1);
	size_ft_printf = ft_printf(KCYN"positif [020.10] ------> [d : %0*.*d].\n", 20, 10, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [020.10] ------> [d : %0*.*d].\n", 20, 10, test2);
	size_ft_printf = ft_printf(KCYN"negatif [020.10] ------> [d : %0*.*d].\n", 20, 10, test2);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"positif [2.2] -------> [d : %*.*d].\n", 2, 2, test1);
	size_ft_printf = ft_printf(KCYN"positif [2.2] -------> [d : %*.*d].\n", 2, 2, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [2.2] -------> [d : %*.*d].\n", 2, 2, test2);
	size_ft_printf = ft_printf(KCYN"negatif [2.2] -------> [d : %*.*d].\n", 2, 2, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-2.2] ------> [d : %-*.*d].\n", 2, 2, test1);
	size_ft_printf = ft_printf(KCYN"positif [-2.2] ------> [d : %-*.*d].\n", 2, 2, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [-2.2] ------> [d : %-*.*d].\n", 2, 2, test2);
	size_ft_printf = ft_printf(KCYN"negatif [-2.2] ------> [d : %-*.*d].\n", 2, 2, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [02.2] ------> [d : %0*.*d].\n", 2, 2, test1);
	size_ft_printf = ft_printf(KCYN"positif [02.2] ------> [d : %0*.*d].\n", 2, 2, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [02.2] ------> [d : %0*.*d].\n", 2, 2, test2);
	size_ft_printf = ft_printf(KCYN"negatif [02.2] ------> [d : %0*.*d].\n", 2, 2, test2);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"positif [20.20] -------> [d : %*.*d].\n", 20, 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [20.20] -------> [d : %*.*d].\n", 20, 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [20.20] -------> [d : %*.*d].\n", 20, 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [20.20] -------> [d : %*.*d].\n", 20, 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20.20] ------> [d : %-*.*d].\n", 20, 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [-20.20] ------> [d : %-*.*d].\n", 20, 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [-20.20] ------> [d : %-*.*d].\n", 20, 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [-20.20] ------> [d : %-*.*d].\n", 20, 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020.20] ------> [d : %0*.*d].\n", 20, 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [020.20] ------> [d : %0*.*d].\n", 20, 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [020.20] ------> [d : %0*.*d].\n", 20, 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [020.20] ------> [d : %0*.*d].\n", 20, 20, test2);
	check_printf(size_ft_printf, size_printf);

///////////////////////////////////////////////////////////////

	size_printf = printf(KGRN"positif [10] -------> [d : %*.1d].\n", 10, test1);
	size_ft_printf = ft_printf(KCYN"positif [10] -------> [d : %*d].\n", 10, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [10] -------> [d : %*.1d].\n", 10, test2);
	size_ft_printf = ft_printf(KCYN"negatif [10] -------> [d : %*d].\n", 10, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-10] ------> [d : %-*d].\n", 10, test1);
	size_ft_printf = ft_printf(KCYN"positif [-10] ------> [d : %-*d].\n", 10, test1);
	check_printf(size_ft_printf, size_printf);





	size_printf = printf(KGRN"negatif [-10] --------------------------> [d : %-*d].\n", 10, test2);
	size_ft_printf = ft_printf(KCYN"negatif [-10] --------------------------> [d : %-*d].\n", 10, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [010] ------> [d : %0*d].\n", 10, test1);
	size_ft_printf = ft_printf(KCYN"positif [010] ------> [d : %0*d].\n", 10, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [010] ------> [d : %0*d].\n", 10, test2);
	size_ft_printf = ft_printf(KCYN"negatif [010] ------> [d : %0*d].\n", 10, test2);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"positif [20] -------> [d : %*d].\n", 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [20] -------> [d : %*d].\n", 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [20] -------> [d : %*d].\n", 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [20] -------> [d : %*d].\n", 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20] ------> [d : %-*d].\n", 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [-20] ------> [d : %-*d].\n", 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [-20] ------> [d : %-*d].\n", 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [-20] ------> [d : %-*d].\n", 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020] ------> [d : %0*d].\n", 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [020] ------> [d : %0*d].\n", 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [020] ------> [d : %0*d].\n", 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [020] ------> [d : %0*d].\n", 20, test2);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"positif [20] -------> [d : %*d].\n", 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [20] -------> [d : %*d].\n", 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [20] -------> [d : %*d].\n", 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [20] -------> [d : %*d].\n", 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20] ------> [d : %-*d].\n", 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [-20] ------> [d : %-*d].\n", 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [-20] ------> [d : %-*d].\n", 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [-20] ------> [d : %-*d].\n", 20, test2);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020] ------> [d : %0*d].\n", 20, test1);
	size_ft_printf = ft_printf(KCYN"positif [020] ------> [d : %0*d].\n", 20, test1);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"negatif [020] ------> [d : %0*d].\n", 20, test2);
	size_ft_printf = ft_printf(KCYN"negatif [020] ------> [d : %0*d].\n", 20, test2);
	check_printf(size_ft_printf, size_printf);

/////////////////////////////////////////////////////////////////////////







	size_printf = printf(KGRN"positif [10.20] -------> [u : %*.*u].\n", 10, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [10.20] -------> [u : %*.*u].\n", 10, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-10.20] ------> [u : %-*.*u].\n", 10, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-10.20] ------> [u : %-*.*u].\n", 10, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [010.20] ------> [u : %0*.*u].\n", 10, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [010.20] ------> [u : %0*.*u].\n", 10, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [20.10] -------> [u : %*.*u].\n", 20, 10, test_u);
	size_ft_printf = ft_printf(KCYN"positif [20.10] -------> [u : %*.*u].\n", 20, 10, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20.10] ------> [u : %-*.*u].\n", 20, 10, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-20.10] ------> [u : %-*.*u].\n", 20, 10, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020.10] ------> [u : %0*.*u].\n", 20, 10, test_u);
	size_ft_printf = ft_printf(KCYN"positif [020.10] ------> [u : %0*.*u].\n", 20, 10, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [2.2] -------> [u : %*.*u].\n", 2, 2, test_u);
	size_ft_printf = ft_printf(KCYN"positif [2.2] -------> [u : %*.*u].\n", 2, 2, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-2.2] ------> [u : %-*.*u].\n", 2, 2, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-2.2] ------> [u : %-*.*u].\n", 2, 2, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [02.2] ------> [u : %0*.*u].\n", 2, 2, test_u);
	size_ft_printf = ft_printf(KCYN"positif [02.2] ------> [u : %0*.*u].\n", 2, 2, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [20.20] -------> [u : %*.*u].\n", 20, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [20.20] -------> [u : %*.*u].\n", 20, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20.20] ------> [u : %-*.*u].\n", 20, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-20.20] ------> [u : %-*.*u].\n", 20, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020.20] ------> [u : %0*.*u].\n", 20, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [020.20] ------> [u : %0*.*u].\n", 20, 20, test_u);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"positif [10.20] -------> [u : %*.*u].\n", 10, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [10.20] -------> [u : %*.*u].\n", 10, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-10.20] ------> [u : %-*.*u].\n", 10, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-10.20] ------> [u : %-*.*u].\n", 10, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [010.20] ------> [u : %0*.*u].\n", 10, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [010.20] ------> [u : %0*.*u].\n", 10, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [20.10] -------> [u : %*.*u].\n", 20, 10, test_u);
	size_ft_printf = ft_printf(KCYN"positif [20.10] -------> [u : %*.*u].\n", 20, 10, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20.10] ------> [u : %-*.*u].\n", 20, 10, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-20.10] ------> [u : %-*.*u].\n", 20, 10, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020.10] ------> [u : %0*.*u].\n", 20, 10, test_u);
	size_ft_printf = ft_printf(KCYN"positif [020.10] ------> [u : %0*.*u].\n", 20, 10, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [2.2] -------> [u : %*.*u].\n", 2, 2, test_u);
	size_ft_printf = ft_printf(KCYN"positif [2.2] -------> [u : %*.*u].\n", 2, 2, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-2.2] ------> [u : %-*.*u].\n", 2, 2, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-2.2] ------> [u : %-*.*u].\n", 2, 2, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [02.2] ------> [u : %0*.*u].\n", 2, 2, test_u);
	size_ft_printf = ft_printf(KCYN"positif [02.2] ------> [u : %0*.*u].\n", 2, 2, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [20.20] -------> [u : %*.*u].\n", 20, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [20.20] -------> [u : %*.*u].\n", 20, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [-20.20] ------> [u : %-*.*u].\n", 20, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [-20.20] ------> [u : %-*.*u].\n", 20, 20, test_u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"positif [020.20] ------> [u : %0*.*u].\n", 20, 20, test_u);
	size_ft_printf = ft_printf(KCYN"positif [020.20] ------> [u : %0*.*u].\n", 20, 20, test_u);
	check_printf(size_ft_printf, size_printf);


/////////////////////////////////////////////////////////////////




	size_printf = printf(KGRN"percent [10] ----------> [percent : %10%].\n");
	size_ft_printf = ft_printf(KCYN"percent [10] ----------> [percent : %10%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [-10] ---------> [percent : %-10%].\n");
	size_ft_printf = ft_printf(KCYN"percent [-10] ---------> [percent : %-10%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [010] ---------> [percent : %010%].\n");
	size_ft_printf = ft_printf(KCYN"percent [010] ---------> [percent : %010%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [2] -----------> [percent : %2%].\n");
	size_ft_printf = ft_printf(KCYN"percent [2] -----------> [percent : %2%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [-2] ----------> [percent : %-2%].\n");
	size_ft_printf = ft_printf(KCYN"percent [-2] ----------> [percent : %-2%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [02] ----------> [percent : %02%].\n");
	size_ft_printf = ft_printf(KCYN"percent [02] ----------> [percent : %02%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [20] ----------> [percent : %20%].\n");
	size_ft_printf = ft_printf(KCYN"percent [20] ----------> [percent : %20%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [-20] ---------> [percent : %-20%].\n");
	size_ft_printf = ft_printf(KCYN"percent [-20] ---------> [percent : %-20%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [020] ---------> [percent : %020%].\n");
	size_ft_printf = ft_printf(KCYN"percent [020] ---------> [percent : %020%].\n");
	check_printf(size_ft_printf, size_printf);




	size_printf = printf(KGRN"percent [10.20] ----------> [percent : %10.20%].\n");
	size_ft_printf = ft_printf(KCYN"percent [10.20] ----------> [percent : %10.20%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [-10.20] ---------> [percent : %-10.20%].\n");
	size_ft_printf = ft_printf(KCYN"percent [-10.20] ---------> [percent : %-10.20%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [010.20] ---------> [percent : %010.20%].\n");
	size_ft_printf = ft_printf(KCYN"percent [010.20] ---------> [percent : %010.20%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [2.2] -----------> [percent : %2.2%].\n");
	size_ft_printf = ft_printf(KCYN"percent [2.2] -----------> [percent : %2%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [-2.2] ----------> [percent : %-2.2%].\n");
	size_ft_printf = ft_printf(KCYN"percent [-2.2] ----------> [percent : %-2%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [02.2] ----------> [percent : %02.2%].\n");
	size_ft_printf = ft_printf(KCYN"percent [02.2] ----------> [percent : %02.2%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [20.10] ----------> [percent : %20.10%].\n");
	size_ft_printf = ft_printf(KCYN"percent [20.10] ----------> [percent : %20.10%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [-20.10] ---------> [percent : %-20.10%].\n");
	size_ft_printf = ft_printf(KCYN"percent [-20.10] ---------> [percent : %-20.10%].\n");
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"percent [020.10] ---------> [percent : %020.10%].\n");
	size_ft_printf = ft_printf(KCYN"percent [020.10] ---------> [percent : %020.10%].\n");
	check_printf(size_ft_printf, size_printf);

   /////////////////////////////////////////////////////////////////


	size_printf = printf(KGRN"x_X [-10.5] -------> [x : %*.*x].\n", -10, 5, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [-10.5] -------> [x : %*.*x].\n", -10, 5, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [-10.20] ------> [x : %-*.*x].\n", 10, 20, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [-10.20] ------> [x : %-*.*x].\n", 10, 20, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [010.20] ------> [x : %0*.*x].\n", 10, 20, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [010.20] ------> [x : %0*.*x].\n", 10, 20, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [20.10] -------> [x : %*.*x].\n", 20, 10, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [20.10] -------> [x : %*.*x].\n", 20, 10, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [-20.10] ------> [x : %-*.*x].\n", 20, 10, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [-20.10] ------> [x : %-*.*x].\n", 20, 10, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [020.10] ------> [x : %0*.*x].\n", 20, 10, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [020.10] ------> [x : %0*.*x].\n", 20, 10, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [2.2] -------> [x : %*.*x].\n", 2, 2, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [2.2] -------> [x : %*.*x].\n", 2, 2, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [-2.2] ------> [x : %-*.*x].\n", 2, 2, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [-2.2] ------> [x : %-*.*x].\n", 2, 2, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [02.2] ------> [x : %0*.*x].\n", 2, 2, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [02.2] ------> [x : %0*.*x].\n", 2, 2, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [20.20] -------> [x : %*.*x].\n", 20, 20, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [20.20] -------> [x : %*.*x].\n", 20, 20, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [-20.20] ------> [x : %-*.*x].\n", 20, 20, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [-20.20] ------> [x : %-*.*x].\n", 20, 20, test_x_X);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"x_X [020.20] ------> [x : %0*.*x].\n", 20, 20, test_x_X);
	size_ft_printf = ft_printf(KCYN"x_X [020.20] ------> [x : %0*.*x].\n", 20, 20, test_x_X);
	check_printf(size_ft_printf, size_printf);


	return (0);
}
