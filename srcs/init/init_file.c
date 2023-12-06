/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:20:53 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/06 02:19:08 by ahooghe          ###   ########.fr       */
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
	text->floor[0] = 0;
	text->floor[1] = 0;
	text->floor[2] = 0;
	text->ceiling[0] = 0;
	text->ceiling[1] = 0;
	text->ceiling[2] = 0;
}

void	init_player(t_player *player)
{
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
	player->sprint = 1;
	player->pos_x = 0;
	player->pos_y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
}

void	init_file(t_file *file)
{
	file->amt_lines = 0;
	file->fd = 0;
	file->file = NULL;
	file->map.map = NULL;
	file->map.amt_lines = 0;
	file->map.longestline = 0;
	file->map.dir = 0;
	file->mlx.mlx = NULL;
	file->mlx.win = NULL;
	init_text(&file->textures, file);
	init_player(&file->player);
}
