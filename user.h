/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 03:42:00 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/22 03:34:47 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	USER_H
# define USER_H

int		ft_key_hook(int keycode, void *param);
int		ft_mouse_move(int x, int y, void *param);
int		ft_mouse_press(int button, int x, int y, void *param);
#endif
