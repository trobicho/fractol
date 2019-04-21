/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:33:23 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/21 04:52:37 by trobicho         ###   ########.fr       */
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
	long double	xp;
	long double	yp;
	long double	len_r;
	long double	len_i;
	t_complex	z;

	len_r = (ml->max.r - ml->min.r);
	len_i = (ml->max.i - ml->min.i);
	xp = (long double)x / ml->w;
	yp = (long double)y / ml->h;
	z.r = xp * len_r + ml->min.r;
	z.i = yp * len_i + ml->min.i;
	return (z);
}

void		ft_zoom(t_mymlx *ml, int x, int y, long double zoom)
{
	long double	xp;
	long double	yp;
	long double	len_r;
	long double	len_i;

	len_r = (ml->max.r - ml->min.r);
	len_i = (ml->max.i - ml->min.i);
	xp = ((long double)x / ml->w) * len_r + ml->min.r;
	yp = ((long double)y / ml->h) * len_i + ml->min.i;
	ml->min.r = (ml->min.r - xp) * zoom + xp;
	ml->min.i = (ml->min.i - yp) * zoom + yp;
	ml->max.r = (ml->max.r - xp) * zoom + xp;
	ml->max.i = (ml->max.i - yp) * zoom + yp;
}
