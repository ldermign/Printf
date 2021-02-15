/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:57:13 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/15 09:28:10 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    flag_precision(t_flag_len *flag)
{
    int     i;
    int     precision;
    
    i = 0;
    precision = flag->nbr_precision;
    if (!(flag->str_precision = ft_calloc(precision + 1, sizeof(char))))
        return ;
    ft_fill_with_c(flag->str_precision, '0', precision + 1);
}

void    flag_width(t_flag_len *flag)
{
    int i;
    int width;

    i = 0;
    width = flag->nbr_width;
    if (!(flag->str_width = ft_calloc(width + 1, sizeof(char))))
        return ;
    ft_fill_with_c(flag->str_width, ' ', width + 1);
}