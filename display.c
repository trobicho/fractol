/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 01:06:43 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/21 05:32:29 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "init_mlx.h"
#include "quadtree.h"
#include "struct_quadtree.h"
#include "pixel.h"

static void	display_tree(t_mymlx *ml, t_quadtree *tree)
{
	int		i;
	t_rect	rect;

	rect = tree->zone;
	rect.y_max = rect.y_min + 1;
	render_rect(ml, &rect, 0x00FFFF00);
	rect = tree->zone;
	rect.y_min = rect.y_max;
	rect.y_max = rect.y_min + 1;
	render_rect(ml, &rect, 0x00FFFF00);
	rect = tree->zone;
	rect.x_max = rect.x_min + 1;
	render_rect(ml, &rect, 0x00FFFF00);
	rect = tree->zone;
	rect.x_min = rect.x_max;
	rect.x_max = rect.x_min + 1;
	render_rect(ml, &rect, 0x00FFFF00);
	if (tree->child)
	{
		i = 0;
		while (i < 4)
		{
			display_tree(ml, &tree->child[i++]);
		}
	}
}

void		render(t_mymlx *ml)
{
	int	i;

	i = 0;
	while (i < ml->nb_tree)
	{
		quad_calc(ml, &ml->tree[i], ml->ptr_func);
		i++;
	}
	if (ml->disp_tree)
	{
		i = 0;
		while (i < ml->nb_tree)
		{
			display_tree(ml, &ml->tree[i]);
			i++;
		}
	}
	mlx_put_image_to_window(ml->mlx_ptr, ml->win_ptr, ml->img_ptr, 0, 0);
}
