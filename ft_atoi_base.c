/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:35:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/21 13:38:22 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_position(char c, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

int		ft_strlen(char *base)
{
	int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

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

int		ft_atoi_base(char *str, char *base)
{
	int neg;
	int nbr;

	neg = 0;
	nbr = 0;
	if (!(ft_base_valid(base)))
		return (0);
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	while (*str && ft_position(*str, base) != -1)
	{
		nbr = nbr * ft_strlen(base) + ft_position(*str, base);
		str++;
	}
	if (neg % 2 != 0)
		nbr *= -1;
	return (nbr);
}
