/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:19:29 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/01 22:18:10 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c, t_struct *ntm)
{
	write(1, &c, 1);
	ntm->final_len++;
}

void	ft_putstr(char *str, t_struct *ntm)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(&str[i], &ntm);
		i++;
	}
}

int		ft_len_int(long n)
{
	int len_int;

	len_int = 0;
	n = n < 0 ? -n : n;
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
		dst[0] = '-';
	nb = nb < 0 ? -nb : nb;
	dst[len] = '\0';
	len--;
	while (nb >= 10)
	{
		dst[len] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	dst[len] = (nb % 10) + '0';
	ft_putstr(dst, &ntm);
	return (dst);
}