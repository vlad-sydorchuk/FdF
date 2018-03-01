/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:22:41 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/07 14:31:58 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	int		i;

	if (!s)
		return (0);
	ans = (char*)malloc(sizeof(*ans) * (len + 1));
	if (!ans)
		return (0);
	i = 0;
	while (s[start + i] && len != 0)
	{
		ans[i] = s[start + i];
		i++;
		len--;
	}
	ans[i] = '\0';
	return (ans);
}
