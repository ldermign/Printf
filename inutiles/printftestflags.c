/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printftestflags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:01:20 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/12 22:31:16 by ldermign         ###   ########.fr       */
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
    printf(KGRN"\t\t//!\\\\NEUTRE//!\\\\\n");
	printf(KGRE"Taille = %d.\n", printf(KGRN"positif, pas de flag -----------------> [d : %d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KGRN"positif, pas de flag -----------------> [d : %d].\n", test2));
    printf(KGRE"Taille = %d.\n", printf(KGRN"positif, width sup -------------------> [d : %10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KGRN"negatif, width sup -------------------> [d : %1d].\n", test2));
    printf(KGRN"\t\t//!\\\\ZERO//!\\\\\n");
	printf(KGRE"Taille = %d.\n", printf(KGRN"positif, zero, width sup -------------> [d : %010d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KGRN"negatif, zero, width sup -------------> [d : %010d].\n", test2));
    printf(KGRN"\t\t//!\\\\MOINS//!\\\\\n");
	printf(KGRE"Taille = %d.\n", printf(KGRN"positif, moins, width sup ------------> [d : %-10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KGRN"negatif, moins, width sup ------------> [d : %-10d].\n", test2));
	printf(KGRN"\t\t//!\\\\PRECISION//!\\\\\n");
	printf(KGRE"Taille = %d.\n", printf(KGRN"positif, zero, width sup, preci sup str & sup width --> [d : %010.15d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KGRN"positif, zero, width sup, preci sup str & inf a width --> [d : %10.30d].\n", test1));

    printf(KGRE"Taille = %d.\n", printf(KGRN"negatif, zero, width sup, preci sup str & sup width --> [d : %010.15d].\n", test2));
    printf(KGRE"Taille = %d.\n", printf(KGRN"positif, zero, width sup, precis sup str & inf width -------------> [d : %010.5d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KGRN"negatif, zero, width sup, precis sup str & inf width -------------> [d : %010.5d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"positif, zero, width sup, precis inf str & inf width -------------> [d : %010.1d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KGRN"negatif, zero, width sup, precis inf str & inf width -------------> [d : %010.1d].\n", test2));
    
	printf(KGRE"Taille = %d.\n", printf(KGRN"positif, zero, width inf, preci sup str & sup width -------------> [d : %01.10d].\n", test1));
    printf(KGRE"Taille = %d.\n", printf(KGRN"positif, moins, width sup, precis sup str & inf width ------------> [d : %-10.5d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KGRN"positif, moins, width sup, precis inf str & inf width ------------> [d : %-10.1d].\n", test1));
    printf(KGRE"Taille = %d.\n", printf(KGRN"negatif, zero, width inf, preci sup str & sup width -------------> [d : %01.10d].\n", test2));
    printf(KGRE"Taille = %d.\n", printf(KGRN"negatif, moins, width sup, precis sup str & inf width ------------> [d : %-10.5d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"negatif, moins, width sup, precis inf str & inf width ------------> [d : %-10.1d].\n", test2));
    
    printf(KGRE"Taille = %d.\n", printf(KGRN"positif, moins, width sup, preci sup str & sup width ------------> [d : %-10.15d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KGRN"positif, moins, width et precis egales, sup ------------> [d : %-10.10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KGRN"negatif, moins, width sup, preci sup str & sup width ------------> [d : %-10.15d].\n", test2));
	printf(KGRE"Taille = %d.\n", printf(KGRN"negatif, moins, width et precis egales, sup ------------> [d : %-10.10d].\n", test2));
    
	printf(KGRE"Taille = %d.\n", printf(KGRN"positif, width sup, preci sup str & sup width -------------------> [d : %10.15d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KGRN"negatif, width sup, precis sup str & inf width -------------------> [d : %10.5d].\n", test2));
    printf(KGRE"Taille = %d.\n", printf(KGRN"positif, width et precis egales, sup a str -------------------> [d : %10.10d].\n", test1));
	printf(KGRE"Taille = %d.\n", printf(KGRN"negatif, width et precis egales, sup a str -------------------> [d : %10.10d].\n", test2));
    return (0);
}