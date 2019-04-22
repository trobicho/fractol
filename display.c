/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 01:06:43 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/22 00:35:17 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "init_mlx.h"
#include "quadtree.h"
#include <pthread.h>
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
	if (tree->child && tree->use_child)
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
	int				i;
	pthread_t		*worker;
	t_quad_param	*param;

	i = 0;
	param = (t_quad_param*)malloc(sizeof(t_quad_param) * ml->nb_tree);
	worker = (pthread_t*)malloc(sizeof(pthread_t) * ml->nb_tree);
	while (i < ml->nb_tree)
	{
		param[i].ml = ml;
		param[i].tree = &ml->tree[i];
		pthread_create(&worker[i], NULL, &quad_calc_thread, (void*)&param[i]);
		i++;
	}
	i = 0;
	while (i < ml->nb_tree)
	{
		pthread_join(worker[i], NULL);
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
