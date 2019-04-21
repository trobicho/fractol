/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadtree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:39:05 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/21 06:33:27 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "init_mlx.h"
#include "ft_complex.h"
#include "pixel.h"

static int	zone_check(t_mymlx *ml, t_quadtree *tree
	, int (*fract)(t_fract fract))
{
	int		n;
	t_fract	param;

	param = ml->fract;
	param.z = pos_to_complex(ml, tree->zone.x_min, tree->zone.y_min);
	n = fract(param);
	if (tree->zone.x_max - tree->zone.x_min <= 1)
		return (n);
	param.z = pos_to_complex(ml, tree->zone.x_max - 1, tree->zone.y_max - 1);
	if (n != fract(param))
		return (-1);
	param.z = pos_to_complex(ml, tree->zone.x_min, tree->zone.y_max - 1);
	if (n != fract(param))
		return (-1);
	param.z = pos_to_complex(ml, tree->zone.x_max - 1, tree->zone.y_min);
	if (n != fract(param))
		return (-1);
	return (n);
}

static void quad_rend(t_mymlx *ml, t_quadtree *tree
	, int (*fract)(t_fract fract))
{
	int				x;
	int				y;
	int				nb_iter;
	t_fract			param;
	unsigned int	color;

	x = tree->zone.x_min;
	y = tree->zone.y_min;
	while (x < tree->zone.x_max)
	{
		y = tree->zone.y_min;
		while (y < tree->zone.y_max)
		{
			param.z = pos_to_complex(ml, x, y);
			nb_iter = fract(param);
			if (nb_iter == ml->fract.max_iter)
				color = 0;
			else
				color = (nb_iter * 0xA2E85E) % 0x1000000;
			ft_putpixel(ml, x, y, color);
			y++;
		}
		x++;
	}
}


static int	quad_split(t_quadtree *tree)
{
	int	i;
	int center_x;
	int center_y;
	int	min_x;
	int	min_y;

	if ((tree->child = (t_quadtree*)malloc(sizeof(t_quadtree) * 4)) == NULL)
		return (-1);
	i = 0;
	center_x = (tree->zone.x_max - tree->zone.x_min) / 2;
	center_y = (tree->zone.y_max - tree->zone.y_min) / 2;
	min_x = tree->zone.x_min;
	min_y = tree->zone.y_min;
	tree = tree->child;
	while (i < 4)
	{
		tree[i].zone.x_min = min_x + center_x * (i % 2);
		tree[i].zone.y_min = min_y + center_y * (i / 2);
		tree[i].zone.x_max = min_x + center_x * (i % 2 + 1);
		tree[i].zone.y_max = min_y + center_y * (i / 2 + 1);
		tree[i].child = NULL;
		i++;
	}
	return (0);
}

int			quad_calc(t_mymlx *ml, t_quadtree *tree
	, int (*fract)(t_fract fract))
{
	int				i;
	int				nb_iter;
	unsigned int	color;

	nb_iter = -1;
	if ((nb_iter = zone_check(ml, tree, fract)) == -1
		&& tree->zone.x_max - tree->zone.x_min >= 8)
	{
		if (quad_split(tree) == -1)
			return (-1);
		i = 0;
		while (i < 4)
		{
			if (quad_calc(ml, &tree->child[i], fract) == -1)
				return (-1);
			i++;
		}
	}
	else if (nb_iter == -1)
		quad_rend(ml, tree, fract);
	else
	{
		if (nb_iter == ml->fract.max_iter)
			color = 0;
		else
			color = (nb_iter * 0xA2E85E) % 0x1000000;
		render_rect(ml, &tree->zone, color);
	}
	return (1);
}
