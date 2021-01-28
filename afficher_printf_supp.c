/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_printf_supp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:47:47 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/28 15:56:21 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	afficher_struct_flags(t_flags flags)
// afficher structure flag
{
	printf("\nStructure flag :\n");
	printf("	minus = %d\n", flags.minus);
	printf("	padded_zero = %d\n", flags.padded_zero);
	printf("	widht = %d\n", flags.widht);
	printf("	precision = %d\n", flags.precision);
}

void	afficher_struct_conv(t_conversion conv)
// afficher structure de conversion
{
	printf("\nStructure conversion :\n");
	printf("	cara_c = %d\n", conv.cara_c);
	printf("	string_s = %d\n", conv.string_s);
	printf("	point_ad_hex_p = %d\n", conv.point_ad_hex_p);
	printf("	int_dec_d = %d\n", conv.int_dec_d);
	printf("	int_dec_i = %d\n", conv.int_dec_i);
	printf("	unsd_int_u = %d\n", conv.unsd_int_u);
	printf("	unsd_hex_x = %d\n", conv.unsd_hex_x);
	printf("	unsd_hex_X = %d\n", conv.unsd_hex_X);
}
