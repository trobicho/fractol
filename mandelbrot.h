/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 22:55:25 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/22 05:56:18 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H
#include "fractal.h"

int	mandelbrot(t_fract fract);
int	julia(t_fract fract);
int	feigenbam(t_fract fract);
int	batman(t_fract fract);
int	vulca(t_fract fract);
int	magnet1(t_fract fract);
int	magnet1_ctype(t_fract fract);
int	magnet2(t_fract fract);
int	magnet2_ctype(t_fract fract);
#endif
