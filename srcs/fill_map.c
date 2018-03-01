/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 13:35:55 by vsydorch          #+#    #+#             */
/*   Updated: 2017/05/07 13:35:56 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	ft_dim(t_dim **dim)
{
	(*dim)->zm = WW / 6 / (*dim)->w;
	if ((*dim)->zm == 0)
		(*dim)->zm = 0.5;
	(*dim)->st = (*dim)->zm / 6;
	(*dim)->al = 315;
	(*dim)->p = 315;
}

static	void	ft_fr(char ***b)
{
	int		i;

	i = -1;
	while ((*b)[++i])
		free((*b)[i]);
	free(*b);
}

int				fill_m(t_crd ****res, char ***a, t_dim **dim, int r)
{
	int		c;
	char	**b;

	c = -1;
	while ((*a)[++c])
	{
		if (!((*res)[r][c] = (t_crd *)malloc(sizeof(t_crd))))
			return (-1);
		b = ft_split_cl((*a)[c], ',');
		(*res)[r][c]->x = c;
		(*res)[r][c]->y = r;
		(*res)[r][c]->z = ft_atoi(b[0]);
		if (b[1])
			(*res)[r][c]->clr = ft_atoi_base(&b[1][2], 16);
		else
			(*res)[r][c]->clr = ft_atoi_base("FFFFFF", 16);
		ft_fr(&b);
	}
	ft_dim(&(*dim));
	return (0);
}
