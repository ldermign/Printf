/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:31:27 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/12 08:47:43 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_free(char **str)
{
	int i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int				ft_len_word(const char *s, char c)
{
	int	len;
	int i;

	len = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

int				ft_nbword(const char *s, char c)
{
	int i;
	int	word_count;
	int	count_switch;

	i = 0;
	word_count = 0;
	count_switch = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			count_switch = 0;
		else if (count_switch == 0)
		{
			count_switch = 1;
			word_count++;
		}
		i++;
	}
	return (word_count);
}

char			**ft_split(char const *s, char c)
{
	char	**dests;
	int		i;
	int		j;
	int		size;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	size = 0;
	if ((dests = (char**)malloc(sizeof(char*) * (ft_nbword(s, c) + 1))) == NULL)
		return (ft_free(dests));
	while (s[i] && j < ft_nbword(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		size = ft_len_word(&s[i], c);
		if ((dests[j] = (char*)malloc(sizeof(char) * size + 1)) == NULL)
			return (ft_free(dests));
		ft_strlcpy(dests[j], &s[i], size + 1);
		j++;
		i += size;
	}
	dests[j] = NULL;
	return (dests);
}
