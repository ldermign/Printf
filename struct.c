/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:46:59 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/01 21:47:12 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct_flag(t_struct *ntm)
// initialiser structure de ntm
{
	ntm->minus = -1;
	ntm->padded_zero = -1;
	ntm->widht = -1;
	ntm->precision = -1;
}

int which_flag(const char *str, t_struct *ntm)
{
	int avancement;

	avancement = ft_strlen(str);
	ft_init_struct_flag(ntm);
	if (str)
	{
		str++;
		while (ft_is_flag(*str))
		{
			if (*str == '-')
				ntm->minus = 1;
			if (*str == '0')
				ntm->padded_zero = 1;
			if (*str == '*' || (ft_is_digit(*str) && *(str + 1) == '.'))
			{
				ntm->widht = 1;
				while (*str == '*' || ft_is_digit(*str))
					str++;
				if ((*str == '.' && ft_is_digit(*str + 1))
				|| *(str + 1) == '*')
					ntm->precision = 1;
			}
			str++;
		}
	}
	afficher_struct_flags(*ntm);
	return (avancement -= ft_strlen(str));
}