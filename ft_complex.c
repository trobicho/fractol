/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 00:24:35 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/22 02:45:42 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <math.h>

double	ft_modz(t_complex z)
{
	return (z.r * z.r + z.i * z.i);
}

t_complex	ft_addz(t_complex z1, t_complex z2)
{
	t_complex	ret;

	ret.r = z1.r + z2.r;
	ret.i = z1.i + z2.i;
	return (ret);
}

t_complex	ft_mulz(t_complex z1, t_complex z2)
{
	t_complex	ret;

	ret.r = z1.r * z2.r - z1.i * z2.i;
	ret.i = z1.r * z2.i + z2.r * z1.i;
	return (ret);
}

t_complex	ft_divz(t_complex z1, t_complex z2)
{
	t_complex	conj;
	t_complex	up;
	double		down;

	conj.r = z2.r;
	conj.i = -z2.i;
	up.r = z1.r * conj.r - z1.i * conj.i;
	up.i = z1.i * conj.r + z1.r * conj.i;
	down = z2.r * conj.r - z2.i * conj.i;
	z1.r = up.r / down;
	z1.i = up.i / down;
	return (z1);
}
