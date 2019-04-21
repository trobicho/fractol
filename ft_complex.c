/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 00:24:35 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/21 05:41:15 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <math.h>

long double	ft_modz(t_complex z)
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
