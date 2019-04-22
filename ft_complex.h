/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 23:04:34 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/22 02:41:11 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

double		ft_modz(t_complex z);
t_complex	ft_addz(t_complex z1, t_complex z2);
t_complex	ft_mulz(t_complex z1, t_complex z2);
t_complex	ft_divz(t_complex z1, t_complex z2);
#endif
