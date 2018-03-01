/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:40:02 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/08 09:41:51 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		words(const char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		j++;
	}
	return (j);
}

static	char	**copy(char **str, const char *s, char c)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		n = 0;
		while (s[i] != c && s[i] != '\0')
			str[j][n++] = s[i++];
		str[j][n] = '\0';
		j++;
	}
	str[j] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		d;

	if (!s)
		return (0);
	if (!(str = (char **)malloc(sizeof(str) * (words(s, c) + 1))))
		return (0);
	i = 0;
	d = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (s[i] != c && s[i++] != '\0')
			j++;
		str[d] = (char *)malloc(sizeof(char) * (j + 1));
		if (!str[d++])
			return (0);
	}
	return (copy(str, s, c));
}
