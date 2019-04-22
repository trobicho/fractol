/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 03:42:04 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/22 07:24:23 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_quadtree.h"
#include "display.h"
#include "mlx.h"

int		ft_key_hook(int keycode, void *param)
{
	int reblit;
	t_mymlx	*ml;

	reblit = 0;
	ml = (t_mymlx*)param;
	if (keycode == 53)
		printf("quitte moi sa steuplait aller euh\n");
	else if (keycode == 17)
		ml->disp_tree = 1 - ml->disp_tree;
	else if (keycode == 78)
	{
		ml->fract.max_iter -= 5;
		if (ml->fract.max_iter < 5)
			ml->fract.max_iter = 5;
	}
	else if (keycode == 69)
	{
		ml->fract.max_iter += 10;
		if (ml->fract.max_iter > 1500)
			ml->fract.max_iter = 1500;
	}
	else if (keycode == 49)
	{
		if (ml->type)
			ml->lock_c = 1 - ml->lock_c;
	}
	else if (keycode == 123)
		ft_translate(ml, -0.1, 0.0);
	else if (keycode == 124)
		ft_translate(ml, 0.1, 0.0);
	else if (keycode == 125)
		ft_translate(ml, 0.0, 0.1);
	else if (keycode == 126)
		ft_translate(ml, 0.0, -0.1);
	else
		return (0);
	render(ml);
	return (0);
}

int		ft_mouse_move(int x, int y, void *param)
{
	t_mymlx	*ml;

	ml = (t_mymlx*)param;
	if (ml->type && !ml->lock_c)
	{
		if (ml->type == type_c)
			ml->fract.c = pos_to_complex(ml, x, y);
		else if(ml->type == type_omega)
		{
			ml->fract.omega = ((double)(x - ml->w / 2) / ml->w) * 5.0;
		}
		render(ml);
	}
}

int		ft_mouse_press(int button, int x, int y, void *param)
{
	t_mymlx	*ml;
	int reblit;

	reblit = 0;
	ml = (t_mymlx*)param;
	if (button == 4)
	{
		ft_zoom(ml, x, y, 0.85);
		render(ml);
	}
	else if (button == 5)
	{
		ft_zoom(ml, x, y, 1.15);
		render(ml);
	}
	return (0);
}
