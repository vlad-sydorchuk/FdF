/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:47:36 by vsydorch          #+#    #+#             */
/*   Updated: 2017/05/07 16:47:36 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	ft_net(t_crd ***m, t_dim *dim, t_gr *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < (dim->h))
	{
		j = -1;
		while (++j < (dim->w - 1))
		{
			if ((m)[i][j]->x > 0 && (m)[i][j]->y > 0 && (m)[i][j + 1]->x > 0
				&& (m)[i][j + 1]->y > 0)
				ft_brez(*m[i][j], *m[i][j + 1], mlx);
		}
	}
	j = -1;
	while (++j < (dim->w))
	{
		i = -1;
		while (++i < (dim->h - 1))
		{
			if ((m)[i][j]->x > 0 && (m)[i][j]->y > 0 && (m)[i + 1][j]->x > 0
				&& (m)[i + 1][j]->y > 0)
				ft_brez(*m[i][j], *m[i + 1][j], mlx);
		}
	}
}

void			ft_drw(t_crd ***r, t_dim *dim, t_gr *mlx, t_all *all)
{
	int		i;
	int		j;

	i = -1;
	mlx_clear_window(mlx->init, mlx->win);
	draw_info(all->mlx);
	while (++i < dim->h)
	{
		j = -1;
		while (++j < dim->w)
		{
			if (r[i][j]->x > 0 && r[i][j]->y > 0)
				mlx_pixel_put(mlx->init, mlx->win, r[i][j]->x, r[i][j]->y,
					r[i][j]->clr);
		}
	}
	ft_net(r, dim, mlx);
}
