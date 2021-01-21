/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:36:24 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/21 13:37:47 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_base_valid(char *str)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' || str[i] < 32 || str[i] > 126)
			return (0);
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	if (ft_strlen(str) < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long nb;
	long size;

	nb = nbr;
	if (!(ft_base_valid(base)))
		return ;
	size = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb < size)
		ft_putchar(base[nb]);
	if (nb >= size)
	{
		ft_putnbr_base((nb / size), base);
		ft_putnbr_base((nb % size), base);
	}
}
