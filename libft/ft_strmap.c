/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:45:34 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/07 14:35:42 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*q;
	int		i;

	if (s)
	{
		i = 0;
		while (s[i])
			i++;
		q = (char*)malloc(sizeof(*q) * (i + 1));
		if (!q)
			return (0);
		i = 0;
		while (s[i])
		{
			q[i] = f(s[i]);
			i++;
		}
		q[i] = '\0';
		return (q);
	}
	return (0);
}
