/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:19:29 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/14 15:02:05 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned int	len;
	unsigned char	*str;

	i = 0;
	len = nmemb * size;
	if ((str = malloc(len)) == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c, t_flag_len *len)
{
	write(1, &c, 1);
	len->final_len++;
}

void	ft_putstr(char *str, t_flag_len *len)
{
	size_t size;

	if (!str)
		return ;
	size = ft_strlen(str);
	write(1, str, size);
	len->final_len += (int)size;
}
void	ft_fill_with_c(char *str, char c, int size)
{
	int i;

	i = 0;
	while (i < (size - 1))
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
}

void	*ft_memmove(char *dst, char *src, size_t n)
{
	size_t i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (n > 0)
		{
			((char*)dst)[n - 1] = ((char*)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	}
	return (dst);
}

void	*fill_from_end(char *dst, char *src, size_t n)
{
	size_t from_last;

	from_last = n;
	if (!dst && !src)
		return (NULL);
	while (from_last > 0)
	{
		dst[from_last] = src[from_last];
		from_last--;
	}
	return (dst);
}

int		ft_len_nb(long n)
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

char	*ft_itoa(int nb)
{
	char	*dst;
	long	nb_long;
	int		len;

	nb_long = nb;
	len = ft_len_nb(nb_long) + (nb_long < 0);
	if ((dst = (char*)malloc(sizeof(char) * len + 1 + (nb < 0))) == NULL)
		return (NULL);
	if (nb_long < 0 && (nb_long = -nb_long))
		*dst = '-';
	dst[len--] = '\0';
	while (len >= (nb < 0))
	{
		dst[len--] = (nb_long % 10) + '0';
		nb_long /= 10;
	}
	return (dst);
}

int	ft_atoi_printf(char *str)
{
	int i;
	int neg;
	int nbr;

	i = 0;
	neg = 0;
	nbr = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	if (neg % 2 != 0)
		nbr *= -1;
	return (nbr);
}

void	ft_putnbr_base_printf(long nbr, char *base, t_flag_len *len)
{
	long size_base;

	size_base = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr *= -1;
	}
	if (nbr < size_base)
		ft_putchar(base[nbr], len);
	if (nbr >= size_base)
	{
		ft_putnbr_base_printf((nbr / size_base), base, len);
		ft_putnbr_base_printf((nbr % size_base), base, len);
	}
}

void	ft_putnbr(unsigned int nbr, t_flag_len *len)
{
	if (nbr > 9)
	{
		ft_putnbr((nbr / 10), len);
		ft_putnbr((nbr % 10), len);
	}
	else
		ft_putchar((nbr + '0'), len);
}

void	ft_putnbr_adr(unsigned long nbr, t_flag_len *len)
{
	char *base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_putnbr_adr((nbr / 16), len);
		ft_putnbr_adr((nbr % 16), len);
	}
	else
		ft_putchar(base[nbr], len);
}

char	*ft_strcat(char *dst, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

char	*ft_strncat(char *dst, char *src, size_t nb)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	// if (dst == NULL || src == NULL || nb < 0)
	// 	return (NULL);
	while (dst[i])
		i++;
	while (src[j] && j < nb)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;
	int		size_tot;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = -1;
	j = -1;
	size_tot = ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1;
	if ((dst = (char*)malloc(sizeof(char) * size_tot)) == NULL)
		return (NULL);
	while (s1[++i])
		dst[i] = s1[i];
	while (s2[++j])
	{
		dst[i] = s2[j];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_atoi(char *str)
{
	int i;
	int neg;
	int nbr;

	i = 0;
	neg = 0;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	if (neg % 2 != 0)
		nbr *= -1;
	return (nbr);
}


/*
int		ft_position(char c, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
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
		nbr *= ft_strlen(base) + ft_position(*str, base);
		str++;
	}
	if (neg % 2 != 0)
		nbr *= -1;
	return (nbr);
}

char	*ft_itoa_base(size_t nb, char *base)
{
	long	nb_long;
	int		size_base;
	int		len_nb;
	char	*dst;

	nb_long = nb;
	size_base = ft_strlen(base);
	len_nb = ft_len_nb(nb);
	if ((size_base < 2 || ((dst = malloc(sizeof(char) * len_nb + 1)) == NULL)))
		return (NULL);
	if (nb < 0)
	{
		dst[0] = '-';
		nb_long = -nb_long;
	}
	dst[len_nb--] = '\0';
	while (len_nb >= (nb < 0))
	{
		dst[len_nb--] = (nb_long % size_base) + '0';
		nb_long /= size_base;
	}
	return (dst);
}*/
