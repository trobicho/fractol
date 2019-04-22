/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 22:47:51 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/22 03:31:32 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
#include "ft_complex.h"

typedef struct	s_fract
{
	t_complex	z;
	t_complex	c;
	double		omega;
	int			max_iter;
}				t_fract;
#endif
