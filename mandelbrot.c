/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 00:19:33 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/22 06:00:01 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "complex.h"
#include <math.h>

int	mandelbrot(t_fract fract)
{
	int			i;
	t_complex	z;
	double	zrs;
	double	zis;
	double	zir;

	i = 1;
	z = fract.z;
	while (i < fract.max_iter)
	{
		zrs = z.r * z.r;
		zis = z.i * z.i;
		zir = z.r * z.i;
		if (zrs + zis > 4.0)
			break;
		z.r = zrs - zis + fract.z.r;
		z.i = zir + zir + fract.z.i;
		i++;
	}
	return (i);
}

int	julia(t_fract fract)
{
	int			i;
	t_complex	z;
	double	zrs;
	double	zis;
	double	zir;

	i = 0;
	z = fract.z;
	while (i < fract.max_iter)
	{
		zrs = z.r * z.r;
		zis = z.i * z.i;
		zir = z.r * z.i;
		if (zrs + zis > 4.0)
			break;
		z.r = zrs - zis + fract.c.r;
		z.i = zir + zir + fract.c.i;
		i++;
	}
	return (i);
}

int	feigenbam(t_fract fract)
{
	int			i;
	double		zrs;
	double		zis;
	double		zir;
	t_complex	z;
	t_complex	cube;

	i = 0;
	z = fract.z;
	cube.r = z.r * z.r * z.r - 3 * z.r * z.i * z.i;
	cube.i = 3 * z.r * z.r * z.i - z.i * z.i * z.i;
	z.r = 0; 
	z.i = 0;
	while (i < fract.max_iter)
	{
		zrs = z.r * z.r;
		zis = z.i * z.i;
		zir = z.r * z.i;
		z.r = zrs - zis + cube.r + fract.omega;
		z.i = zir + zir + cube.i;
		if (zrs + zis > 5.0)
			break;
		i++;
	}
	return (i);
}

int	batman(t_fract fract)
{
	int			i;
	t_complex	z;
	t_complex	tmpz;
	double		zrs;
	double		zis;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	zrs = fract.z.r * fract.z.r;
	zis = fract.z.i * fract.z.i;
	while (i < fract.max_iter)
	{
		tmpz.r = cos(z.r) * cosh(z.i) + fract.z.r / (zrs + zis);
		tmpz.i = -sin(z.r) * sinh(z.i) + fract.z.i / (zrs + zis);
		z = tmpz;
		if (z.r * z.r + z.i * z.i > 50.0)
			break;

		i++;
	}
	return (i);
}

int	vulca(t_fract fract)
{
	int			i;
	t_complex	z;
	t_complex	tmpz;
	double		zrs;
	double		zis;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	while (i < fract.max_iter)
	{
		z = ft_divz(z, fract.z);
		tmpz.r = cos(z.r) * cosh(z.i);
		tmpz.i = -sin(z.r) * sinh(z.i);
		z = tmpz;
		if (z.r * z.r + z.i * z.i > 50.0)
			break;

		i++;
	}
	return (i);
}

int	magnet1(t_fract fract)
{
	int			i;
	t_complex	z;
	t_complex	tmpz;
	t_complex	tmpz2;
	double		zrs;
	double		zis;
	double		zir;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	while (i < fract.max_iter)
	{
		zrs = z.r * z.r;
		zis = z.i * z.i;
		zir = z.r * z.i;
		tmpz.r = zrs - zis + fract.z.r - 1.0;
		tmpz.i = zir + zir + fract.z.i;
		tmpz2.r = 2.0 * z.r + fract.z.r - 2.0;
		tmpz2.i = 2.0 * z.i + fract.z.i;
		z = ft_divz(tmpz, tmpz2);
		zrs = z.r * z.r;
		zis = z.i * z.i;
		zir = z.r * z.i;
		z.r = zrs - zis;
		z.i = 2.0 * zir;
		if (zrs + zis > 30.0)
			break;
		i++;
	}
	return (i);
}

int	magnet1_ctype(t_fract fract)
{
	int			i;
	t_complex	z;
	t_complex	tmpz;
	t_complex	tmpz2;
	double		zrs;
	double		zis;
	double		zir;

	i = 0;
	z = fract.z;
	while (i < fract.max_iter)
	{
		zrs = z.r * z.r;
		zis = z.i * z.i;
		zir = z.r * z.i;
		tmpz.r = zrs - zis + fract.c.r - 1.0;
		tmpz.i = zir + zir + fract.c.i;
		tmpz2.r = 2.0 * z.r + fract.c.r - 2.0;
		tmpz2.i = 2.0 * z.i + fract.c.i;
		z = ft_divz(tmpz, tmpz2);
		zrs = z.r * z.r;
		zis = z.i * z.i;
		zir = z.r * z.i;
		z.r = zrs - zis;
		z.i = 2.0 * zir;
		if (zrs + zis > 30.0)
			break;
		i++;
	}
	return (i);
}

int	magnet2(t_fract fract)
{
	int			i;
	t_complex	z;
	t_complex	tmpz;
	t_complex	tmpz2;
	double		zrs;
	double		zis;
	double		zir;
	t_complex	cs;
	t_complex	cube;
	t_complex	mul;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	cs.r = (fract.z.r - 1.0) * (fract.z.r - 2.0) - fract.z.i * fract.z.i;
	cs.i = (fract.z.r - 1.0) * fract.z.i + (fract.z.r - 2.0) * fract.z.i;
	while (i < fract.max_iter)
	{
		zrs = z.r * z.r;
		zis = z.i * z.i;
		zir = z.r * z.i;
		cube.r = z.r * z.r * z.r - 3 * z.r * z.i * z.i;
		cube.i = 3 * z.r * z.r * z.i - z.i * z.i * z.i;
		mul.r = (fract.z.r - 1.0) * z.r - fract.z.i * z.i;
		mul.i = (fract.z.r - 1.0) * z.i + fract.z.i * z.r;
		tmpz.r = cube.r + 3 * mul.r + cs.r;
		tmpz.i = cube.i + 3 * mul.i + cs.i;
		mul.r = (fract.z.r - 2.0) * z.r - fract.z.i * z.i;
		mul.i = (fract.z.r - 2.0) * z.i + fract.z.i * z.r;
		tmpz2.r = 3 * (zrs - zis) + 3 * mul.r + cs.r + 1.0;
		tmpz2.i = 3 * (zir + zir) + 3 * mul.i + cs.i;
		z = ft_divz(tmpz, tmpz2);
		zrs = z.r * z.r;
		zis = z.i * z.i;
		zir = z.r * z.i;
		z.r = zrs - zis;
		z.i = 2.0 * zir;
		if (zrs + zis > 1500.0)
			break;
		i++;
	}
	return (i);
}

int	magnet2_ctype(t_fract fract)
{
	int			i;
	t_complex	z;
	t_complex	tmpz;
	t_complex	tmpz2;
	double		zrs;
	double		zis;
	double		zir;
	t_complex	cs;
	t_complex	cube;
	t_complex	mul;

	i = 0;
	z = fract.z;
	cs.r = (fract.c.r - 1.0) * (fract.c.r - 2.0) - fract.c.i * fract.c.i;
	cs.i = (fract.c.r - 1.0) * fract.c.i + (fract.c.r - 2.0) * fract.c.i;
	while (i < fract.max_iter)
	{
		zrs = z.r * z.r;
		zis = z.i * z.i;
		zir = z.r * z.i;
		cube.r = z.r * z.r * z.r - 3 * z.r * z.i * z.i;
		cube.i = 3 * z.r * z.r * z.i - z.i * z.i * z.i;
		mul.r = (fract.c.r - 1.0) * z.r - fract.c.i * z.i;
		mul.i = (fract.c.r - 1.0) * z.i + fract.c.i * z.r;
		tmpz.r = cube.r + 3 * mul.r + cs.r;
		tmpz.i = cube.i + 3 * mul.i + cs.i;
		mul.r = (fract.c.r - 2.0) * z.r - fract.c.i * z.i;
		mul.i = (fract.c.r - 2.0) * z.i + fract.c.i * z.r;
		tmpz2.r = 3 * (zrs - zis) + 3 * mul.r + cs.r + 1.0;
		tmpz2.i = 3 * (zir + zir) + 3 * mul.i + cs.i;
		z = ft_divz(tmpz, tmpz2);
		zrs = z.r * z.r;
		zis = z.i * z.i;
		zir = z.r * z.i;
		z.r = zrs - zis;
		z.i = 2.0 * zir;
		if (zrs + zis > 1500.0)
			break;
		i++;
	}
	return (i);
}
