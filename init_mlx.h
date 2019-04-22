/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:34:20 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/22 07:20:56 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MLX
# define INIT_MLX
#include "struct_quadtree.h"

int			init_mlx(t_mymlx *init, int w, int h, char *name);
t_complex	pos_to_complex(t_mymlx *ml, int x, int y);
void		ft_zoom(t_mymlx *ml, int x, int y, double zoom);
void		ft_translate(t_mymlx *ml, double x, double y);
#endif
