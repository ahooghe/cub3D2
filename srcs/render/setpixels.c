/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpixels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:40:13 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/11 00:05:49 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	set_index(t_file *file, t_ray *ray)
{
	if (ray->side == -1)
	{
		if (ray->step_x == -1)
			file->textures.tex_index = WEST;
		if (ray->step_x == 1)
			file->textures.tex_index = EAST;
	}
	else
	{
		if (ray->step_y == -1)
			file->textures.tex_index = NORTH;
		if (ray->step_y == 1)
			file->textures.tex_index = SOUTH;
	}
}

void	draw_line(t_ray *ray, t_text *text, t_file *file, int x)
{
	int	y;

	set_index(file, ray);
	text->x = (int)(ray->wall_pos * text->width) % text->width;
	if ((ray->side == 0 && ray->raydir_x < 0) || \
	(ray->side == 1 && ray->raydir_y > 0))
		text->x = text->width - text->x - 1;
	text->step = 1.0 * text->height / ray->lineheight;
	text->pos = (ray->drawstart - HEIGHT / 2 + ray->lineheight / 2) * \
		text->step;
	y = ray->drawstart;
	while (y < ray->drawend)
	{
		text->y = (int)text->pos & (text->height - 1);
		text->pos += text->step;
		text->pixels[y][x] = text->textures_addr[text->tex_index] \
		[text->width * text->y + text->x];
		y++;
	}
}
