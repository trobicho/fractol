/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:29:29 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/21 04:30:40 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIXEL_H
# define PIXEL_H
#include "struct_quadtree.h"

void	ft_putpixel(t_mymlx *ml, int x, int y, unsigned int color);
void	render_rect(t_mymlx *ml, t_rect *zone, unsigned int color);
#endif
