/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:25:52 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/22 17:08:46 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"
#include "quadtree.h"
#include "fractal.h"
#include "mandelbrot.h"
#include "display.h"
#include "mlx.h"
#include "user.h"
#include <string.h>

int main(int ac, char **av)
{
	int			i;
	t_quadtree	quad[4];
	t_mymlx		myml;

	if (init_mlx(&myml, 1024, 1024, "fractol") == -1)
		return (-1);
	mlx_hook(myml.win_ptr, 2, 0, &ft_key_hook, &myml);
	mlx_hook(myml.win_ptr, 4, 0, &ft_mouse_press, &myml);
	mlx_hook(myml.win_ptr, 6, 0, &ft_mouse_move, &myml);
	myml.lock_c = 1;
	myml.type = type_fix;
	myml.fract.max_iter = 50;
	myml.fract.omega = -1.401155;
	myml.fract.c = (t_complex){0.0, 0.0};
	myml.min = (t_complex){-2.0, -1.3};
	myml.max = (t_complex){0.6, 1.3};
	myml.disp_tree = 0;
	myml.ptr_func = &batman;
	myml.tree = quad;
	myml.nb_tree = 4;
	myml.max_quad_len = 256;
	i = 0;
	while (i < 4)
	{
		quad[i].zone.x_min = (1024 / 2) * (i % 2);
		quad[i].zone.y_min = (1024 / 2) * (i / 2);
		quad[i].zone.x_max = (1024 / 2) * (i % 2 + 1);
		quad[i].zone.y_max = (1024 / 2) * (i / 2 + 1);
		quad[i].child = NULL;
		quad[i].use_child = 0;
		i++;
	}
	render(&myml);
	mlx_loop(myml.mlx_ptr);
	return (0);
}
