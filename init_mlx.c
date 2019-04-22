/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:33:23 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/22 07:19:59 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"
#include "mlx.h"
#include "string.h"
//ERROR GESTION

int			init_mlx(t_mymlx *init, int w, int h, char *name)
{
	if ((init->mlx_ptr = mlx_init()) == NULL)
	{
		//ft_putendl("failed to init");
		return (-1);
	}
	if (name)
		init->win_ptr = mlx_new_window(init->mlx_ptr, w, h, name);
	else
		init->win_ptr = mlx_new_window(init->mlx_ptr, w, h, "no_name");
	init->img_ptr = mlx_new_image(init->mlx_ptr, w, h);
	init->buf = mlx_get_data_addr(init->img_ptr, &init->bpp,
									&init->sline, &init->endian);
	init->bpp /= 8;
	init->w = w;
	init->h = h;
	return (0);
}

t_complex	pos_to_complex(t_mymlx *ml, int x, int y)
{
	double	xp;
	double	yp;
	double	len_r;
	double	len_i;
	t_complex	z;

	len_r = (ml->max.r - ml->min.r);
	len_i = (ml->max.i - ml->min.i);
	xp = (double)x / ml->w;
	yp = (double)y / ml->h;
	z.r = xp * len_r + ml->min.r;
	z.i = yp * len_i + ml->min.i;
	return (z);
}

void		ft_zoom(t_mymlx *ml, int x, int y, double zoom)
{
	double	xp;
	double	yp;
	double	len_r;
	double	len_i;

	len_r = (ml->max.r - ml->min.r);
	len_i = (ml->max.i - ml->min.i);
	xp = ((double)x / ml->w) * len_r + ml->min.r;
	yp = ((double)y / ml->h) * len_i + ml->min.i;
	ml->min.r = (ml->min.r - xp) * zoom + xp;
	ml->min.i = (ml->min.i - yp) * zoom + yp;
	ml->max.r = (ml->max.r - xp) * zoom + xp;
	ml->max.i = (ml->max.i - yp) * zoom + yp;
}

void		ft_translate(t_mymlx *ml, double x, double y)
{
	double	dif;

	dif = ((ml->max.r - ml->min.r) * x);
	ml->min.r += dif;
	ml->max.r += dif;
	dif = ((ml->max.i - ml->min.i) * y);
	ml->min.i += dif;
	ml->max.i += dif;
}
