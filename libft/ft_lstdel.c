/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:43:03 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/09 14:05:13 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if ((*alst) && del)
		while ((*alst) != NULL)
		{
			tmp = (*alst);
			(*alst) = (*alst)->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
		}
}
