/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadtree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:39:08 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/21 23:50:20 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUADTREE_H
# define QUADTREE_H
#include "init_mlx.h"
#include "struct_quadtree.h"

typedef struct	s_quad_param
{
	t_mymlx		*ml;
	t_quadtree	*tree;
}				t_quad_param;

int				quad_calc(t_mymlx *ml, t_quadtree *tree);
int				quad_calc_thread(void *vparam);
#endif
