/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpixels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:40:13 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/10 19:53:54 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	set_index(t_file *file, t_ray *ray)
{
	if (ray->side == -1)
	{
		if (file->player.dir_x == -1)
			file->textures.tex_index = WEST;
		if (file->player.dir_x == 1)
			file->textures.tex_index = EAST;
	}
	else
	{
	    if (file->player.dir_y == -1)
	    	file->textures.tex_index = NORTH;
	    if (file->player.dir_y == 1)
	    	file->textures.tex_index = SOUTH;
	}
}
void	draw_line(t_ray *ray, t_text *text, t_file *file, int x)
{
	int	y;
	int	color;

	set_index(file, ray);
	text->x = (int)(ray->wall_pos * text->width);
	text->step = (double)(text->height / ray->lineheight);
	text->pos = (ray->drawstart - HEIGHT / 2 + ray->lineheight / 2) * text->step;
	y = ray->drawstart;
	while (y < ray->drawend)
	{
		text->y = (int)text->pos & (text->height - 1);
		text->pos += text->step;
		color = text->textures_addr[text->tex_index][text->width * text->y + text->x];
		text->pixels[y][x] = color;
		y++;
	}
}
