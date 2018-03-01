/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:20:36 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/08 16:59:24 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*tdst;
	char	*tsrc;
	int		i;

	tdst = (char *)dst;
	tsrc = (char *)src;
	i = 0;
	if (n > 0)
	{
		while (n != 0)
		{
			if (tsrc[i] != c)
				tdst[i] = tsrc[i];
			else
			{
				tdst[i] = c;
				return (&tdst[i + 1]);
			}
			i++;
			n--;
		}
	}
	return (0);
}
