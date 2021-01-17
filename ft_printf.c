/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/15 13:44:14 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	ft_putstr(const char *str);

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}



#include <libc.h>

/*void	ft_afficher(const char *str)
{
	int size;
	int i;

	size = 0;
	i = 0;
//	printf("Voici la chaine :");
//	ft_putstr(str);
	printf("\n");
	while (str[size])
		size++;
	printf("Taille de la chaine envoyee = %d.\n", size);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '0'
				|| str[i] == '#')
			printf("Il y a un flag : %c", str[i]);
		i++;
	}
}*/

void	ft_init_struct(t_flags *newVar)
{
	newVar->minus = 0;
	newVar->padded_zero = 0;
	newVar->sign_number = 0;
	newVar->space = 0;
	newVar->prefix = 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/*void	ft_putnbr(int nb)
{
	long nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

int		ft_size_str(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}*/

/*
 *	fonction pour preciser la conversion ?
 *	ou renvoit ce qui a ete convertit (non ! trop de diff)
 */

/*void	ft_conversion(char c)
{
	if (c == 'c')
		ft_print_char();
	else if (c == 's')
		ft_print_string();
	else if (c == 'p')
		ft_();
	else if (c == 'd')
		ft_();
	else if (c == 'i')
		ft_();
	else if (c == 'u')
		ft_();
	else if (c == 'x' || c == 'X')
		ft_();
	else if (c == '%')
		ft_print_percentage();
}*/

/*
 *	fonction pour les flags
 *	si doublon, tej ? 
 *
 *
 */

void	ft_flags(const char *str, t_flags *newVar)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '-')
				newVar->minus = 1;
			if (str[i] == '+')
				newVar->sign_number = 1;
			if (str[i] == ' ')
				newVar->space = 1;
			if (str[i] == '0')
				newVar->padded_zero = 1;
			if (str[i] == '#')
				newVar->prefix = 1;
			if (str[i] != '-' && str[i] != '+' && str[i] != ' ' && str[i] != '0'
					&& str[i] != '#')
				break ;
			i++;
		}
	}
}

/*
 *	fonction pour afficher pourcentage
 *	flags pas pris en compte !!!!
 */

/*int		ft_percentage()
{}

char	ft_print_char()
{}

char	*ft_print_string()
{}

void	ft_flag()
{}*/

/*
 *	... == nombre variable d'arguments, oblige d'utiliser va_arg,start,end,list 
 *	pour y acceder
 *
 */

int	ft_printf(const char *str, ...)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	va_list ap;
	va_start (ap, str);
	t_flags newVar;
	ft_init_struct(&newVar);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_flags(&str[i], &newVar);
			break ;
		}
		else if (str[i] == '\0')
			ft_putstr(str);
		i++;
	}
	printf("minus = %d\n", newVar.minus);
	printf("sign_number = %d\n", newVar.sign_number);
	printf("space = %d\n", newVar.space);
	printf("padded_zero = %d\n", newVar.padded_zero);
	printf("prefix = %d\n", newVar.prefix);
	va_end(ap);
	return (ft_strlen(str));
}

int main ()
{
	int i;

	i = 0;
	ft_printf("On va tester cette merde");
	return (0);
}
