/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int_d_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:43:34 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/02 13:43:47 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    conv_int(va_list ap, t_struct flag)
{
    int i;
    int arg_int;

    i = 0;
    arg_int = 0;
	(void)flag;
	(void)ap;
	to_flag(flag, ap);
}

int		ft_len_int(long n)
{
	int len_int;

	len_int = 0;
    if (n < 0)
        n = -n;
	while (n >= 10)
	{
		n /= 10;
		len_int++;
	}
	return (len_int + 1);
}

char	*ft_itoa(int n, t_struct *ntm)
{
	char	*dst;
	long	nb;
	int		len;

	nb = n;
	len = ft_len_int(nb) + (n < 0);
	if (!(dst = (char*)malloc(sizeof(char) * len + 1 + (n < 0))))
		return (NULL);
	if (nb < 0)
    {
		dst[0] = '-';
    	nb = -nb;
    }
	dst[len--] = '\0';
	while (nb >= 10)
	{
		dst[len] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	dst[len] = (nb % 10) + '0';
	ft_putstr(dst, ntm);
	return (dst);
}