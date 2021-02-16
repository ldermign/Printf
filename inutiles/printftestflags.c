/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printftestflags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:01:20 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/16 10:14:32 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#define KRED  "\x1B[0;31m"
#define KGRN  "\x1B[0;32m"
#define KYEL  "\x1B[0;33m"
#define KBLU  "\x1B[0;34m"
#define KMAG  "\x1B[0;35m"
#define KCYN  "\x1B[0;36m"
#define KWHT  "\x1B[0;37m"
#define KGRE  "\x1b[1;30m"

int main()
{
    int test1 = 765;
	int test2 = -765;
	
	printf(KRED"\n\t\t//!\\\\VRAI PRINTF//!\\\\\n");
	printf(KGRE"Taille = %d.\n", printf(KGRN"[\\] ----------> [d : %d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[\\] ----------> [d : %d].\n", test2));
    printf(KGRE"Taille = %d.\n", printf(KGRN"[10] ---------> [d : %10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[10] ---------> [d : %10d].\n", test2));
    printf(KGRE"Taille = %d.\n", printf(KGRN"[10.0] -------> [d : %10.0d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[10.0] -------> [d : %10.0d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[10.30] ------> [d : %10.30d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[10.30] ------> [d : %10.30d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[30.10] ------> [d : %30.10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[30.10] ------> [d : %30.10d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[10.5] -------> [d : %10.5d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[10.5] -------> [d : %10.5d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[010.1] ------> [d : %10.1d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[10.1] -------> [d : %10.1d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[1.10] -------> [d : %1.10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[1.10] -------> [d : %1.10d].\n", test2));
    printf(KGRE"Taille = %d.\n", printf(KGRN"[10.10] ------> [d : %10.10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[10.10] ------> [d : %10.10d].\n", test2));

	printf(KRED"\n\n\t\t//!\\\\ZERO//!\\\\\n");
	printf(KGRE"Taille = %d.\n", printf(KGRN"[010] --------> [d : %010d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[010] --------> [d : %010d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[010.0] ------> [d : %010.0d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[010.0] ------> [d : %010.0d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[010.30] -----> [d : %010.30d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[010.30] -----> [d : %010.30d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[030.10] -----> [d : %030.10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[030.10] -----> [d : %030.10d].\n", test2));
    printf(KGRE"Taille = %d.\n", printf(KGRN"[010.5] ------> [d : %010.5d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[010.5] ------> [d : %010.5d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[010.1] ------> [d : %010.1d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[010.1] ------> [d : %010.1d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[01.10] ------> [d : %01.10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[01.10] ------> [d : %01.10d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[010.10] -----> [d : %010.10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[010.10] -----> [d : %010.10d].\n", test2));

	printf(KRED"\n\n\t\t//!\\\\MOINS//!\\\\\n");
	printf(KGRE"Taille = %d.\n", printf(KGRN"[-10] --------> [d : %-10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[-10] --------> [d : %-10d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[-.10] -------> [d : %-.10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[-.10] -------> [d : %-.10d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[-10.0] ------> [d : %-10.0d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[-10.0] ------> [d : %-10.0d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[-10.30] -----> [d : %-10.30d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[-10.30] -----> [d : %-10.30d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[-30.10] -----> [d : %-30.10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[-30.10] -----> [d : %-30.10d].\n", test2));
    printf(KGRE"Taille = %d.\n", printf(KGRN"[-10.5] ------> [d : %-10.5d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[-10.5] ------> [d : %-10.5d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[-10.1] ------> [d : %-10.1d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[-10.1] ------> [d : %-10.1d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[-1.10] ------> [d : %-1.10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[-1.10] ------> [d : %-1.10d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"[-10.10] -----> [d : %-10.10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KRED"[-10.10] -----> [d : %-10.10d].\n", test2));

    return (0);
}
