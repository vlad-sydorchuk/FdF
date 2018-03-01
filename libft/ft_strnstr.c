/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:17:05 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/08 12:54:35 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	j;
	size_t	lenlit;

	i = 0;
	lenlit = 0;
	while (little[lenlit])
		lenlit++;
	if (lenlit == 0)
		return ((char *)&big[i]);
	while (big[i] != '\0' && len > i)
	{
		j = i;
		k = 0;
		while (big[j] && big[j] == little[k] && len > j)
		{
			j++;
			k++;
			if (k == lenlit)
				return ((char *)&big[j - lenlit]);
		}
		i++;
	}
	return (0);
}
