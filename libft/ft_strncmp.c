/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:09:38 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/08 12:17:59 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ts1;
	unsigned char	*ts2;

	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	if (!ts1 || !ts2)
		return (*ts1 - *ts2);
	else
	{
		while ((*ts1 || *ts2) && n != 0)
		{
			if (*ts1 != *ts2)
				return (*ts1 - *ts2);
			ts1++;
			ts2++;
			n--;
		}
		return (0);
	}
}
