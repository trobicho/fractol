/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:30:10 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/21 04:28:51 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixel.h"
#include "mlx.h"

static void	ft_putcolor_bpp(char *buf, int bpp, unsigned int color)
{
	int		b;
	char	*c;

	b = 0;
	c = (char*)&color;
	while (b < bpp)
	{
		buf[b] = c[b];
		b++;
	}
}

void		ft_putpixel(t_mymlx *ml, int x, int y, unsigned int color)
{
	ft_putcolor_bpp(&ml->buf[x * ml->bpp + y * ml->sline], ml->bpp, color);
}

void		render_rect(t_mymlx *ml, t_rect *zone, unsigned int color)
{
	int	x;
	int	y;

	y = zone->y_min;
	while (y < zone->y_max)
	{
		x = zone->x_min;
		while (x < zone->x_max)
		{
			ft_putpixel(ml, x, y, color);
			x++;
		}
		y++;
	}
}
