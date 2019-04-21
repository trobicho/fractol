/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 00:19:33 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/21 06:07:53 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mandelbrot(t_fract fract)
{
	int			i;
	t_complex	z;
	long double	zrs;
	long double	zis;
	long double	zir;

	i = 1;
	z = fract.z;
	while (i < fract.max_iter)
	{
		zrs = z.r * z.r;
		zis = z.i * z.i;
		zir = z.r * z.i;
		if (zrs + zis > 4)
			break;
		z.r = zrs - zis + fract.z.r;
		z.i = zir + zir + fract.z.i;
		i++;
	}
	return (i);
}
