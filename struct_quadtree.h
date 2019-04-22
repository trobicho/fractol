/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_quadtree.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 04:15:14 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/22 03:56:49 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STRUCT_QUADTREE_H
# define STRUCT_QUADTREE_H
#include "ft_complex.h"
#include "fractal.h"

typedef enum {type_fix, type_c, type_omega}e_fract_type;

typedef	struct	s_rect
{
	int	x_min;
	int	y_min;
	int	x_max;
	int	y_max;
}				t_rect;

typedef struct	s_quadtree
{
	t_rect				zone;
	struct s_quadtree	*child;
	int					use_child;
}				t_quadtree;

typedef struct	s_mymlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				w;
	int				h;
	int				button;
	char			*buf;
	int				bpp;
	int				sline;
	int				endian;
	t_complex		min;
	t_complex		max;
	t_fract			fract;
	t_quadtree		*tree;
	int				nb_tree;
	int				disp_tree;
	int				(*ptr_func)(t_fract fract);
	int				max_quad_len;
	int				lock_c;
	e_fract_type	type;
}				t_mymlx;
#endif
