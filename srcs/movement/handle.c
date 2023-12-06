/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:20:04 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/06 02:51:44 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_collision(t_file *file, double tmp_x, double tmp_y)
{
	int		x;
	int		y;

	x = (int)tmp_x;
	y = (int)tmp_y;
	if (file->map.map[x][y] == '1' || file->map.map[x][y] == '\0')
		return (FAILURE);
	if (tmp_x < 0.25 || tmp_y < 0.25 || \
		tmp_x >= file->map.longestline - 0.25 || \
		tmp_y >= file->map.amt_lines - 0.25)
		return (FAILURE);
	return (SUCCESS);
}

void	move(t_file *file)
{
	double	tmp_x;
	double	tmp_y;

	if (file->player.move_x != 0)
	{
		tmp_x = file->player.pos_x - file->player.move_x * \
			MOVESPEED * file->player.sprint * file->player.dir_y;
		tmp_y = file->player.pos_y + file->player.move_x * \
			MOVESPEED * file->player.sprint * file->player.dir_x;
	}
	if (file->player.move_y != 0)
	{
		tmp_x = file->player.pos_x + file->player.move_y * \
			MOVESPEED * file->player.sprint * file->player.dir_x;
		tmp_y = file->player.pos_y + file->player.move_y * \
			MOVESPEED * file->player.sprint * file->player.dir_y;
	}
	if (check_collision(file, tmp_x, tmp_y) == SUCCESS)
	{
		file->player.pos_x = tmp_x;
		file->player.pos_y = tmp_y;
	}
}

void	rotate(t_file *file)
{
	double	rot;
	double	tmp;

	tmp = file->player.dir_x;
	rot = file->player.rotate * ROTSPEED;
	file->player.dir_x = file->player.dir_x * \
		cos(rot) - file->player.dir_y * sin(rot);
	file->player.dir_y = tmp * sin(rot) + file->player.dir_y * cos(rot);
	tmp = file->player.plane_x;
	file->player.plane_x = file->player.plane_x * \
		cos(rot) - file->player.plane_y * sin(rot);
	file->player.plane_y = tmp * sin(rot) + file->player.plane_y * cos(rot);
}

void	handle_movement(t_file *file)
{
	if (file->player.move_x != 0 || file->player.move_y != 0)
		move(file);
	if (file->player.rotate)
		rotate(file);
}
