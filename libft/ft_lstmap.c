/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:03:13 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/09 14:45:35 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*begin;

	if (!(lst && f))
		return (NULL);
	tmp = f(lst);
	lst = lst->next;
	begin = tmp;
	while (lst)
	{
		tmp->next = f(lst);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (begin);
}
