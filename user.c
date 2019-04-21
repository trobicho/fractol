/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 03:42:04 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/21 06:14:04 by trobicho         ###   ########.fr       */
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
	{
		ml->disp_tree = 1 - ml->disp_tree;
		reblit = 1;
	}
	else
		return (0);
	if (reblit)
		render(ml);
	return (0);
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
