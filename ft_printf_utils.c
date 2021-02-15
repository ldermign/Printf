/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:19:29 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/15 16:10:33 by ldermign         ###   ########.fr       */
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



// char	*ft_itoa(size_t nbr)
// {
// 	char	*dst;
// 	size_t	len;

// 	len = ft_len_nb(nbr) + (nbr < 0);
// 	if ((dst = (char*)malloc(sizeof(char) * len + 1 + (nbr < 0))) == NULL)
// 		return (NULL);
// 	if (nbr < 0 && (nbr = -nbr))
// 		*dst = '-';
// 	dst[len] = '\0';
// 	len--;
// 	while (len >= (nbr < 0))
// 	{
// 		dst[len--] = (nbr % 10) + '0';
// 		nbr /= 10;
// 	}
// 	return (dst);
// }

// int		ft_len_int(long n)
// {
// 	int len_int;

// 	len_int = 0;
// 	if (n < 0)
// 		n = -n;
// 	while (n >= 10)
// 	{
// 		n /= 10;
// 		len_int++;
// 	}
// 	return (len_int + 1);
// }

// char	*ft_itoa(int n)
// {
// 	char	*dst;
// 	long	nb;
// 	int		len;

// 	nb = n;
// 	len = ft_len_int(nb) + (nb < 0);
// 	if ((dst = (char*)malloc(sizeof(char) * len + 1 + (n < 0))) == NULL)
// 		return (NULL);
// 	if (nb < 0 && (nb = -nb))
// 		*dst = '-';
// 	dst[len--] = '\0';
// 	while (len >= (n < 0))
// 	{
// 		dst[len--] = (nb % 10) + '0';
// 		nb /= 10;
// 	}
// 	return (dst);
// }

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

// void	ft_putnbr(unsigned int nbr, t_flag_len *len)
// {
// 	if (nbr > 9)
// 	{
// 		ft_putnbr((nbr / 10), len);
// 		ft_putnbr((nbr % 10), len);
// 	}
// 	else
// 		ft_putchar((nbr + '0'), len);
// }

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


// size_t		ft_len_nb(size_t n, size_t base)
// {
// 	size_t len_int;

// 	len_int = 0;
// 	while (n >= base)
// 	{
// 		n /= base;
// 		len_int++;
// 	}
// 	return (len_int + 1);
// }

// char	*ft_itoa_base(size_t nbr, char *base)
// {
// 	size_t	len_nbr;
// 	size_t	size_base;
// 	size_t	nbr_positif;
// 	char	*dst;

// 	size_base = ft_strlen(base);
// 	len_nbr = ft_len_nb(nbr, size_base);
// 	nbr_positif = nbr;
// 	if ((dst = malloc(sizeof(char) * (len_nbr + 1 + (nbr < 0)))) == NULL)
// 		return (NULL);
// 	if (nbr_positif < 0)
// 	{
// 		nbr_positif = -nbr_positif;
// 		len_nbr++;
// 		dst[0] = '-';
// 	}
// 	dst[len_nbr--] = '\0';
// 	while (len_nbr >= size_base)
// 	{
// 		dst[len_nbr--] = ft_itoa_base(nbr_positif % size_base, base);
// 		nbr_positif /= size_base;
// 	}
// 	return (dst);
// }


char	*ft_itoa_base(size_t nbr, char *base)
{
	char	*dst;
	size_t	size_base;
	
	size_base = ft_strlen(base);
	if ((dst = malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	if (nbr >= size_base)
		dst = ft_strjoin(ft_itoa_base(nbr / size_base, base),
		ft_itoa_base(nbr % size_base, base));
	else
	{
		dst[0] = base[nbr];
		dst[1] = '\0';
	}
	return (dst);
}


/*char	*ft_itoa_base(size_t nb, char *base)
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
