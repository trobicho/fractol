/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:25:52 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/21 06:12:49 by trobicho         ###   ########.fr       */
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
	myml.fract.max_iter = 500;
	myml.min = (t_complex){-2.0, -1.3};
	myml.max = (t_complex){0.6, 1.3};
	myml.disp_tree = 0;
	myml.ptr_func = &mandelbrot;
	myml.tree = quad;
	myml.nb_tree = 4;
	i = 0;
	while (i < 4)
	{
		quad[i].zone.x_min = (1024 / 2) * (i % 2);
		quad[i].zone.y_min = (1024 / 2) * (i / 2);
		quad[i].zone.x_max = (1024 / 2) * (i % 2 + 1);
		quad[i].zone.y_max = (1024 / 2) * (i / 2 + 1);
		quad[i].child = NULL;
		i++;
	}
	render(&myml);
	mlx_loop(myml.mlx_ptr);
	return (0);
}
