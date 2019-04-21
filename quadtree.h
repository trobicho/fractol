/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadtree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:39:08 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/21 04:24:49 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUADTREE_H
# define QUADTREE_H
#include "init_mlx.h"
#include "struct_quadtree.h"

int				quad_calc(t_mymlx *ml, t_quadtree *tree
	, int (*fract)(t_fract fract));
#endif
