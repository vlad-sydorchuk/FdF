/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:32:15 by vsydorch          #+#    #+#             */
/*   Updated: 2017/05/07 16:32:16 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_brez(t_crd d1, t_crd d2, t_gr *mlx)
{
	t_brez	*brez;

	brez = (t_brez *)malloc(sizeof(t_brez));
	brez->dx = abs((int)d2.x - (int)d1.x);
	brez->dy = abs((int)d2.y - (int)d1.y);
	brez->sx = (d1.x < d2.x) ? 1 : -1;
	brez->sy = (d1.y < d2.y) ? 1 : -1;
	brez->err0 = brez->dx - brez->dy;
	while ((int)d1.x != (int)d2.x || (int)d1.y != (int)d2.y)
	{
		brez->err1 = brez->err0 * 2;
		if (brez->err1 > -brez->dy)
		{
			brez->err0 -= brez->dy;
			d1.x += brez->sx;
		}
		if (brez->err1 < brez->dx)
		{
			brez->err0 += brez->dx;
			d1.y += brez->sy;
		}
		mlx_pixel_put(mlx->init, mlx->win, (int)d1.x, (int)d1.y, d1.clr);
	}
	free(brez);
}

t_crd	***ft_isometric(t_crd ***m, t_dim *dim)
{
	int		r;
	int		c;
	t_crd	***a;

	r = -1;
	a = (t_crd ***)malloc(sizeof(t_crd **) * dim->h);
	while (++r < dim->h)
	{
		c = -1;
		a[r] = (t_crd **)malloc(sizeof(t_crd *) * dim->w);
		while (++c < dim->w)
		{
			a[r][c] = (t_crd *)malloc(sizeof(t_crd));
			a[r][c]->x = (m[r][c]->y - m[r][c]->x)
				* sin(dim->al * M_PI / 180);
			a[r][c]->x = (a[r][c]->x - dim->w / 2)
				* dim->zm + WW / 2;
			a[r][c]->y = ((m[r][c]->x + m[r][c]->y)
				* cos(dim->p * M_PI / 180) - m[r][c]->z);
			a[r][c]->y = (a[r][c]->y - dim->h / 2) * dim->zm + WH / 2;
			a[r][c]->clr = m[r][c]->clr;
		}
	}
	return (a);
}

t_crd	***ft_parallel(t_crd ***m, t_dim *dim)
{
	int		r;
	int		c;
	t_crd	***a;

	r = -1;
	a = (t_crd ***)malloc(sizeof(t_crd **) * dim->h);
	while (++r < dim->h)
	{
		c = -1;
		a[r] = (t_crd **)malloc(sizeof(t_crd *) * dim->w);
		while (++c < dim->w)
		{
			a[r][c] = (t_crd *)malloc(sizeof(t_crd));
			a[r][c]->x = m[r][c]->x;
			a[r][c]->x = (a[r][c]->x - dim->w / 2) * dim->zm + WW / 2;
			a[r][c]->y = m[r][c]->y * cos(dim->al * M_PI / 180)
					+ m[r][c]->z * sin(dim->al * M_PI / 180);
			a[r][c]->y = (a[r][c]->y - dim->h / 2) * dim->zm + WH / 2;
			a[r][c]->clr = m[r][c]->clr;
		}
	}
	return (a);
}

void	ft_prj(int key, t_all *all)
{
	if (key == I)
	{
		all->r = ft_isometric(all->m, all->dim);
		all->flag = 1;
	}
	else
	{
		all->r = ft_parallel(all->m, all->dim);
		all->flag = 0;
	}
	ft_drw(all->r, all->dim, all->mlx, all);
}
