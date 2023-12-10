/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:08:07 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/10 22:17:56 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	key_press(int keycode, t_file *file)
{
	if (keycode == XK_Escape)
		exit_cubed(file, NULL, SUCCESS);
	if (keycode == XK_w)
		file->player.move_y = 1;
	if (keycode == XK_s)
		file->player.move_y = -1;
	if (keycode == XK_a)
		file->player.move_x = -1;
	if (keycode == XK_d)
		file->player.move_x = 1;
	if (keycode == XK_Left)
		file->player.rotate = -1;
	if (keycode == XK_Right)
		file->player.rotate = 1;
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		file->player.sprint = 2;
	return (SUCCESS);
}

int	key_release(int keycode, t_file *file)
{
	if (keycode == XK_Escape)
		exit_cubed(file, NULL, SUCCESS);
	if (keycode == XK_w || keycode == XK_s)
		file->player.move_y = 0;
	if (keycode == XK_a || keycode == XK_d)
		file->player.move_x = 0;
	if (keycode == XK_Left || keycode == XK_Right)
		file->player.rotate = 0;
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		file->player.sprint = 1;
	return (SUCCESS);
}
