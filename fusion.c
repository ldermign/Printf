/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:48:27 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/14 09:50:05 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     check_if_zero_in_str(t_flag_len *flag)
{
    (void)flag;
    return (0);
}

char    *fusion_conv_strflag(char *str, int nbr, t_flag_len *flag)
{
    int     size_str;
    char    *dst;

    size_str = ft_strlen(str);
    if ((dst = malloc(sizeof(char) * ((flag->size_final_str_flag)
    + (nbr < 0)))) == NULL)
        return (NULL);
    // while (str[size])
    // {
        
    // }
    return (NULL);
}