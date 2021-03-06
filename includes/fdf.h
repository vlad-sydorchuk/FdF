/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 14:03:29 by vsydorch          #+#    #+#             */
/*   Updated: 2017/05/10 13:16:34 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# define WW 1920
# define WH 1080

# define ESC 53
# define I 34
# define P 35
# define ZMP 69
# define ZMM 78
# define XP 2
# define XM 0
# define YM 13
# define YP 1
# define Z 6
# define X 7
# define XPL 91
# define XMN 89
# define YPL 87
# define YMN 86

typedef	struct	s_im
{
	float	x;
	float	y;
	float	z;
	int		clr;
}				t_crd;

typedef	struct	s_brez
{
	float	dx;
	float	dy;
	float	sx;
	float	sy;
	float	err0;
	float	err1;
}				t_brez;

typedef struct	s_dim
{
	int		h;
	int		w;
	float	zm;
	float	st;
	int		al;
	int		p;
}				t_dim;

typedef struct	s_gr
{
	void	*init;
	void	*win;
}				t_gr;

typedef struct	s_all
{
	t_crd	***r;
	t_crd	***m;
	t_dim	*dim;
	t_gr	*mlx;
	int		flag;
	int		step;
}				t_all;

void			ft_err(int code);
void			valid(char *s);
void			ft_free(char ***a, char **tmp);
char			**ft_split_cl(char const *str, char c);
int				fill_m(t_crd ****res, char ***a, t_dim **dim, int r);
void			draw_info(t_gr *mlx);
int				ft_atoi_base(char *str, int base);
void			ft_alg(t_crd ***map, t_dim *dim);
int				ft_hooks(int key, t_all *all);
void			ft_prj(int key, t_all *all);
t_crd			***ft_parallel(t_crd ***m, t_dim *dim);
t_crd			***ft_isometric(t_crd ***m, t_dim *dim);
void			ft_brez(t_crd d1, t_crd d2, t_gr *mlx);
void			ft_drw(t_crd ***r, t_dim *dim, t_gr *mlx, t_all *all);
#endif
