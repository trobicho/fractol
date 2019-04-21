/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:34:20 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/21 04:47:01 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MLX
# define INIT_MLX
#include "struct_quadtree.h"

int			init_mlx(t_mymlx *init, int w, int h, char *name);
t_complex	pos_to_complex(t_mymlx *ml, int x, int y);
void		ft_zoom(t_mymlx *ml, int x, int y, long double zoom);
#endif
