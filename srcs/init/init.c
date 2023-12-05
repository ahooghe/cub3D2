/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:20:53 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/05 18:00:43 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_text(t_text *text, t_file *file)
{
	text->colors = malloc(sizeof(char *) * (3));
	if (!text->colors)
		exit_cubed(file, "Malloc failure.\n", FAILURE);
	text->colors[0] = NULL;
	text->colors[1] = NULL;
	text->colors[2] = NULL;
	text->textures = malloc(sizeof(char *) * (5));
	if (!text->textures)
		exit_cubed(file, "Malloc failure.\n", FAILURE);
	text->textures[0] = NULL;
	text->textures[1] = NULL;
	text->textures[2] = NULL;
	text->textures[3] = NULL;
	text->textures[4] = NULL;
}
void	init_file(t_file *file)
{
	file->amt_lines = 0;
	file->fd = 0;
	file->file = NULL;
	file->map.map = NULL;
	file->mlx.mlx = NULL;
	file->mlx.win = NULL;
	init_text(&file->textures, file);
}
