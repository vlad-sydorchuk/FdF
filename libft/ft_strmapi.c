/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:22:42 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/07 14:35:18 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*q;
	unsigned int	i;

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
			q[i] = f(i, s[i]);
			i++;
		}
		q[i] = '\0';
		return (q);
	}
	return (0);
}
