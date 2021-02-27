/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:07:46 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/26 23:48:55 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*
**	TEJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
*/
// #define BPRINT(x, ...) PRINT("\"%s\" // 1st '*' = %d, 2nd '*' = %d\n", x, a, b)
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	// int		f = 42;
	// int		g = 25;
	// int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

#define KRED  "\x1B[0;31m" // ROUGE
#define KGRN  "\x1B[0;32m" // VERT
#define KYEL  "\x1B[0;33m" // JAUNE
#define KBLU  "\x1B[0;34m" // BLEU
#define KMAG  "\x1B[0;35m" // MAGENTA
#define KCYN  "\x1B[0;36m" // CYAN
#define KWHT  "\x1B[0;37m" // BLANC
#define KGRE  "\x1b[1;30m" // VERT
#define CLR_COLOR "\x1b[0m" // CLEAR COLOR

// printf("666666\n");
# include <libc.h> /////////////////////////////////////////////////////////////




int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}


void	check_printf(int size_ft_printf, int size_printf)
{
	if (size_ft_printf == size_printf)
		printf(KGRN"OK\n");
	else
		printf(KRED"KO\n");
}

int main()
{

	// unsigned int	test_u = 42;
	// unsigned int	test_x_X = 666666;
	// char 			*test_s = "pouet c'est relou";
	// char				test_c = 'q';
	// int				test_adresse_p = 9999999;
	// int				*test_p = &test_adresse_p;
	// int test1 = 765;
	// int test2 = -765;
	int size_ft_printf;
	int size_printf;
	// d

	// size_printf = printf(KGRN"[.4d] -------> [%.4d].\n", 5263);
	// size_ft_printf = ft_printf(KCYN"[.4d] -------> [%.4d].\n", 5263);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.4d] -------> [%.4d].\n", -2372);
	// size_ft_printf = ft_printf(KCYN"[.4d] -------> [%.4d].\n", -2372);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.3d] -------> [%.3d].\n", -23646);
	// size_ft_printf = ft_printf(KCYN"[.3d] -------> [%.3d].\n", -23646);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.d] -------> [%.d].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[.d] -------> [%.d].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[5.0d] -------> [%5.0d].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[5.0d] -------> [%5.0d].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[5.d] -------> [%5.d].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[5.d] -------> [%5.d].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-5.0d] -------> [%-5.0d].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[-5.0d] -------> [%-5.0d].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-5.d] -------> [%-5.d].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[-5.d] -------> [%-5.d].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.*d] -------> [%.*d].\n", -3, 12345);
	// size_ft_printf = ft_printf(KCYN"[.*d] -------> [%.*d].\n", -3, 12345);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.*d] -------> [%.*d].\n", -1, 12345);
	// size_ft_printf = ft_printf(KCYN"[.*d] -------> [%.*d].\n", -1, 12345);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.*d] -------> [%.*d].\n", -1, 0);
	// size_ft_printf = ft_printf(KCYN"[.*d] -------> [%.*d].\n", -1, 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3d] -------> [%3d].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[3d] -------> [%3d].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-3d] -------> [%-3d].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[-3d] -------> [%-3d].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.5d] -------> [%.5d].\n", 2);
	// size_ft_printf = ft_printf(KCYN"[.5d] -------> [%.5d].\n", 2);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.6d] -------> [%.6d].\n", -3);
	// size_ft_printf = ft_printf(KCYN"[.6d] -------> [%.6d].\n", -3);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.3d] -------> [%.3d].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[.3d] -------> [%.3d].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.0d] -------> [%.0d].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[.0d] -------> [%.0d].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-8.3d] -------> [%-8.3d].\n", 8375);
	// size_ft_printf = ft_printf(KCYN"[-8.3d] -------> [%-8.3d].\n", 8375);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-8.3d] -------> [%-8.3d].\n", -8375);
	// size_ft_printf = ft_printf(KCYN"[-8.3d] -------> [%-8.3d].\n", -8375);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[8.3d] -------> [%8.3d].\n", 8375);
	// size_ft_printf = ft_printf(KCYN"[8.3d] -------> [%8.3d].\n", 8375);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[8.3d] -------> [%8.3d].\n", -8473);
	// size_ft_printf = ft_printf(KCYN"[8.3d] -------> [%8.3d].\n", -8473);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[05d] -------> [%05d].\n", 43);
	// size_ft_printf = ft_printf(KCYN"[05d] -------> [%05d].\n", 43);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[07d] -------> [%07d].\n", -54);
	// size_ft_printf = ft_printf(KCYN"[07d] -------> [%07d].\n", -54);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[03d] -------> [%03d].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[03d] -------> [%03d].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.0x] -------> [%.0x].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[.0x] -------> [%.0x].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.x] -------> [%.x].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[.x] -------> [%.x].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.0X] -------> [%.0X].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[.0X] -------> [%.0X].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.X] -------> [%.X].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[.X] -------> [%.X].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[0-7i] -------> [%0*i].\n", -7, -54);
	// size_ft_printf = ft_printf(KCYN"[0-7i] -------> [%0*i].\n", -7, -54);
	// check_printf(size_ft_printf, size_printf);




///////////////////////////////////////////////////////////






	// size_printf = printf(KGRN"[] -------> hello, [%s].\n", "gavin");
	// size_ft_printf = ft_printf(KCYN"[] -------> hello, [%s].\n", "gavin");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[] -------> [%s%s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[] -------> [%s%s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[] -------> this [%s] is [%s].\n", "hello", "");
	// size_ft_printf = ft_printf(KCYN"[] -------> this [%s] is [%s].\n", "hello", "");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[32] -------> [%32s].\n", "abc");
	// size_ft_printf = ft_printf(KCYN"[32] -------> [%32s].\n", "abc");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[16] -------> [%16s].\n", "nark nark");
	// size_ft_printf = ft_printf(KCYN"[16] -------> [%16s].\n", "nark nark");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-32] ------> [%-32s].\n", "abc");
	// size_ft_printf = ft_printf(KCYN"[-32] ------> [%-32s].\n", "abc");
	// check_printf(size_ft_printf, size_printf);
	
	// size_printf = printf(KGRN"[-5] -------> [%-5s].\n", "goes over");
	// size_ft_printf = ft_printf(KCYN"[-5] -------> [%-5s].\n", "goes over");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.7] -------> [%.7s].\n", "hello");
	// size_ft_printf = ft_printf(KCYN"[.7] -------> [%.7s].\n", "hello");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.3] -------> [%.3s].\n", "hello");
	// size_ft_printf = ft_printf(KCYN"[.3] -------> [%.3s].\n", "hello");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.3s|.2s] -------> [%.3s%.2s].\n", "holla", "bitch");
	// size_ft_printf = ft_printf(KCYN"[.3s|.2s] -------> [%.3s%.2s].\n", "holla", "bitch");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.2s|.7s] -------> [%.2s%.7s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[.2s|.7s] -------> [%.2s%.7s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.7s|.2s] -------> [%.7s%.2s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[.7s|.2s] -------> [%.7s%.2s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.5s|7s] -------> [%.5s%7s].\n", "yo", "boi");
	// size_ft_printf = ft_printf(KCYN"[.5s|7s] -------> [%.5s%7s].\n", "yo", "boi");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[7.5s] -------> [%7.5s].\n", "yolo");
	// size_ft_printf = ft_printf(KCYN"[7.5s] -------> [%7.5s].\n", "yolo");
	// check_printf(size_ft_printf, size_printf);
	
	// ////////////////////////////////////////////////////////
	
	// size_printf = printf(KGRN"[11.5s] -------> [%11.5s].\n", "bombastic");
	// size_ft_printf = ft_printf(KCYN"[11.5s] -------> [%11.5s].\n", "bombastic");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[5.11s] -------> [%5.11s].\n", "bombastic");
	// size_ft_printf = ft_printf(KCYN"[5.11s] -------> [%5.11s].\n", "bombastic");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[5.4s] -------> [%5.4s].\n", "bombastic");
	// size_ft_printf = ft_printf(KCYN"[5.4s] -------> [%5.4s].\n", "bombastic");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[11.10s] -------> [%11.10s].\n", "bombastic");
	// size_ft_printf = ft_printf(KCYN"[11.10s] -------> [%11.10s].\n", "bombastic");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3.4s] -------> [%3.4s].\n", "bombastic");
	// size_ft_printf = ft_printf(KCYN"[3.4s] -------> [%3.4s].\n", "bombastic");
	// check_printf(size_ft_printf, size_printf);


	
	// size_printf = printf(KGRN"[-7.5s] -------> [%-7.5s].\n", "yolo");
	// size_ft_printf = ft_printf(KCYN"[-7.5s] -------> [%-7.5s].\n", "yolo");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-7.5s] -------> [%-7.5s].\n", "tubular");
	// size_ft_printf = ft_printf(KCYN"[-7.5s] -------> [%-7.5s].\n", "tubular");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[5.7s] -------> [%5.7s].\n", "yolo");
	// size_ft_printf = ft_printf(KCYN"[5.7s] -------> [%5.7s].\n", "yolo");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[5.7s] -------> [%5.7s].\n", "bombastic");
	// size_ft_printf = ft_printf(KCYN"[5.7s] -------> [%5.7s].\n", "bombastic");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-5.7s] -------> [%-5.7s].\n", "yolo");
	// size_ft_printf = ft_printf(KCYN"[-5.7s] -------> [%-5.7s].\n", "yolo");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-5.7s] -------> [%-5.7s].\n", "tubular");
	// size_ft_printf = ft_printf(KCYN"[-5.7s] -------> [%-5.7s].\n", "tubular");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[7.7s|7.7s] -------> [%7.7s][%7.7s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[7.7s|7.7s] -------> [%7.7s][%7.7s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3.7s|7.7s] -------> [%3.7s][%7.7s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[3.7s|7.7s] -------> [%3.7s][%7.7s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[7.7s|3.7s] -------> [%7.7s][%3.7s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[7.7s|3.7s] -------> [%7.7s][%3.7s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3.7s|3.7s] -------> [%3.7s][%3.7s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[3.7s|3.7s] -------> [%3.7s][%3.7s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[7.3s|7.7s] -------> [%7.3s][%7.7s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[7.3s|7.7s] -------> [%7.3s][%7.7s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3.3s|7.7s] -------> [%3.3s][%7.7s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[3.3s|7.7s] -------> [%3.3s][%7.7s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[7.3s|3.7s] -------> [%7.3s][%3.7s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[7.3s|3.7s] -------> [%7.3s][%3.7s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3.3s|3.7s] -------> [%3.3s][%3.7s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[3.3s|3.7s] -------> [%3.3s][%3.7s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[7.7s|7.3s] -------> [%7.7s][%7.3s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[7.7s|7.3s] -------> [%7.7s][%7.3s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3.7s|7.3s] -------> [%3.7s][%7.3s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[3.7s|7.3s] -------> [%3.7s][%7.3s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[7.7s|3.3s] -------> [%7.7s][%3.3s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[7.7s|3.3s] -------> [%7.7s][%3.3s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3.7s|3.3s] -------> [%3.7s][%3.3s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[3.7s|3.3s] -------> [%3.7s][%3.3s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[7.3s|7.3s] -------> [%7.3s][%7.3s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[7.3s|7.3s] -------> [%7.3s][%7.3s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3.3s|7.3s] -------> [%3.3s][%7.3s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[3.3s|7.3s] -------> [%3.3s][%7.3s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[7.3s|3.3s] -------> [%7.3s][%3.3s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[7.3s|3.3s] -------> [%7.3s][%3.3s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3.3s|3.3s] -------> [%3.3s][%3.3s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[3.3s|3.3s] -------> [%3.3s][%3.3s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	
	// size_printf = printf(KGRN"[3s|3s] -------> [%3s][%3s].\n", "hello", "world");
	// size_ft_printf = ft_printf(KCYN"[3s|3s] -------> [%3s][%3s].\n", "hello", "world");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[] -------> [%s].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[] -------> [%s].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[32s] -------> [%32s].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[32s] -------> [%32s].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[2s] -------> [%2s].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[2s] -------> [%2s].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-32s] -------> [%-32s].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[-32s] -------> [%-32s].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-16s] -------> [%-16s].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[-16s] -------> [%-16s].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-3s] -------> [%-3s].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[-3s] -------> [%-3s].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.9s] -------> [%.9s].\n", "NULL");
	// size_ft_printf = ft_printf(KCYN"[.9s] -------> [%.9s].\n", "NULL");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.3s] -------> [%.3s].\n", "NULL");
	// size_ft_printf = ft_printf(KCYN"[.3s] -------> [%.3s].\n", "NULL");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3.-15s] -------> [%3.*s].\n", -15, NULL);
	// size_ft_printf = ft_printf(KCYN"[3.-15s] -------> [%3.*s].\n", -15, NULL);
	// check_printf(size_ft_printf, size_printf);
	
	// size_printf = printf(KGRN"[] -------> [%s].\n", "hi low");
	// size_ft_printf = ft_printf(KCYN"[] -------> [%s].\n", "hi low");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3] -------> [%3s].\n", "hi low");
	// size_ft_printf = ft_printf(KCYN"[3] -------> [%3s].\n", "hi low");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[9] -------> [%9s].\n", "hi low");
	// size_ft_printf = ft_printf(KCYN"[9] -------> [%9s].\n", "hi low");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.9] -------> [%.9s].\n", "hi low");
	// size_ft_printf = ft_printf(KCYN"[.9] -------> [%.9s].\n", "hi low");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.03] -------> [%.03s].\n", "hi low");
	// size_ft_printf = ft_printf(KCYN"[.03] -------> [%.03s].\n", "hi low");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.09] -------> [%.09s].\n", "hi low");
	// size_ft_printf = ft_printf(KCYN"[.09] -------> [%.09s].\n", "hi low");
	// check_printf(size_ft_printf, size_printf);

	// size_printf = printf(KGRN"[.s] -------> [%.s].\n", "hello");
	// size_ft_printf = ft_printf(KCYN"[.s] -------> [%.s].\n", "hello");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.s] -------> [%.s].\n", "NULL");
	// size_ft_printf = ft_printf(KCYN"[.s] -------> [%.s].\n", "NULL");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.s] -------> [%.s].\n", "hi low");
	// size_ft_printf = ft_printf(KCYN"[.s] -------> [%.s].\n", "hi low");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.03s] -------> [%.03s].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[.03s] -------> [%.03s].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3.s] -------> [%3.s].\n", "hi low");
	// size_ft_printf = ft_printf(KCYN"[3.s] -------> [%3.s].\n", "hi low");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[10.s] -------> [%10.s].\n", "hi low");
	// size_ft_printf = ft_printf(KCYN"[10.s] -------> [%10.s].\n", "hi low");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3.s] -------> [%3.s].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[3.s] -------> [%3.s].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[10.s] -------> [%10.s].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[10.s] -------> [%10.s].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-3.s] -------> [%-3.s].\n", "hi low");
	// size_ft_printf = ft_printf(KCYN"[-3.s] -------> [%-3.s].\n", "hi low");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-8.s] -------> [%-8.s].\n", "hi low");
	// size_ft_printf = ft_printf(KCYN"[-8.s] -------> [%-8.s].\n", "hi low");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-3.s] -------> [%-3.s].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[-3.s] -------> [%-3.s].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-8.s] -------> [%-8.s].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[-8.s] -------> [%-8.s].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3.1s] -------> [%3.1s].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[3.1s] -------> [%3.1s].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-3.1s] -------> [%-3.1s].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[-3.1s] -------> [%-3.1s].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.-3s] -------> [%.*s].\n", -3, NULL);
	// size_ft_printf = ft_printf(KCYN"[.-3s] -------> [%.*s].\n", -3, NULL);
	// check_printf(size_ft_printf, size_printf);





// // ///////////////////////////////////////pft





// 	size_printf = printf(KGRN"c [-.00s] -------> [%-.0s].\n", "hi low");
// 	size_ft_printf = ft_printf(KCYN"c [-.00s] -------> [%-.0s].\n", "hi low");
// 	check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"c [-10] ------> [%-*c].\n", 10, test_c);
	// size_ft_printf = ft_printf(KCYN"c [-10] ------> [%-*c].\n", 10, test_c);
	// check_printf(size_ft_printf, size_printf);

	// size_printf = printf(KGRN"s [.-1] -------> [%.*s].\n", -1, NULL);
	// size_ft_printf = ft_printf(KCYN"s [.-1] -------> [%.*s].\n", -1, NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"s [-30.11] ------> [%-*.*s].\n", 30, 11, test_s);
	// size_ft_printf = ft_printf(KCYN"s [-30.11] ------> [%-*.*s].\n", 30, 11, test_s);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"s [11.30] -------> [%*.*s].\n", 11, 30, test_s);
	// size_ft_printf = ft_printf(KCYN"s [11.30] -------> [%*.*s].\n", 11, 30, test_s);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"s [-11.30] ------> [%-*.*s].\n", 11, 30, test_s);
	// size_ft_printf = ft_printf(KCYN"s [-11.30] ------> [%-*.*s].\n", 11, 30, test_s);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"s [.11] -------> [%.*s].\n", 11, test_s);
	// size_ft_printf = ft_printf(KCYN"s [.11] -------> [%.*s].\n", 11, test_s);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"s [1.11] -------> [%1.*s].\n", 11, test_s);
	// size_ft_printf = ft_printf(KCYN"s [1.11] -------> [%1.*s].\n", 11, test_s);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"s [-.11] ------> [%-.*s].\n", 11, test_s);
	// size_ft_printf = ft_printf(KCYN"s [-.11] ------> [%-.*s].\n", 11, test_s);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"s [.30] -------> [%.*s].\n", 30, test_s);
	// size_ft_printf = ft_printf(KCYN"s [.30] -------> [%.*s].\n", 30, test_s);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"s [-.30] ------> [%-.*s].\n", 30, test_s);
	// size_ft_printf = ft_printf(KCYN"s [-.30] ------> [%-.*s].\n", 30, test_s);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"s [.0] ------> [%.0s].\n", test_s);
	// size_ft_printf = ft_printf(KCYN"s [.0] ------> [%.0s].\n", test_s);
	// check_printf(size_ft_printf, size_printf);


	// size_printf = printf(KGRN"p [30] -------> [%*.p].\n", 30, test_p);
	// size_ft_printf = ft_printf(KCYN"p [30] -------> [%*.p].\n", 30, test_p);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"p [-30] ------> [%-*p].\n", 30, test_p);
	// size_ft_printf = ft_printf(KCYN"p [-30] ------> [%-*p].\n", 30, test_p);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"p [6] -------> [%*p].\n", 6, test_p);
	// size_ft_printf = ft_printf(KCYN"p [6] -------> [%*p].\n", 6, test_p);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"p [-6] ------> [%-*p].\n", 6, test_p);
	// size_ft_printf = ft_printf(KCYN"p [-6] ------> [%-*p].\n", 6, test_p);
	// check_printf(size_ft_printf, size_printf);




	
// 	size_printf = printf(KGRN"positif [-10.5] -------> [d : %*.*d].\n", -10, 5, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [-10.5] -------> [d : %*.*d].\n", -10, 5, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [10.20] -------> [d : %*.*d].\n", 10, 20, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [10.20] -------> [d : %*.*d].\n", 10, 20, test2);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-10.20] ------> [d : %-*.*d].\n", 10, 20, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [-10.20] ------> [d : %-*.*d].\n", 10, 20, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [-10.20] ------> [d : %-*.*d].\n", 10, 20, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [-10.20] ------> [d : %-*.*d].\n", 10, 20, test2);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [010.20] ------> [d : %0*.*d].\n", 10, 20, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [010.20] ------> [d : %0*.*d].\n", 10, 20, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [010.20] ------> [d : %0*.*d].\n", 10, 20, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [010.20] ------> [d : %0*.*d].\n", 10, 20, test2);
// 	check_printf(size_ft_printf, size_printf);

// 	size_printf = printf(KGRN"positif [20.10] -------> [d : %*.*d].\n", 20, 10, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [20.10] -------> [d : %*.*d].\n", 20, 10, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [20.10] -------> [d : %*.*d].\n", 20, 10, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [20.10] -------> [d : %*.*d].\n", 20, 10, test2);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-20.10] ------> [d : %-*.*d].\n", 20, 10, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [-20.10] ------> [d : %-*.*d].\n", 20, 10, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [-20.10] ------> [d : %-*.*d].\n", 20, 10, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [-20.10] ------> [d : %-*.*d].\n", 20, 10, test2);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [020.10] ------> [d : %0*.*d].\n", 20, 10, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [020.10] ------> [d : %0*.*d].\n", 20, 10, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [020.10] ------> [d : %0*.*d].\n", 20, 10, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [020.10] ------> [d : %0*.*d].\n", 20, 10, test2);
// 	check_printf(size_ft_printf, size_printf);

// 	size_printf = printf(KGRN"positif [2.2] -------> [d : %*.*d].\n", 2, 2, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [2.2] -------> [d : %*.*d].\n", 2, 2, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [2.2] -------> [d : %*.*d].\n", 2, 2, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [2.2] -------> [d : %*.*d].\n", 2, 2, test2);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-2.2] ------> [d : %-*.*d].\n", 2, 2, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [-2.2] ------> [d : %-*.*d].\n", 2, 2, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [-2.2] ------> [d : %-*.*d].\n", 2, 2, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [-2.2] ------> [d : %-*.*d].\n", 2, 2, test2);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [02.2] ------> [d : %0*.*d].\n", 2, 2, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [02.2] ------> [d : %0*.*d].\n", 2, 2, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [02.2] ------> [d : %0*.*d].\n", 2, 2, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [02.2] ------> [d : %0*.*d].\n", 2, 2, test2);
// 	check_printf(size_ft_printf, size_printf);

// 	size_printf = printf(KGRN"positif [20.20] -------> [d : %*.*d].\n", 20, 20, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [20.20] -------> [d : %*.*d].\n", 20, 20, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [20.20] -------> [d : %*.*d].\n", 20, 20, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [20.20] -------> [d : %*.*d].\n", 20, 20, test2);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-20.20] ------> [d : %-*.*d].\n", 20, 20, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [-20.20] ------> [d : %-*.*d].\n", 20, 20, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [-20.20] ------> [d : %-*.*d].\n", 20, 20, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [-20.20] ------> [d : %-*.*d].\n", 20, 20, test2);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [020.20] ------> [d : %0*.*d].\n", 20, 20, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [020.20] ------> [d : %0*.*d].\n", 20, 20, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [020.20] ------> [d : %0*.*d].\n", 20, 20, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [020.20] ------> [d : %0*.*d].\n", 20, 20, test2);
// 	check_printf(size_ft_printf, size_printf);

// ///////////////////////////////////////////////////////////////

// 	size_printf = printf(KGRN"positif [10] -------> [d : %*.1d].\n", 10, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [10] -------> [d : %*d].\n", 10, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [10] -------> [d : %*.1d].\n", 10, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [10] -------> [d : %*d].\n", 10, test2);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-10] ------> [d : %-*d].\n", 10, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [-10] ------> [d : %-*d].\n", 10, test1);
// 	check_printf(size_ft_printf, size_printf);





// 	size_printf = printf(KGRN"negatif [-10] --------------------------> [d : %-*d].\n", 10, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [-10] --------------------------> [d : %-*d].\n", 10, test2);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [010] ------> [d : %0*d].\n", 10, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [010] ------> [d : %0*d].\n", 10, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [010] ------> [d : %0*d].\n", 10, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [010] ------> [d : %0*d].\n", 10, test2);
// 	check_printf(size_ft_printf, size_printf);

// 	size_printf = printf(KGRN"positif [20] -------> [d : %*d].\n", 20, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [20] -------> [d : %*d].\n", 20, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [20] -------> [d : %*d].\n", 20, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [20] -------> [d : %*d].\n", 20, test2);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-20] ------> [d : %-*d].\n", 20, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [-20] ------> [d : %-*d].\n", 20, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [-20] ------> [d : %-*d].\n", 20, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [-20] ------> [d : %-*d].\n", 20, test2);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [020] ------> [d : %0*d].\n", 20, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [020] ------> [d : %0*d].\n", 20, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [020] ------> [d : %0*d].\n", 20, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [020] ------> [d : %0*d].\n", 20, test2);
// 	check_printf(size_ft_printf, size_printf);

// 	size_printf = printf(KGRN"positif [20] -------> [d : %*d].\n", 20, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [20] -------> [d : %*d].\n", 20, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [20] -------> [d : %*d].\n", 20, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [20] -------> [d : %*d].\n", 20, test2);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-20] ------> [d : %-*d].\n", 20, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [-20] ------> [d : %-*d].\n", 20, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [-20] ------> [d : %-*d].\n", 20, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [-20] ------> [d : %-*d].\n", 20, test2);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [020] ------> [d : %0*d].\n", 20, test1);
// 	size_ft_printf = ft_printf(KCYN"positif [020] ------> [d : %0*d].\n", 20, test1);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"negatif [020] ------> [d : %0*d].\n", 20, test2);
// 	size_ft_printf = ft_printf(KCYN"negatif [020] ------> [d : %0*d].\n", 20, test2);
// 	check_printf(size_ft_printf, size_printf);

// /////////////////////////////////////////////////////////////////////////







// 	size_printf = printf(KGRN"positif [10.20] -------> [u : %*.*u].\n", 10, 20, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [10.20] -------> [u : %*.*u].\n", 10, 20, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-10.20] ------> [u : %-*.*u].\n", 10, 20, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [-10.20] ------> [u : %-*.*u].\n", 10, 20, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [010.20] ------> [u : %0*.*u].\n", 10, 20, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [010.20] ------> [u : %0*.*u].\n", 10, 20, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [20.10] -------> [u : %*.*u].\n", 20, 10, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [20.10] -------> [u : %*.*u].\n", 20, 10, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-20.10] ------> [u : %-*.*u].\n", 20, 10, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [-20.10] ------> [u : %-*.*u].\n", 20, 10, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [020.10] ------> [u : %0*.*u].\n", 20, 10, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [020.10] ------> [u : %0*.*u].\n", 20, 10, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [2.2] -------> [u : %*.*u].\n", 2, 2, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [2.2] -------> [u : %*.*u].\n", 2, 2, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-2.2] ------> [u : %-*.*u].\n", 2, 2, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [-2.2] ------> [u : %-*.*u].\n", 2, 2, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [02.2] ------> [u : %0*.*u].\n", 2, 2, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [02.2] ------> [u : %0*.*u].\n", 2, 2, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [20.20] -------> [u : %*.*u].\n", 20, 20, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [20.20] -------> [u : %*.*u].\n", 20, 20, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-20.20] ------> [u : %-*.*u].\n", 20, 20, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [-20.20] ------> [u : %-*.*u].\n", 20, 20, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [020.20] ------> [u : %0*.*u].\n", 20, 20, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [020.20] ------> [u : %0*.*u].\n", 20, 20, test_u);
// 	check_printf(size_ft_printf, size_printf);

// 	size_printf = printf(KGRN"positif [10.20] -------> [u : %*.*u].\n", 10, 20, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [10.20] -------> [u : %*.*u].\n", 10, 20, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-10.20] ------> [u : %-*.*u].\n", 10, 20, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [-10.20] ------> [u : %-*.*u].\n", 10, 20, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [010.20] ------> [u : %0*.*u].\n", 10, 20, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [010.20] ------> [u : %0*.*u].\n", 10, 20, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [20.10] -------> [u : %*.*u].\n", 20, 10, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [20.10] -------> [u : %*.*u].\n", 20, 10, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-20.10] ------> [u : %-*.*u].\n", 20, 10, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [-20.10] ------> [u : %-*.*u].\n", 20, 10, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [020.10] ------> [u : %0*.*u].\n", 20, 10, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [020.10] ------> [u : %0*.*u].\n", 20, 10, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [2.2] -------> [u : %*.*u].\n", 2, 2, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [2.2] -------> [u : %*.*u].\n", 2, 2, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-2.2] ------> [u : %-*.*u].\n", 2, 2, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [-2.2] ------> [u : %-*.*u].\n", 2, 2, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [02.2] ------> [u : %0*.*u].\n", 2, 2, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [02.2] ------> [u : %0*.*u].\n", 2, 2, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [20.20] -------> [u : %*.*u].\n", 20, 20, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [20.20] -------> [u : %*.*u].\n", 20, 20, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [-20.20] ------> [u : %-*.*u].\n", 20, 20, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [-20.20] ------> [u : %-*.*u].\n", 20, 20, test_u);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"positif [020.20] ------> [u : %0*.*u].\n", 20, 20, test_u);
// 	size_ft_printf = ft_printf(KCYN"positif [020.20] ------> [u : %0*.*u].\n", 20, 20, test_u);
// 	check_printf(size_ft_printf, size_printf);


// /////////////////////////////////////////////////////////////////




// 	size_printf = printf(KGRN"percent [10] ----------> [percent : %10%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [10] ----------> [percent : %10%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [-10] ---------> [percent : %-10%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [-10] ---------> [percent : %-10%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [010] ---------> [percent : %010%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [010] ---------> [percent : %010%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [2] -----------> [percent : %2%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [2] -----------> [percent : %2%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [-2] ----------> [percent : %-2%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [-2] ----------> [percent : %-2%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [02] ----------> [percent : %02%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [02] ----------> [percent : %02%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [20] ----------> [percent : %20%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [20] ----------> [percent : %20%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [-20] ---------> [percent : %-20%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [-20] ---------> [percent : %-20%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [020] ---------> [percent : %020%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [020] ---------> [percent : %020%].\n");
// 	check_printf(size_ft_printf, size_printf);




// 	size_printf = printf(KGRN"percent [10.20] ----------> [percent : %10.20%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [10.20] ----------> [percent : %10.20%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [-10.20] ---------> [percent : %-10.20%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [-10.20] ---------> [percent : %-10.20%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [010.20] ---------> [percent : %010.20%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [010.20] ---------> [percent : %010.20%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [2.2] -----------> [percent : %2.2%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [2.2] -----------> [percent : %2%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [-2.2] ----------> [percent : %-2.2%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [-2.2] ----------> [percent : %-2%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [02.2] ----------> [percent : %02.2%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [02.2] ----------> [percent : %02.2%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [20.10] ----------> [percent : %20.10%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [20.10] ----------> [percent : %20.10%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [-20.10] ---------> [percent : %-20.10%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [-20.10] ---------> [percent : %-20.10%].\n");
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"percent [020.10] ---------> [percent : %020.10%].\n");
// 	size_ft_printf = ft_printf(KCYN"percent [020.10] ---------> [percent : %020.10%].\n");
// 	check_printf(size_ft_printf, size_printf);

//    /////////////////////////////////////////////////////////////////


// 	size_printf = printf(KGRN"x_X [-10.5] -------> [x : %*.*x].\n", -10, 5, test_x_X);
// 	size_ft_printf = ft_printf(KCYN"x_X [-10.5] -------> [x : %*.*x].\n", -10, 5, test_x_X);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"x_X [-10.20] ------> [x : %-*.*x].\n", 10, 20, test_x_X);
// 	size_ft_printf = ft_printf(KCYN"x_X [-10.20] ------> [x : %-*.*x].\n", 10, 20, test_x_X);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"x_X [010.20] ------> [x : %0*.*x].\n", 10, 20, test_x_X);
// 	size_ft_printf = ft_printf(KCYN"x_X [010.20] ------> [x : %0*.*x].\n", 10, 20, test_x_X);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"x_X [20.10] -------> [x : %*.*x].\n", 20, 10, test_x_X);
// 	size_ft_printf = ft_printf(KCYN"x_X [20.10] -------> [x : %*.*x].\n", 20, 10, test_x_X);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"x_X [-20.10] ------> [x : %-*.*x].\n", 20, 10, test_x_X);
// 	size_ft_printf = ft_printf(KCYN"x_X [-20.10] ------> [x : %-*.*x].\n", 20, 10, test_x_X);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"x_X [020.10] ------> [x : %0*.*x].\n", 20, 10, test_x_X);
// 	size_ft_printf = ft_printf(KCYN"x_X [020.10] ------> [x : %0*.*x].\n", 20, 10, test_x_X);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"x_X [2.2] -------> [x : %*.*x].\n", 2, 2, test_x_X);
// 	size_ft_printf = ft_printf(KCYN"x_X [2.2] -------> [x : %*.*x].\n", 2, 2, test_x_X);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"x_X [-2.2] ------> [x : %-*.*x].\n", 2, 2, test_x_X);
// 	size_ft_printf = ft_printf(KCYN"x_X [-2.2] ------> [x : %-*.*x].\n", 2, 2, test_x_X);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"x_X [02.2] ------> [x : %0*.*x].\n", 2, 2, test_x_X);
// 	size_ft_printf = ft_printf(KCYN"x_X [02.2] ------> [x : %0*.*x].\n", 2, 2, test_x_X);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"x_X [20.20] -------> [x : %*.*x].\n", 20, 20, test_x_X);
// 	size_ft_printf = ft_printf(KCYN"x_X [20.20] -------> [x : %*.*x].\n", 20, 20, test_x_X);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"x_X [-20.20] ------> [x : %-*.*x].\n", 20, 20, test_x_X);
// 	size_ft_printf = ft_printf(KCYN"x_X [-20.20] ------> [x : %-*.*x].\n", 20, 20, test_x_X);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"x_X [020.20] ------> [x : %0*.*x].\n", 20, 20, test_x_X);
// 	size_ft_printf = ft_printf(KCYN"x_X [020.20] ------> [x : %0*.*x].\n", 20, 20, test_x_X);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[5.0u] -------> [%5.0u].\n", 0);
// 	size_ft_printf = ft_printf(KCYN"[5.0u] -------> [%5.0u].\n", 0);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[5.u] -------> [%5.u].\n", 0);
// 	size_ft_printf = ft_printf(KCYN"[5.u] -------> [%5.u].\n", 0);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[-5.0u] -------> [%-5.0u].\n", 0);
// 	size_ft_printf = ft_printf(KCYN"[-5.0u] -------> [%-5.0u].\n", 0);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[-5.u] -------> [%-5.u].\n", 0);
// 	size_ft_printf = ft_printf(KCYN"[-5.u] -------> [%-5.u].\n", 0);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[5.0x] -------> [%5.0x].\n", 0);
// 	size_ft_printf = ft_printf(KCYN"[5.0x] -------> [%5.0x].\n", 0);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[5.x] -------> [%5.x].\n", 0);
// 	size_ft_printf = ft_printf(KCYN"[5.x] -------> [%5.x].\n", 0);
// 	check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[-5.0x] -------> [%-5.0x].\n", 0);
// 	// size_ft_printf = ft_printf(KCYN"[-5.0x] -------> [%-5.0x].\n", 0);
// 	// check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[-5.x] -------> [%-5.x].\n", 0);
// 	// size_ft_printf = ft_printf(KCYN"[-5.x] -------> [%-5.x].\n", 0);
// 	// check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[5.0X] -------> [%5.0X].\n", 0);
// 	// size_ft_printf = ft_printf(KCYN"[5.0X] -------> [%5.0X].\n", 0);
// 	// check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[5.X] -------> [%5.X].\n", 0);
// 	// size_ft_printf = ft_printf(KCYN"[5.X] -------> [%5.X].\n", 0);
// 	// check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[-5.0X] -------> [%-5.0X].\n", 0);
// 	// size_ft_printf = ft_printf(KCYN"[-5.0X] -------> [%-5.0X].\n", 0);
// 	// check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[-5.X] -------> [%-5.X].\n", 0);
// 	// size_ft_printf = ft_printf(KCYN"[-5.X] -------> [%-5.X].\n", 0);
// 	// check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[5.11s] -------> [%5.11s].\n", "bombastic");
// 	// size_ft_printf = ft_printf(KCYN"[5.11s] -------> [%5.11s].\n", "bombastic");
// 	// check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[--15.-4s] -------> [%-*.*s].\n", -15, -4, "bombastic");
// 	// size_ft_printf = ft_printf(KCYN"[--15.-4s] -------> [%-*.*s].\n", -15, -4, "bombastic");
// 	// check_printf(size_ft_printf, size_printf);
// 	size_printf = printf(KGRN"[--7.-3s] -------> [%-*.*s].\n", -7, -3, "yolo");
// 	// size_ft_printf = ft_printf(KCYN"[--7.-3s] -------> [%-*.*s].\n", -7, -3, "yolo");
// 	// check_printf(size_ft_printf, size_printf);



	// size_printf = printf(KGRN"[5c] -------> [%5c].\n", '\0');
	// size_ft_printf = ft_printf(KCYN"[5c] -------> [%5c].\n", '\0');
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-5c] -------> [%-5c].\n", '\0');
	// size_ft_printf = ft_printf(KCYN"[-5c] -------> [%-5c].\n", '\0');
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-14c] -------> [%-14c].\n", 'p');
	// size_ft_printf = ft_printf(KCYN"[-14c] -------> [%-14c].\n", 'p');
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-1c] -------> [%-1c].\n", 't');
	// size_ft_printf = ft_printf(KCYN"[-1c] -------> [%-1c].\n", 't');
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[1c] -------> [%1c].\n", 't');
	// size_ft_printf = ft_printf(KCYN"[1c] -------> [%1c].\n", 't');
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.0u|0.-3x] -------> [%.0u][%0.*x].\n", -228163136, -3, 2147483647);
	// size_ft_printf = ft_printf(KCYN"[.0u|0.-3x] -------> [%.0u][%0.*x].\n", -228163136, -3, 2147483647);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[14.0 s = {tyL2lTkXLSJwV2yncawCv1YKLTpR9ZhbTJz8qKS8DNtqyG36tmDuPdctln}] -------> [%14.0s].\n", "tyL2lTkXLSJwV2yncawCv1YKLTpR9ZhbTJz8qKS8DNtqyG36tmDuPdctln");
	// size_ft_printf = ft_printf(KCYN"[14.0 s = {tyL2lTkXLSJwV2yncawCv1YKLTpR9ZhbTJz8qKS8DNtqyG36tmDuPdctln}] -------> [%14.0s].\n", "tyL2lTkXLSJwV2yncawCv1YKLTpR9ZhbTJz8qKS8DNtqyG36tmDuPdctln");
	// check_printf(size_ft_printf, size_printf);

	// size_printf = printf(KGRN"[14.0s] -------> [%14.0s].\n", "hello");
	// size_ft_printf = ft_printf(KCYN"[14.0s] -------> [%14.0s].\n", "hello");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[3.0s] -------> [%3.0s].\n", "hello");
	// size_ft_printf = ft_printf(KCYN"[3.0s] -------> [%3.0s].\n", "hello");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[14.3s] -------> [%14.3s].\n", "hello");
	// size_ft_printf = ft_printf(KCYN"[14.3s] -------> [%14.3s].\n", "hello");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[4.3s] -------> [%4.3s].\n", "hello");
	// size_ft_printf = ft_printf(KCYN"[4.3s] -------> [%4.3s].\n", "hello");
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.-1x] -------> [%.*x].\n", -1, 0);
	// size_ft_printf = ft_printf(KCYN"[.-1x] -------> [%.*x].\n", -1, 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.-1X] -------> [%.*X].\n", -1, 0);
	// size_ft_printf = ft_printf(KCYN"[.-1X] -------> [%.*X].\n", -1, 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.-1u] -------> [%.*u].\n", -1, 0);
	// size_ft_printf = ft_printf(KCYN"[.-1u] -------> [%.*u].\n", -1, 0);
	// check_printf(size_ft_printf, size_printf);



	// size_printf = printf(KGRN"[.p] -------> [%.p].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[.p] -------> [%.p].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[5.p] -------> [%5.p].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[5.p] -------> [%5.p].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[2.p] -------> [%2.p].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[2.p] -------> [%2.p].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[p] -------> [%p].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[p] -------> [%p].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[5p] -------> [%5p].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[5p] -------> [%5p].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[2p] -------> [%2p].\n", NULL);
	// size_ft_printf = ft_printf(KCYN"[2p] -------> [%2p].\n", NULL);
	// check_printf(size_ft_printf, size_printf);
	// // size_printf = printf(KGRN"[00s] -------> [%00s].\n", "hi low");
	// // size_ft_printf = ft_printf(KCYN"[00s] -------> [%00s].\n", "hi low");
	// // check_printf(size_ft_printf, size_printf);
	// // size_printf = printf(KGRN"[000s] -------> [%000s].\n", "hi low");
	// // size_ft_printf = ft_printf(KCYN"[000s] -------> [%000s].\n", "hi low");
	// // check_printf(size_ft_printf, size_printf);
	// // size_printf = printf(KGRN"[0000s] -------> [%0000s].\n", "hi low");
	// // size_ft_printf = ft_printf(KCYN"[0000s] -------> [%0000s].\n", "hi low");
	// // check_printf(size_ft_printf, size_printf);
	// // size_printf = printf(KGRN"[00-s] -------> [%00-s].\n", "hi low");
	// // size_ft_printf = ft_printf(KCYN"[00-s] -------> [%00-s].\n", "hi low");
	// // check_printf(size_ft_printf, size_printf);
	// // 	size_printf = printf(KGRN"[05%] -------> [%05%].\n");
	// // size_ft_printf = ft_printf(KCYN"[05%] -------> [%05%].\n");
	// // check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[05d] -------> [%05d].\n", 43);
	// size_ft_printf = ft_printf(KCYN"[05d] -------> [%05d].\n", 43);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[07d] -------> [%07d].\n", -54);
	// size_ft_printf = ft_printf(KCYN"[07d] -------> [%07d].\n", -54);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[03d] -------> [%03d].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[03d] -------> [%03d].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[05i] -------> [%05i].\n", 43);
	// size_ft_printf = ft_printf(KCYN"[05i] -------> [%05i].\n", 43);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[07i] -------> [%07i].\n", -54);
	// size_ft_printf = ft_printf(KCYN"[07i] -------> [%07i].\n", -54);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[03i] -------> [%03i].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[03i] -------> [%03i].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[05u] -------> [%05u].\n", 43);
	// size_ft_printf = ft_printf(KCYN"[05u] -------> [%05u].\n", 43);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[03u] -------> [%03u].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[03u] -------> [%03u].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[05x] -------> [%05x].\n", 43);
	// size_ft_printf = ft_printf(KCYN"[05x] -------> [%05x].\n", 43);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[03x] -------> [%03x].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[03x] -------> [%03x].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[05X] -------> [%05X].\n", 43);
	// size_ft_printf = ft_printf(KCYN"[05X] -------> [%05X].\n", 43);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[03X] -------> [%03X].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[03X] -------> [%03X].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[07i] -------> [%0*i].\n", 7, -54);
	// size_ft_printf = ft_printf(KCYN"[07i] -------> [%0*i].\n", 7, -54);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[04i] -------> [%04i].\n", 42);
	// size_ft_printf = ft_printf(KCYN"[04i] -------> [%04i].\n", 42);
	// check_printf(size_ft_printf, size_printf);
	// // size_printf = printf(KGRN"[0-8.3i] -------> [%0-8.3i].\n", -8473);
	// // size_ft_printf = ft_printf(KCYN"[0-8.3i] -------> [%0-8.3i].\n", -8473);
	// // check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[0.i] -------> [%0.i].\n", i);
	// size_ft_printf = ft_printf(KCYN"[0.i] -------> [%0.i].\n", i);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[0.d] -------> [%0.d].\n", j);
	// size_ft_printf = ft_printf(KCYN"[0.d] -------> [%0.d].\n", j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[0.d] -------> [%0.d].\n", k);
	// size_ft_printf = ft_printf(KCYN"[0.d] -------> [%0.d].\n", k);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[0.d] -------> [%0.d].\n", l);
	// size_ft_printf = ft_printf(KCYN"[0.d] -------> [%0.d].\n", l);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[0.d] -------> [%0.d].\n", m);
	// size_ft_printf = ft_printf(KCYN"[0.d] -------> [%0.d].\n", m);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[0.d] -------> [%0.d].\n", c);
	// size_ft_printf = ft_printf(KCYN"[0.d] -------> [%0.d].\n", c);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[0.d] -------> [%0.d].\n", e);
	// size_ft_printf = ft_printf(KCYN"[0.d] -------> [%0.d].\n", e);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[0.d] -------> [%0.d].\n", d);
	// size_ft_printf = ft_printf(KCYN"[0.d] -------> [%0.d].\n", d);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.0i] -------> [%.0i].\n", i);
	// size_ft_printf = ft_printf(KCYN"[.0i] -------> [%.0i].\n", i);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.0d] -------> [%.0d].\n", j);
	// size_ft_printf = ft_printf(KCYN"[.0d] -------> [%.0d].\n", j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.0d] -------> [%.0d].\n", k);
	// size_ft_printf = ft_printf(KCYN"[.0d] -------> [%.0d].\n", k);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.0d] -------> [%.0d].\n", l);
	// size_ft_printf = ft_printf(KCYN"[.0d] -------> [%.0d].\n", l);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.0d] -------> [%.0d].\n", m);
	// size_ft_printf = ft_printf(KCYN"[.0d] -------> [%.0d].\n", m);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.0d] -------> [%.0d].\n", c);
	// size_ft_printf = ft_printf(KCYN"[.0d] -------> [%.0d].\n", c);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.0d] -------> [%.0d].\n", e);
	// size_ft_printf = ft_printf(KCYN"[.0d] -------> [%.0d].\n", e);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.0d] -------> [%.0d].\n", d);
	// size_ft_printf = ft_printf(KCYN"[.0d] -------> [%.0d].\n", d);
	// check_printf(size_ft_printf, size_printf);
	// 	size_printf = printf(KGRN"[1.i] -------> [%1.i].\n", i);
	// size_ft_printf = ft_printf(KCYN"[1.i] -------> [%1.i].\n", i);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[1.d] -------> [%1.d].\n", j);
	// size_ft_printf = ft_printf(KCYN"[1.d] -------> [%1.d].\n", j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[1.d] -------> [%1.d].\n", k);
	// size_ft_printf = ft_printf(KCYN"[1.d] -------> [%1.d].\n", k);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[1.d] -------> [%1.d].\n", l);
	// size_ft_printf = ft_printf(KCYN"[1.d] -------> [%1.d].\n", l);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[1.d] -------> [%1.d].\n", m);
	// size_ft_printf = ft_printf(KCYN"[1.d] -------> [%1.d].\n", m);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[1.d] -------> [%1.d].\n", c);
	// size_ft_printf = ft_printf(KCYN"[1.d] -------> [%1.d].\n", c);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[1.d] -------> [%1.d].\n", e);
	// size_ft_printf = ft_printf(KCYN"[1.d] -------> [%1.d].\n", e);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[1.d] -------> [%1.d].\n", d);
	// size_ft_printf = ft_printf(KCYN"[1.d] -------> [%1.d].\n", d);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-2.1i] -------> [%*.*i].\n", -2, 1, i);
	// size_ft_printf = ft_printf(KCYN"[-2.1i] -------> [%*.*i].\n", -2, 1, i);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-2.1d] -------> [%*.*d].\n", -2, 1, j);
	// size_ft_printf = ft_printf(KCYN"[-2.1d] -------> [%*.*d].\n", -2, 1, j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-2.1d] -------> [%*.*d].\n", -2, 1, k);
	// size_ft_printf = ft_printf(KCYN"[-2.1d] -------> [%*.*d].\n", -2, 1, k);
	// check_printf(size_ft_printf, size_printf);
	// 	size_printf = printf(KGRN"[-2.1d] -------> [%*.*d].\n", -2, 1, l);
	// size_ft_printf = ft_printf(KCYN"[-2.1d] -------> [%*.*d].\n", -2, 1, l);
	// check_printf(size_ft_printf, size_printf);
	// 	size_printf = printf(KGRN"[-2.1d] -------> [%*.*d].\n", -2, 1, m);
	// size_ft_printf = ft_printf(KCYN"[-2.1d] -------> [%*.*d].\n", -2, 1, m);
	// check_printf(size_ft_printf, size_printf);
	// 	size_printf = printf(KGRN"[-2.1d] -------> [%*.*d].\n", -2, 1, c);
	// size_ft_printf = ft_printf(KCYN"[-2.1d] -------> [%*.*d].\n", -2, 1, c);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-2.1d] -------> [%*.*d].\n", -2, 1, e);
	// size_ft_printf = ft_printf(KCYN"[-2.1d] -------> [%*.*d].\n", -2, 1, e);
	// check_printf(size_ft_printf, size_printf);
	// 	size_printf = printf(KGRN"[-2.1d] -------> [%*.*d].\n", -2, 1, d);
	// size_ft_printf = ft_printf(KCYN"[-2.1d] -------> [%*.*d].\n", -2, 1, d);
	// check_printf(size_ft_printf, size_printf);
	// 	size_printf = printf(KGRN"[.0u] -------> [%.0u].\n", 3);
	// size_ft_printf = ft_printf(KCYN"[.0u] -------> [%.0u].\n", 3);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.u] -------> [%.u].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[.u] -------> [%.u].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.3X] -------> [%.3X].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[.3X] -------> [%.3X].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.3x] -------> [%.3x].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[.3x] -------> [%.3x].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.3u] -------> [%.3u].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[.3u] -------> [%.3u].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[.3d] -------> [%.3d].\n", 13862);
	// size_ft_printf = ft_printf(KCYN"[.3d] -------> [%.3d].\n", 13862);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-3.7d] -------> [%-3.7d].\n", 3267);
	// size_ft_printf = ft_printf(KCYN"[-3.7d] -------> [%-3.7d].\n", 3267);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-3.7d] -------> [%-3.7d].\n", -2375);
	// size_ft_printf = ft_printf(KCYN"[-3.7d] -------> [%-3.7d].\n", -2375);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-10.5d] -------> [%-10.5d].\n", -216);
	// size_ft_printf = ft_printf(KCYN"[-10.5d] -------> [%-10.5d].\n", -216);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-8.5d] -------> [%-8.5d].\n", 0);
	// size_ft_printf = ft_printf(KCYN"[-8.3d] -------> [%-8.5d].\n", 0);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-8.5d] -------> [%-8.5d].\n", 34);
	// size_ft_printf = ft_printf(KCYN"[-8.5d] -------> [%-8.5d].\n", 34);
	// check_printf(size_ft_printf, size_printf);
	// 	size_printf = printf(KGRN"[02.-2i] -------> [%0*.*i].\n", 2, -2, i);
	// size_ft_printf = ft_printf(KCYN"[02.-2i] -------> [%0*.*i].\n", 2, -2, i);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[02.-2d] -------> [%0*.*d].\n", 2, -2, j);
	// size_ft_printf = ft_printf(KCYN"[02.-2d] -------> [%0*.*d].\n", 2, -2, j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[02.-2d] -------> [%0*.*d].\n", 2, -2, k);
	// size_ft_printf = ft_printf(KCYN"[02.-2d] -------> [%0*.*d].\n", 2, -2, k);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[02.-2d] -------> [%0*.*d].\n", 2, -2, l);
	// size_ft_printf = ft_printf(KCYN"[02.-2d] -------> [%0*.*d].\n", 2, -2, l);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[02.-2d] -------> [%0*.*d].\n", 2, -2, m);
	// size_ft_printf = ft_printf(KCYN"[02.-2d] -------> [%0*.*d].\n", 2, -2, m);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[02.-2d] -------> [%0*.*d].\n", 2, -2, c);
	// size_ft_printf = ft_printf(KCYN"[02.-2d] -------> [%0*.*d].\n", 2, -2, c);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[02.-2d] -------> [%0*.*d].\n", 2, -2, e);
	// size_ft_printf = ft_printf(KCYN"[02.-2d] -------> [%0*.*d].\n", 2, -2, e);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[02.-2d] -------> [%0*.*d].\n", 2, -2, d);
	// size_ft_printf = ft_printf(KCYN"[02.-2d] -------> [%0*.*d].\n", 2, -2, d);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[08.3d] -------> [%08.3d].\n", 8375);
	// size_ft_printf = ft_printf(KCYN"[08.3d] -------> [%08.3d].\n", 8375);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[08.3d] -------> [%08.3d].\n", -8473);
	// size_ft_printf = ft_printf(KCYN"[08.3d] -------> [%08.3d].\n", -8473);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[03.-2i] -------> [%0*.*i].\n", 3, -2, i);
	// size_ft_printf = ft_printf(KCYN"[03.-2i] -------> [%0*.*i].\n", 3, -2, i);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[03.-2d] -------> [%0*.*d].\n", 3, -2, k);
	// size_ft_printf = ft_printf(KCYN"[03.-2d] -------> [%0*.*d].\n", 3, -2, k);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[03.-2d] -------> [%0*.*d].\n", 3, -2, l);
	// size_ft_printf = ft_printf(KCYN"[03.-2d] -------> [%0*.*d].\n", 3, -2, l);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[03.-2d] -------> [%0*.*d].\n", 3, -2, m);
	// size_ft_printf = ft_printf(KCYN"[03.-2d] -------> [%0*.*d].\n", 3, -2, m);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[03.-2d] -------> [%0*.*d].\n", 3, -2, c);
	// size_ft_printf = ft_printf(KCYN"[03.-2d] -------> [%0*.*d].\n", 3, -2, c);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[03.-2d] -------> [%0*.*d].\n", 3, -2, e);
	// size_ft_printf = ft_printf(KCYN"[03.-2d] -------> [%0*.*d].\n", 3, -2, e);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[03.-2d] -------> [%0*.*d].\n", 3, -2, d);
	// size_ft_printf = ft_printf(KCYN"[03.-2d] -------> [%0*.*d].\n", 3, -2, d);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[08.3d] -------> [%08.3d].\n", 8375);
	// size_ft_printf = ft_printf(KCYN"[08.3d] -------> [%08.3d].\n", 8375);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[08.3d] -------> [%08.3d].\n", -8473);
	// size_ft_printf = ft_printf(KCYN"[08.3d] -------> [%08.3d].\n", -8473);
	// check_printf(size_ft_printf, size_printf);

	// size_printf = printf(KGRN"[03.-2d] -------> [%0*.*d].\n", 3, -2, j);
	// size_ft_printf = ft_printf(KCYN"[03.-2d] -------> [%0*.*d].\n", 3, -2, j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-2.3d] -------> [%-*.*d].\n", -2, 3, j);
	// size_ft_printf = ft_printf(KCYN"[-2.3d] -------> [%-*.*d].\n", -2, 3, j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[02.3d] -------> [%0*.*d].\n", -2, 3, j);
	// size_ft_printf = ft_printf(KCYN"[02.3d] -------> [%0*.*d].\n", -2, 3, j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[03.0d] -------> [%0*.*d].\n", 3, 0, j);
	// size_ft_printf = ft_printf(KCYN"[03.0d] -------> [%0*.*d].\n", 3, 0, j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-4.0d] -------> [%*.*d].\n", -4, 0, j);
	// size_ft_printf = ft_printf(KCYN"[-4.0d] -------> [%*.*d].\n", -4, 0, j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[6.0d] -------> [%*.*d].\n", 6, 0, j);
	// size_ft_printf = ft_printf(KCYN"[6.0d] -------> [%*.*d].\n", 6, 0, j);
	// check_printf(size_ft_printf, size_printf);

	// size_printf = printf(KGRN"[-4.10j] -------> [%-*.*d].\n", 4, 10, 1);
	// size_ft_printf = ft_printf(KCYN"[-4.10j] -------> [%-*.*d].\n", 4, 10, 1);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-7.15j] -------> [%-*.*d].\n", 7, 15, 1);
	// size_ft_printf = ft_printf(KCYN"[-7.15j] -------> [%-*.*d].\n", 7, 15, 1);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[07.15j] -------> [%0*.*d].\n", 7, 15, 1);
	// size_ft_printf = ft_printf(KCYN"[07.15j] -------> [%0*.*d].\n", 7, 15, 1);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-3.2d] -------> [%-*.*d].\n", 3, 2, m);
	// size_ft_printf = ft_printf(KCYN"[-3.2d] -------> [%-*.*d].\n", 3, 2, m);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-3.2d] -------> [%-*.*d].\n", 3, 2, e);
	// size_ft_printf = ft_printf(KCYN"[-3.2d] -------> [%-*.*d].\n", 3, 2, e);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-3.2d] -------> [%-*.*d].\n", 3, 2, d);
	// size_ft_printf = ft_printf(KCYN"[-3.2d] -------> [%-*.*d].\n", 3, 2, d);
	// check_printf(size_ft_printf, size_printf);

	// 	size_printf = printf(KGRN"[-3.2d] -------> [%-*.*d].\n", 3, 2, c);
	// size_ft_printf = ft_printf(KCYN"[-3.2d] -------> [%-*.*d].\n", 3, 2, c);
	// check_printf(size_ft_printf, size_printf);
	// 	size_printf = printf(KGRN"[-3.2d] -------> [%-*.*d].\n", 3, 2, l);
	// size_ft_printf = ft_printf(KCYN"[-3.2d] -------> [%-*.*d].\n", 3, 2, l);
	// check_printf(size_ft_printf, size_printf);
	// 	size_printf = printf(KGRN"[04.10j] -------> [%0*.*d].\n", 4, 10, 1);
	// size_ft_printf = ft_printf(KCYN"[04.10j] -------> [%0*.*d].\n", 4, 10, 1);
	// check_printf(size_ft_printf, size_printf);
	// 	size_printf = printf(KGRN"[-4.3j] -------> [%-*.*d].\n", 4, 3, j);
	// size_ft_printf = ft_printf(KCYN"[-4.3j] -------> [%-*.*d].\n", 4, 3, j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-6.3j] -------> [%-*.*d].\n", 6, 3, j);
	// size_ft_printf = ft_printf(KCYN"[-6.3j] -------> [%-*.*d].\n", 6, 3, j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-10.3j] -------> [%-*.*d].\n", 10, 3, j);
	// size_ft_printf = ft_printf(KCYN"[-10.3j] -------> [%-*.*d].\n", 10, 3, j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-3.2i] -------> [%-*.*i].\n", 3, 2, i);
	// size_ft_printf = ft_printf(KCYN"[-3.2i] -------> [%-*.*i].\n", 3, 2, i);
	// check_printf(size_ft_printf, size_printf);
	// 	size_printf = printf(KGRN"[-3.2d] -------> [%-*.*d].\n", 3, 2, j);
	// size_ft_printf = ft_printf(KCYN"[-3.2d] -------> [%-*.*d].\n", 3, 2, j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-4.2j] -------> [%-*.*d].\n", 4, 2, j);
	// size_ft_printf = ft_printf(KCYN"[-4.2j] -------> [%-*.*d].\n", 4, 2, j);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-5.2d] -------> [%-*.*d].\n", 5, 2, c);
	// size_ft_printf = ft_printf(KCYN"[-5.2d] -------> [%-*.*d].\n", 5, 2, c);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-6.2j] -------> [%-*.*d].\n", 6, 2, j);
	// size_ft_printf = ft_printf(KCYN"[-6.2j] -------> [%-*.*d].\n", 6, 2, j);
	// check_printf(size_ft_printf, size_printf);
	// 	size_printf = printf(KGRN"[015.7j] -------> [%0*.*d].\n", 15, 7, 1);
	// size_ft_printf = ft_printf(KCYN"[015.7j] -------> [%0*.*d].\n", 15, 7, 1);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-10.4j] -------> [%-*.*d].\n", 10, 4, 1);
	// size_ft_printf = ft_printf(KCYN"[-10.4j] -------> [%-*.*d].\n", 10, 4, 1);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[010.4j] -------> [%0*.*d].\n", 10, 4, 1);
	// size_ft_printf = ft_printf(KCYN"[010.4j] -------> [%0*.*d].\n", 10, 4, 1);
	// check_printf(size_ft_printf, size_printf);
	// size_printf = printf(KGRN"[-15.7j] -------> [%-*.*d].\n", 15, 7, 1);
	// size_ft_printf = ft_printf(KCYN"[-15.7j] -------> [%-*.*d].\n", 15, 7, 1);
	// check_printf(size_ft_printf, size_printf);
size_printf = printf(KGRN"[-2.-2 n = abcdefghijklmnop] -------> [%*.*s].\n", -2, -2, n);
	size_ft_printf = ft_printf(KCYN"[-2.-2 n = abcdefghijklmnop] -------> [%*.*s].\n", -2, -2, n);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-2 o = -a] -------> [%*.*s].\n", -2, -2, o);
	size_ft_printf = ft_printf(KCYN"[-2.-2 o = -a] -------> [%*.*s].\n", -2, -2, o);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-2 p = -12] -------> [%*.*s].\n", -2, -2, p);
	size_ft_printf = ft_printf(KCYN"[-2.-2 p = -12] -------> [%*.*s].\n", -2, -2, p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-2 = 0] -------> [%*.*s].\n", -2, -2, q);
	size_ft_printf = ft_printf(KCYN"[-2.-2 = 0] -------> [%*.*s].\n", -2, -2, q);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-2 r = %%] -------> [%*.*s].\n", -2, -2, r);
	size_ft_printf = ft_printf(KCYN"[-2.-2 r = %%] -------> [%*.*s].\n", -2, -2, r);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-2 s = -2147483648] -------> [%*.*s].\n", -2, -2, s);
	size_ft_printf = ft_printf(KCYN"[-2.-2 s = -2147483648] -------> [%*.*s].\n", -2, -2, s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-2 t = 0x12345678] -------> [%*.*s].\n", -2, -2, t);
	size_ft_printf = ft_printf(KCYN"[-2.-2 t = 0x12345678] -------> [%*.*s].\n", -2, -2, t);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-2 u = -0] -------> [%*.*s].\n", -2, -2, u);
	size_ft_printf = ft_printf(KCYN"[-2.-2 u = -0] -------> [%*.*s].\n", -2, -2, u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.0 n = abcdefghijklmnop] -------> [%*.*s].\n", -2, 0, n);
	size_ft_printf = ft_printf(KCYN"[-2.0 n = abcdefghijklmnop] -------> [%*.*s].\n", -2, 0, n);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.0 o = -a] -------> [%*.*s].\n", -2, 0, o);
	size_ft_printf = ft_printf(KCYN"[-2.0 o = -a] -------> [%*.*s].\n", -2, 0, o);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.0 p = -12] -------> [%*.*s].\n", -2, 0, p);
	size_ft_printf = ft_printf(KCYN"[-2.0 p = -12] -------> [%*.*s].\n", -2, 0, p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.0 q = 0] -------> [%*.*s].\n", -2, 0, q);
	size_ft_printf = ft_printf(KCYN"[-2.0 q = 0] -------> [%*.*s].\n", -2, 0, q);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.0 r = %%s] -------> [%*.*s].\n", -2, 0, r);
	size_ft_printf = ft_printf(KCYN"[-2.0 r = %%s] -------> [%*.*s].\n", -2, 0, r);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.0 s = -2147483648s] -------> [%*.*s].\n", -2, 0, s);
	size_ft_printf = ft_printf(KCYN"[-2.0 s = -2147483648s] -------> [%*.*s].\n", -2, 0, s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.0 t = 0x12345678s] -------> [%*.*s].\n", -2, 0, t);
	size_ft_printf = ft_printf(KCYN"[-2.0 t = 0x12345678s] -------> [%*.*s].\n", -2, 0, t);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.0 u = -0s] -------> [%*.*s].\n", -2, 0, u);
	size_ft_printf = ft_printf(KCYN"[-2.0 u = -0s] -------> [%*.*s].\n", -2, 0, u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.1 n = abcdefghijklmnop] -------> [%*.*s].\n", -2, 1, n);
	size_ft_printf = ft_printf(KCYN"[-2.1 n = abcdefghijklmnop] -------> [%*.*s].\n", -2, 1, n);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.1 o = -a] -------> [%*.*s].\n", -2, 1, o);
	size_ft_printf = ft_printf(KCYN"[-2.1 o = -a] -------> [%*.*s].\n", -2, 1, o);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.1 p = -12] -------> [%*.*s].\n", -2, 1, p);
	size_ft_printf = ft_printf(KCYN"[-2.1 p = -12] -------> [%*.*s].\n", -2, 1, p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.1 q = 0] -------> [%*.*s].\n", -2, 1, q);
	size_ft_printf = ft_printf(KCYN"[-2.1 q = 0] -------> [%*.*s].\n", -2, 1, q);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.1 r = %%s] -------> [%*.*s].\n", -2, 1, r);
	size_ft_printf = ft_printf(KCYN"[-2.1 r = %%s] -------> [%*.*s].\n", -2, 1, r);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.1 s = -2147483648s] -------> [%*.*s].\n", -2, 1, s);
	size_ft_printf = ft_printf(KCYN"[-2.1 s = -2147483648s] -------> [%*.*s].\n", -2, 1, s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2. t = 0x12345678s] -------> [%*.*s].\n", -2, 1, t);
	size_ft_printf = ft_printf(KCYN"[-2. t = 0x12345678s] -------> [%*.*s].\n", -2, 1, t);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.1 u = -0s] -------> [%*.*s].\n", -2, 1, u);
	size_ft_printf = ft_printf(KCYN"[-2.1 u = -0s] -------> [%*.*s].\n", -2, 1, u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-1 n = abcdefghijklmnop] -------> [%*.*s].\n", -2, -1, n);
	size_ft_printf = ft_printf(KCYN"[-2.-1 n = abcdefghijklmnop] -------> [%*.*s].\n", -2, -1, n);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-1 o = -a] -------> [%*.*s].\n", -2, -1, o);
	size_ft_printf = ft_printf(KCYN"[-2.-1 o = -a] -------> [%*.*s].\n", -2, -1, o);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-1 p = -12] -------> [%*.*s].\n", -2, -1, p);
	size_ft_printf = ft_printf(KCYN"[-2.-1 p = -12] -------> [%*.*s].\n", -2, -1, p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-1 q = 0] -------> [%*.*s].\n", -2, -1, q);
	size_ft_printf = ft_printf(KCYN"[-2.-1 q = 0] -------> [%*.*s].\n", -2, -1, q);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-1 r = %%] -------> [%*.*s].\n", -2, -1, r);
	size_ft_printf = ft_printf(KCYN"[-2.-1 r = %%] -------> [%*.*s].\n", -2, -1, r);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-1 s = -2147483648] -------> [%*.*s].\n", -2, -1, s);
	size_ft_printf = ft_printf(KCYN"[-2.-1 s = -2147483648] -------> [%*.*s].\n", -2, -1, s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-1 t = 0x12345678] -------> [%*.*s].\n", -2, -1, t);
	size_ft_printf = ft_printf(KCYN"[-2.-1 t = 0x12345678] -------> [%*.*s].\n", -2, -1, t);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-2.-1 u = -0] -------> [%*.*s].\n", -2, -1, u);
	size_ft_printf = ft_printf(KCYN"[-2.-1 u = -0] -------> [%*.*s].\n", -2, -1, u);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0.-2 n = abcdefghijklmnop] -------> [%*.*s].\n", 0, -2, n);
	size_ft_printf = ft_printf(KCYN"[0.-2 n = abcdefghijklmnop] -------> [%*.*s].\n", 0, -2, n);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0.-2 o = -a] -------> [%*.*s].\n", 0, -2, o);
	size_ft_printf = ft_printf(KCYN"[0.-2 o = -a] -------> [%*.*s].\n", 0, -2, o);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0.-2 p = -12] -------> [%*.*s].\n", 0, -2, p);
	size_ft_printf = ft_printf(KCYN"[0.-2 p = -12] -------> [%*.*s].\n", 0, -2, p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0.-2 q = 0] -------> [%*.*s].\n", 0, -2, q);
	size_ft_printf = ft_printf(KCYN"[0.-2 q = 0] -------> [%*.*s].\n", 0, -2, q);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0.-2 r = %%] -------> [%*.*s].\n", 0, -2, r);
	size_ft_printf = ft_printf(KCYN"[0.-2 r = %%] -------> [%*.*s].\n", 0, -2, r);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0.-2 s = -2147483648] -------> [%*.*s].\n", 0, -2, s);
	size_ft_printf = ft_printf(KCYN"[0.-2 s = -2147483648] -------> [%*.*s].\n", 0, -2, s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0.-2 t = 0x12345678] -------> [%*.*s].\n", 0, -2, t);
	size_ft_printf = ft_printf(KCYN"[0.-2 t = 0x12345678] -------> [%*.*s].\n", 0, -2, t);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0.-2 u = -0] -------> [%*.*s].\n", 0, -2, u);
	size_ft_printf = ft_printf(KCYN"[0.-2 u = -0] -------> [%*.*s].\n", 0, -2, u);
	check_printf(size_ft_printf, size_printf);
		size_printf = printf(KGRN"[1.-2 n = abcdefghijklmnop] -------> [%*.*s].\n", 1, -2, n);
	size_ft_printf = ft_printf(KCYN"[1.-2 n = abcdefghijklmnop] -------> [%*.*s].\n", 1, -2, n);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[1.-2 o = -a] -------> [%*.*s].\n", 1, -2, o);
	size_ft_printf = ft_printf(KCYN"[1.-2 o = -a] -------> [%*.*s].\n", 1, -2, o);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[1.-2 p = -12] -------> [%*.*s].\n", 1, -2, p);
	size_ft_printf = ft_printf(KCYN"[1.-2 p = -12] -------> [%*.*s].\n", 1, -2, p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[1.-2 q = 0] -------> [%*.*s].\n", 1, -2, q);
	size_ft_printf = ft_printf(KCYN"[1.-2 q = 0] -------> [%*.*s].\n", 1, -2, q);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[1.-2 r = %%] -------> [%*.*s].\n", 1, -2, r);
	size_ft_printf = ft_printf(KCYN"[1.-2 r = %%] -------> [%*.*s].\n", 1, -2, r);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[1.-2 s = -2147483648] -------> [%*.*s].\n", 1, -2, s);
	size_ft_printf = ft_printf(KCYN"[1.-2 s = -2147483648] -------> [%*.*s].\n", 1, -2, s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[1.-2 t = 0x12345678] -------> [%*.*s].\n", 1, -2, t);
	size_ft_printf = ft_printf(KCYN"[1.-2 t = 0x12345678] -------> [%*.*s].\n", 1, -2, t);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[1.-2 u = -0] -------> [%*.*s].\n", 1, -2, u);
	size_ft_printf = ft_printf(KCYN"[1.-2 u = -0] -------> [%*.*s].\n", 1, -2, u);
	check_printf(size_ft_printf, size_printf);
		size_printf = printf(KGRN"[3.-2 n = abcdefghijklmnop] -------> [%*.*s].\n", 3, -2, n);
	size_ft_printf = ft_printf(KCYN"[3.-2 n = abcdefghijklmnop] -------> [%*.*s].\n", 3, -2, n);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[3.-2 o = -a] -------> [%*.*s].\n", 3, -2, o);
	size_ft_printf = ft_printf(KCYN"[3.-2 o = -a] -------> [%*.*s].\n", 3, -2, o);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[3.-2 p = -12] -------> [%*.*s].\n", 3, -2, p);
	size_ft_printf = ft_printf(KCYN"[3.-2 p = -12] -------> [%*.*s].\n", 3, -2, p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[3.-2 q = 0] -------> [%*.*s].\n", 3, -2, q);
	size_ft_printf = ft_printf(KCYN"[3.-2 q = 0] -------> [%*.*s].\n", 3, -2, q);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[3.-2 r = %%] -------> [%*.*s].\n", 3, -2, r);
	size_ft_printf = ft_printf(KCYN"[3.-2 r = %%] -------> [%*.*s].\n", 3, -2, r);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[3.-2 s = -2147483648] -------> [%*.*s].\n", 3, -2, s);
	size_ft_printf = ft_printf(KCYN"[3.-2 s = -2147483648] -------> [%*.*s].\n", 3, -2, s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[3.-2 t = 0x12345678] -------> [%*.*s].\n", 3, -2, t);
	size_ft_printf = ft_printf(KCYN"[3.-2 t = 0x12345678] -------> [%*.*s].\n", 3, -2, t);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[3.-2 u = -0] -------> [%*.*s].\n", 3, -2, u);
	size_ft_printf = ft_printf(KCYN"[3.-2 u = -0] -------> [%*.*s].\n", 3, -2, u);
	check_printf(size_ft_printf, size_printf);
		size_printf = printf(KGRN"[2.1 n = abcdefghijklmnop] -------> [%*.*s].\n", 2, 1, n);
	size_ft_printf = ft_printf(KCYN"[2.1 n = abcdefghijklmnop] -------> [%*.*s].\n", 2, 1, n);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[2.1 o = -a] -------> [%*.*s].\n", 2, 1, o);
	size_ft_printf = ft_printf(KCYN"[2.1 o = -a] -------> [%*.*s].\n", 2, 1, o);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[2.1 p = -12] -------> [%*.*s].\n", 2, 1, p);
	size_ft_printf = ft_printf(KCYN"[2.1 p = -12] -------> [%*.*s].\n", 2, 1, p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[2.1 q = 0] -------> [%*.*s].\n", 2, 1, q);
	size_ft_printf = ft_printf(KCYN"[2.1 q = 0] -------> [%*.*s].\n", 2, 1, q);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[2.1 r = %%] -------> [%*.*s].\n", 2, 1, r);
	size_ft_printf = ft_printf(KCYN"[2.1 r = %%] -------> [%*.*s].\n", 2, 1, r);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[2.1 s = -2147483648] -------> [%*.*s].\n", 2, 1, s);
	size_ft_printf = ft_printf(KCYN"[2.1 s = -2147483648] -------> [%*.*s].\n", 2, 1, s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[2.1 t = 0x12345678] -------> [%*.*s].\n", 2, 1, t);
	size_ft_printf = ft_printf(KCYN"[2.1 t = 0x12345678] -------> [%*.*s].\n", 2, 1, t);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[2.1 u = -0] -------> [%*.*s].\n", 2, 1, u);
	size_ft_printf = ft_printf(KCYN"[2.1 u = -0] -------> [%*.*s].\n", 2, 1, u);
	check_printf(size_ft_printf, size_printf);
		size_printf = printf(KGRN"[3.-1 n = abcdefghijklmnop] -------> [%*.*s].\n", 3, -1, n);
	size_ft_printf = ft_printf(KCYN"[3.-1 n = abcdefghijklmnop] -------> [%*.*s].\n", 3, -1, n);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[3.-1 o = -a] -------> [%*.*s].\n", 3, -1, o);
	size_ft_printf = ft_printf(KCYN"[3.-1 o = -a] -------> [%*.*s].\n", 3, -1, o);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[3.-1 p = -12] -------> [%*.*s].\n", 3, -1, p);
	size_ft_printf = ft_printf(KCYN"[3.-1 p = -12] -------> [%*.*s].\n", 3, -1, p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[3.-1 q = 0] -------> [%*.*s].\n", 3, -1, q);
	size_ft_printf = ft_printf(KCYN"[3.-1 q = 0] -------> [%*.*s].\n", 3, -1, q);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[3.-1 r = %%] -------> [%*.*s].\n", 3, -1, r);
	size_ft_printf = ft_printf(KCYN"[3.-1 r = %%] -------> [%*.*s].\n", 3, -1, r);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[3.-1 s = -2147483648] -------> [%*.*s].\n", 3, -1, s);
	size_ft_printf = ft_printf(KCYN"[3.-1 s = -2147483648] -------> [%*.*s].\n", 3, -1, s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[3.-1 t = 0x12345678] -------> [%*.*s].\n", 3, -1, t);
	size_ft_printf = ft_printf(KCYN"[3.-1 t = 0x12345678] -------> [%*.*s].\n", 3, -1, t);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[3.-1 u = -0] -------> [%*.*s].\n", 3, -1, u);
	size_ft_printf = ft_printf(KCYN"[3.-1 u = -0] -------> [%*.*s].\n", 3, -1, u);
	check_printf(size_ft_printf, size_printf);
		size_printf = printf(KGRN"[4.-2 n = abcdefghijklmnop] -------> [%*.*s].\n", 4, -2, n);
	size_ft_printf = ft_printf(KCYN"[4.-2 n = abcdefghijklmnop] -------> [%*.*s].\n", 4, -2, n);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[4.-2 o = -a] -------> [%*.*s].\n", 4, -2, o);
	size_ft_printf = ft_printf(KCYN"[4.-2 o = -a] -------> [%*.*s].\n", 4, -2, o);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[4.-2 p = -12] -------> [%*.*s].\n", 4, -2, p);
	size_ft_printf = ft_printf(KCYN"[4.-2 p = -12] -------> [%*.*s].\n", 4, -2, p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[4.-2 q = 0] -------> [%*.*s].\n", 4, -2, q);
	size_ft_printf = ft_printf(KCYN"[4.-2 q = 0] -------> [%*.*s].\n", 4, -2, q);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[4.-2 r = %%] -------> [%*.*s].\n", 4, -2, r);
	size_ft_printf = ft_printf(KCYN"[4.-2 r = %%] -------> [%*.*s].\n", 4, -2, r);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[4.-2 s = -2147483648] -------> [%*.*s].\n", 4, -2, s);
	size_ft_printf = ft_printf(KCYN"[4.-2 s = -2147483648] -------> [%*.*s].\n", 4, -2, s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[4.-2 t = 0x12345678] -------> [%*.*s].\n", 4, -2, t);
	size_ft_printf = ft_printf(KCYN"[4.-2 t = 0x12345678] -------> [%*.*s].\n", 4, -2, t);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[4.-2 u = -0] -------> [%*.*s].\n", 4, -2, u);
	size_ft_printf = ft_printf(KCYN"[4.-2 u = -0] -------> [%*.*s].\n", 4, -2, u);
	check_printf(size_ft_printf, size_printf);
		size_printf = printf(KGRN"[4.-1 n = abcdefghijklmnop] -------> [%*.*s].\n", 4, -1, n);
	size_ft_printf = ft_printf(KCYN"[4.-1 n = abcdefghijklmnop] -------> [%*.*s].\n", 4, -1, n);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[4.-1 o = -a] -------> [%*.*s].\n", 4, -1, o);
	size_ft_printf = ft_printf(KCYN"[4.-1 o = -a] -------> [%*.*s].\n", 4, -1, o);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[4.-1 p = -12] -------> [%*.*s].\n", 4, -1, p);
	size_ft_printf = ft_printf(KCYN"[4.-1 p = -12] -------> [%*.*s].\n", 4, -1, p);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[4.-1 q = 0] -------> [%*.*s].\n", 4, -1, q);
	size_ft_printf = ft_printf(KCYN"[4.-1 q = 0] -------> [%*.*s].\n", 4, -1, q);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[4.-1 r = %%] -------> [%*.*s].\n", 4, -1, r);
	size_ft_printf = ft_printf(KCYN"[4.-1 r = %%] -------> [%*.*s].\n", 4, -1, r);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[4.-1 s = -2147483648] -------> [%*.*s].\n", 4, -1, s);
	size_ft_printf = ft_printf(KCYN"[4.-1 s = -2147483648] -------> [%*.*s].\n", 4, -1, s);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[4.-1 t = 0x12345678] -------> [%*.*s].\n", 4, -1, t);
	size_ft_printf = ft_printf(KCYN"[4.-1 t = 0x12345678] -------> [%*.*s].\n", 4, -1, t);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[4.-1 u = -0] -------> [%*.*s].\n", 4, -1, u);
	size_ft_printf = ft_printf(KCYN"[4.-1 u = -0] -------> [%*.*s].\n", 4, -1, u);
	check_printf(size_ft_printf, size_printf);


	// int		a = -4;
	// int		b = 0;
	// char		c = 'a';
	// int		d = 2147483647;
	// int		e = -2147483648;
	// int		f = 42;
	// int		g = 25;
	// int		h = 4200;
	// int		i = 8;
	// int		j = -12;
	// int		k = 123456789;
	// int		l = 0;
	// int		m = -12345678;
	// char	*n = "abcdefghijklmnop";
	// char	*o = "-a";
	// char	*p = "-12";
	// char	*q = "0";
	// char	*r = "%%";
	// char	*s = "-2147483648";
	// char	*t = "0x12345678";
	// char	*u = "-0";

// ----------Test 381 : ----------
// "%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X" // 1st '*' = -1, 2nd '*' = 0

// 1c1
// < 8, 8, 8, 4294967284, fffffff4, FFFFFFF4, 123456789, 75bcd15, 75BCD15, 0, 0, 0, 4282621618, ff439eb2, FF439EB2, 97, 61, 61, 2147483647, 7fffffff, 7FFFFFFF, 2147483648, 80000000, 80000000 --- Return : 185
// ---
// > 8, 8, 8, 4294967284, fffffff4, FFFFFFF4, 123456789, 75bcd15, 75BCD15,  ,  ,  , 4282621618, ff439eb2, FF439EB2, 97, 61, 61, 2147483647, 7fffffff, 7FFFFFFF, 2147483648, 80000000, 80000000 --- Return : 185


//////////// faux
printf(KRED"\n\t///!\\\\\\FAUX///!\\\\\\\n\n");


	size_printf = printf(KGRN"[-1.0 i = 8] -------> [%*.*u].\n", -1, 0, i);
	size_ft_printf = ft_printf(KCYN"[-1.0 i = 8] -------> [%*.*u].\n", -1, 0, i);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-1.0 i = 0] -------> [%*.*x].\n", -1, 0, i);
	size_ft_printf = ft_printf(KCYN"[-1.0 i = 0] -------> [%*.*x].\n", -1, 0, i);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-1.0 i = 0] -------> [%*.*X].\n", -1, 0, i);
	size_ft_printf = ft_printf(KCYN"[-1.0 i = 0] -------> [%*.*X].\n", -1, 0, i);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"[-1.0 j = 8] -------> [%*.*u].\n", -1, 0, j);
	size_ft_printf = ft_printf(KCYN"[-1.0 j = 8] -------> [%*.*u].\n", -1, 0, j);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-1.0 j = 0] -------> [%*.*x].\n", -1, 0, j);
	size_ft_printf = ft_printf(KCYN"[-1.0 j = 0] -------> [%*.*x].\n", -1, 0, j);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-1.0 j = 0] -------> [%*.*X].\n", -1, 0, j);
	size_ft_printf = ft_printf(KCYN"[-1.0 j = 0] -------> [%*.*X].\n", -1, 0, j);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"[-1.0 k = 8] -------> [%*.*u].\n", -1, 0, k);
	size_ft_printf = ft_printf(KCYN"[-1.0 k = 8] -------> [%*.*u].\n", -1, 0, k);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-1.0 k = 0] -------> [%*.*x].\n", -1, 0, k);
	size_ft_printf = ft_printf(KCYN"[-1.0 k = 0] -------> [%*.*x].\n", -1, 0, k);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-1.0 k = 0] -------> [%*.*X].\n", -1, 0, k);
	size_ft_printf = ft_printf(KCYN"[-1.0 k = 0] -------> [%*.*X].\n", -1, 0, k);
	check_printf(size_ft_printf, size_printf);

		size_printf = printf(KGRN"[-1.0 l = 8] -------> [%*.*u].\n", -1, 0, l);
	size_ft_printf = ft_printf(KCYN"[-1.0 l = 8] -------> [%*.*u].\n", -1, 0, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-1.0 l = 0] -------> [%*.*x].\n", -1, 0, l);
	size_ft_printf = ft_printf(KCYN"[-1.0 l = 0] -------> [%*.*x].\n", -1, 0, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-1.0 l = 0] -------> [%*.*X].\n", -1, 0, l);
	size_ft_printf = ft_printf(KCYN"[-1.0 l = 0] -------> [%*.*X].\n", -1, 0, l);
	check_printf(size_ft_printf, size_printf);
	
			size_printf = printf(KGRN"[0-1.0 l = 8] -------> [%0*.*u].\n", -1, 0, l);
	size_ft_printf = ft_printf(KCYN"[0-1.0 l = 8] -------> [%0*.*u].\n", -1, 0, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0-1.0 l = 0] -------> [%0*.*x].\n", -1, 0, l);
	size_ft_printf = ft_printf(KCYN"[0-1.0 l = 0] -------> [%0*.*x].\n", -1, 0, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0-1.0 l = 0] -------> [%0*.*X].\n", -1, 0, l);
	size_ft_printf = ft_printf(KCYN"[0-1.0 l = 0] -------> [%0*.*X].\n", -1, 0, l);
	check_printf(size_ft_printf, size_printf);

		size_printf = printf(KGRN"[0-1.-1 l = 8] -------> [%0*.*u].\n", -1, -1, l);
	size_ft_printf = ft_printf(KCYN"[0-1.-1 l = 8] -------> [%0*.*u].\n", -1, -1, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0-1.-1 l = 0] -------> [%0*.*x].\n", -1, -1, l);
	size_ft_printf = ft_printf(KCYN"[0-1.-1 l = 0] -------> [%0*.*x].\n", -1, -1, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0-1.-1 l = 0] -------> [%0*.*X].\n", -1, -1, l);
	size_ft_printf = ft_printf(KCYN"[0-1.-1 l = 0] -------> [%0*.*X].\n", -1, -1, l);
	check_printf(size_ft_printf, size_printf);


 			size_printf = printf(KGRN"[-1.1 l = 8] -------> [%*.*u].\n", -1, 1, l);
	size_ft_printf = ft_printf(KCYN"[-1.1 l = 8] -------> [%*.*u].\n", -1, 1, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-1.1 l = 0] -------> [%*.*x].\n", -1, 1, l);
	size_ft_printf = ft_printf(KCYN"[-1.1 l = 0] -------> [%*.*x].\n", -1, 1, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-1.1 l = 0] -------> [%*.*X].\n", -1, 1, l);
	size_ft_printf = ft_printf(KCYN"[-1.1 l = 0] -------> [%*.*X].\n", -1, 1, l);
	check_printf(size_ft_printf, size_printf);

 			size_printf = printf(KGRN"[-1.5 l = 8] -------> [%*.*u].\n", -1, 5, l);
	size_ft_printf = ft_printf(KCYN"[-1.5 l = 8] -------> [%*.*u].\n", -1, 5, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-1.5 l = 0] -------> [%*.*x].\n", -1, 5, l);
	size_ft_printf = ft_printf(KCYN"[-1.5 l = 0] -------> [%*.*x].\n", -1, 5, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[-1.5 l = 0] -------> [%*.*X].\n", -1, 5, l);
	size_ft_printf = ft_printf(KCYN"[-1.5 l = 0] -------> [%*.*X].\n", -1, 5, l);
	check_printf(size_ft_printf, size_printf);

			size_printf = printf(KGRN"[0-1 l = 8] -------> [%0*u].\n", -1, l);
	size_ft_printf = ft_printf(KCYN"[0-1 l = 8] -------> [%0*u].\n", -1, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0-1 l = 0] -------> [%0*x].\n", -1, l);
	size_ft_printf = ft_printf(KCYN"[0-1 l = 0] -------> [%0*x].\n", -1, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0-1 l = 0] -------> [%0*X].\n", -1, l);
	size_ft_printf = ft_printf(KCYN"[0-1 l = 0] -------> [%0*X].\n", -1, l);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"[0.0 l = 8] -------> [%*.*u].\n", 0, 0, l);
	size_ft_printf = ft_printf(KCYN"[0.0 l = 8] -------> [%*.*u].\n", 0, 0, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0.0 l = 0] -------> [%*.*x].\n", 0, 0, l);
	size_ft_printf = ft_printf(KCYN"[0.0 l = 0] -------> [%*.*x].\n", 0, 0, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[0.0 l = 0] -------> [%*.*X].\n", 0, 0, l);
	size_ft_printf = ft_printf(KCYN"[0.0 l = 0] -------> [%*.*X].\n", 0, 0, l);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"[1.0 l = 8] -------> [%*.*u].\n", 1, 0, l);
	size_ft_printf = ft_printf(KCYN"[1.0 l = 8] -------> [%*.*u].\n", 1, 0, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[1.0 l = 0] -------> [%*.*x].\n", 1, 0, l);
	size_ft_printf = ft_printf(KCYN"[1.0 l = 0] -------> [%*.*x].\n", 1, 0, l);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[1.0 l = 0] -------> [%*.*X].\n", 1, 0, l);
	size_ft_printf = ft_printf(KCYN"[1.0 l = 0] -------> [%*.*X].\n", 1, 0, l);
	check_printf(size_ft_printf, size_printf);

			size_printf = printf(KGRN"[42.25 l = 8] -------> [%*.*u].\n", 42, 25, e);
	size_ft_printf = ft_printf(KCYN"[42.25 l = 8] -------> [%*.*u].\n", 42, 25, e);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[42.25 l = 0] -------> [%*.*x].\n", 42, 25, e);
	size_ft_printf = ft_printf(KCYN"[42.25 l = 0] -------> [%*.*x].\n", 42, 25, e);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[42.25 l = 0] -------> [%*.*X].\n", 42, 25, e);
	size_ft_printf = ft_printf(KCYN"[42.25 l = 0] -------> [%*.*X].\n", 42, 25, e);
	check_printf(size_ft_printf, size_printf);

	size_printf = printf(KGRN"[42.25 l = 8] -------> [%*.*u].\n", 42, 25, j);
	size_ft_printf = ft_printf(KCYN"[42.25 l = 8] -------> [%*.*u].\n", 42, 25, j);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[42.25 l = 0] -------> [%*.*x].\n", 42, 25, j);
	size_ft_printf = ft_printf(KCYN"[42.25 l = 0] -------> [%*.*x].\n", 42, 25, j);
	check_printf(size_ft_printf, size_printf);
	size_printf = printf(KGRN"[42.25 l = 0] -------> [%*.*X].\n", 42, 25, j);
	size_ft_printf = ft_printf(KCYN"[42.25 l = 0] -------> [%*.*X].\n", 42, 25, j);
	check_printf(size_ft_printf, size_printf);



	return (0);
}
