/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 14:20:15 by vsydorch          #+#    #+#             */
/*   Updated: 2017/05/07 14:20:18 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		len_w(char const *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static int		num_w(char const *str, char c)
{
	int	num_w;
	int	i;

	i = 0;
	num_w = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			num_w++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (num_w);
}

static char		*new_w(char const *str, char c)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = len_w(str, c);
	new = (char *)malloc(sizeof(char) * (len + 1));
	while (str[i] && str[i] != c)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char			**ft_split_cl(char const *str, char c)
{
	char	**words;
	int		i;
	int		j;
	int		nw;

	if (!(str))
		return (0);
	nw = num_w(str, c);
	if (!(words = (char **)malloc(sizeof(char *) * (nw + 1))))
		return (0);
	i = 0;
	j = 0;
	while (str[j])
	{
		while (str[j] == c)
			j++;
		if (!str[j])
			break ;
		words[i] = new_w(str + j, c);
		i++;
		while (str[j] != c && str[j])
			j++;
	}
	words[i] = 0;
	return (words);
}
