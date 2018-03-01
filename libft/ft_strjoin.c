/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:59:54 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/07 14:39:04 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	int		i;
	int		j;

	if (!(s1 && s2))
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	ans = (char *)malloc(sizeof(*ans) * (i + j + 1));
	if (!ans)
		return (0);
	i = -1;
	j = -1;
	while (s1 && s1[++i])
		ans[i] = s1[i];
	while (s2 && s2[++j])
		ans[i + j] = s2[j];
	ans[i + j] = '\0';
	return (ans);
}
