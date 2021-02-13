/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:48:27 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/14 00:05:57 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     check_if_zero_in_str(t_flag_len *flag)
{
    
}

char    *fusion_conv_strflag(char *str, int nbr, t_flag_len *flag)
{
    int     size_str;
    int     size_str_flag;
    char    *dst;

    size_str = ft_strlen(str);
    size_str_flag = ft_strlen(flag->final_flag);
    if ((dst = malloc(sizeof(char) * ((size_str_flag) + (nbr < 0))) == NULL))
        return (NULL);
    while (str[size])
    {
        
    }
}