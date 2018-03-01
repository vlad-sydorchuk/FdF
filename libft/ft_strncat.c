/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:51:46 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/08 17:00:36 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	char *tmp;

	tmp = s1;
	while (*tmp)
		tmp++;
	while (*s2 && len > 0)
	{
		*tmp++ = *s2++;
		len--;
	}
	*tmp = '\0';
	return (s1);
}
