/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadtree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:39:05 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/22 02:58:35 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "init_mlx.h"
#include "ft_complex.h"
#include "pixel.h"
#include "quadtree.h"
#include <pthread.h>

static unsigned int get_color(t_mymlx *ml, int n)
{
	unsigned int color = 0x817507;
	if (n == ml->fract.max_iter)
		return (0);
	else
		return (((n - 1) * 0x564255 + color) % 0x1000000);
}

static void	zone2_check_hard(t_mymlx *ml, t_quadtree *tree, int n[4], int nb)
{
	int				i;
	int				n2;
	int				xt;
	int				yt;
	unsigned int	color;
	t_fract			param;

	xt = (nb % 2 == 0) ? tree->zone.x_min : tree->zone.x_max - 1;
	yt = (nb / 2 == 0) ? tree->zone.y_min : tree->zone.y_max - 1;
	param = ml->fract;
	param.z = pos_to_complex(ml, xt + (nb % 2 ? -1 : 1), yt + (nb / 2 ? -1 : 1));
	n2 = ml->ptr_func(param);
	if (n[nb] == n2)
	{
		//printf("better %d ", nb);
		color = get_color(ml, n2);
		i = -1;
		while (++i < 4)
		{
			ft_putpixel(ml, xt + i % 2 * (nb % 2 ? -1 : 1)
				, yt + i / 2 * (nb / 2 ? -1 : 1), color);
		}
		return ;
	}
	ft_putpixel(ml, xt, yt, get_color(ml, n[nb]));
	ft_putpixel(ml, xt + (nb % 2 ? -1 : 1), yt + (nb / 2 ? -1 : 1), get_color(ml, n2));
	param.z = pos_to_complex(ml, xt + (nb % 2 ? -1 : 1), yt);
	ft_putpixel(ml, xt + (nb % 2 ? -1 : 1), yt, get_color(ml, ml->ptr_func(param)));
	param.z = pos_to_complex(ml, xt, yt + (nb / 2 ? -1 : 1));
	ft_putpixel(ml, xt, yt + (nb / 2 ? -1 : 1), get_color(ml, ml->ptr_func(param)));
	//printf("worst ");
}

static void	zone4_check(t_mymlx *ml, t_quadtree *tree)
{
	int		n[4];
	int		n2;
	t_fract	param;

	param = ml->fract;
	param.z = pos_to_complex(ml, tree->zone.x_min, tree->zone.y_min);
	n[0] = ml->ptr_func(param);
	param.z = pos_to_complex(ml, tree->zone.x_max - 1, tree->zone.y_min);
	n[1] = ml->ptr_func(param);
	param.z = pos_to_complex(ml, tree->zone.x_min, tree->zone.y_max - 1);
	n[2] = ml->ptr_func(param);
	param.z = pos_to_complex(ml, tree->zone.x_max - 1, tree->zone.y_max - 1);
	n[3] = ml->ptr_func(param);
	if (n[0] == n[1] && n[0] == n[2] && n[0] == n[3])
	{
		//printf("best");
		render_rect(ml, &tree->zone, get_color(ml, n[0]));
		return ;
	}
	zone2_check_hard(ml, tree, n, 0);
	zone2_check_hard(ml, tree, n, 1);
	zone2_check_hard(ml, tree, n, 2);
	zone2_check_hard(ml, tree, n, 3);
}

static int	zone_check(t_mymlx *ml, t_quadtree *tree)
{
	int		n;
	t_fract	param;
	int		tmp;

	param = ml->fract;
	param.z = pos_to_complex(ml, tree->zone.x_min, tree->zone.y_min);
	n = ml->ptr_func(param);
	if (tree->zone.x_max - tree->zone.x_min <= 1)
		return (n);
	param.z = pos_to_complex(ml, tree->zone.x_max - 1, tree->zone.y_max - 1);
	if (n != ml->ptr_func(param))
		return (-1);
	param.z = pos_to_complex(ml, tree->zone.x_min, tree->zone.y_max - 1);
	if (n != ml->ptr_func(param))
		return (-1);
	param.z = pos_to_complex(ml, tree->zone.x_max - 1, tree->zone.y_min);
	if (n != ml->ptr_func(param))
		return (-1);
	tmp = (tree->zone.x_max - tree->zone.x_min) / 2 + tree->zone.x_min;
	param.z = pos_to_complex(ml, tmp , tree->zone.y_min);
	if (n != ml->ptr_func(param))
		return (-1);
	param.z = pos_to_complex(ml, tmp , tree->zone.y_max - 1);
	if (n != ml->ptr_func(param))
		return (-1);
	tmp = (tree->zone.y_max - tree->zone.y_min) / 2 + tree->zone.y_min;
	param.z = pos_to_complex(ml, tree->zone.x_min, tmp);
	if (n != ml->ptr_func(param))
		return (-1);
	param.z = pos_to_complex(ml, tree->zone.x_max - 1, tmp);
	if (n != ml->ptr_func(param))
		return (-1);
	return (n);
}

static void quad_rend(t_mymlx *ml, t_quadtree *tree)
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
			nb_iter = ml->ptr_func(param);
			color = get_color(ml, nb_iter);
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

	if (tree->child == NULL)
		if ((tree->child = (t_quadtree*)malloc(sizeof(t_quadtree) * 4)) == NULL)
			return (-1);
	tree->use_child = 1;
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
		tree->use_child = 0;
		tree[i].child = NULL;
		i++;
	}
	return (0);
}

int			quad_calc(t_mymlx *ml, t_quadtree *tree)
{
	int				i;
	int				nb_iter;
	unsigned int	color;

	nb_iter = -1;
	tree->use_child = 0;
	if (tree->zone.x_max - tree->zone.x_min > ml->max_quad_len
		|| (tree->zone.x_max - tree->zone.x_min > 5
			&& (nb_iter = zone_check(ml, tree)) == -1))
	{
		if (quad_split(tree) == -1)
			return (-1);
		i = 0;
		while (i < 4)
		{
			if (quad_calc(ml, &tree->child[i]) == -1)
				return (-1);
			i++;
		}
	}
	else if (nb_iter == -1)
	{
		zone4_check(ml, tree);
		//printf("\n");
	}
	else
	{
		color = get_color(ml, nb_iter);
		render_rect(ml, &tree->zone, color);
	}
	return (1);
}

int			quad_calc_thread(void *vparam)
{
	int				i;
	t_quad_param	*param;

	param = (t_quad_param*)vparam;
	quad_calc(param->ml, param->tree);
	pthread_exit(NULL);
}
