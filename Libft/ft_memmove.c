/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:10:59 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/12 08:46:39 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t i;
	size_t n_bytes;

	i = 0;
	n_bytes = n;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		while (n_bytes > 0)
		{
			((char*)dst)[n_bytes - 1] = ((char*)src)[n_bytes - 1];
			n_bytes--;
		}
	}
	else
	{
		while (i < n_bytes)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	}
	return (dst);
}
