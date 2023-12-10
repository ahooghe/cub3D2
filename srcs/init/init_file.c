/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:20:53 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/10 22:19:37 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_text(t_text *text, t_file *file)
{
	int	i;

	i = 0;
	text->colors = ft_calloc(3, sizeof(char *));
	text->textures = ft_calloc(5, sizeof(char *));
	if (!text->colors || !text->textures)
		exit_cubed(file, "Malloc failure.\n", FAILURE);
	while (i < 3)
	{
		text->colors[i] = NULL;
		text->floor[i] = 0;
		text->ceiling[i] = 0;
		i++;
	}
	i = 0;
	while (i < 5)
		text->textures[i++] = NULL;
	text->tex_size[0] = 0;
	text->tex_size[1] = 0;
	text->width = TEXWIDTH;
	text->height = TEXHEIGHT;
	text->textures_addr = NULL;
	text->pixels = NULL;
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

void	init_mlx_empty(t_mlx *mlx)
{
	mlx->addr = NULL;
	mlx->img = NULL;
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->bpp = 0;
	mlx->line_length = 0;
	mlx->endian = 0;
}

void	init_ray(t_ray *ray)
{
	ray->plane_x = 0.0;
	ray->plane_y = 0.0;
	ray->camera_pos = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->sidedist_x = 0.0;
	ray->sidedist_y = 0.0;
	ray->deltadist_x = 0.0;
	ray->deltadist_y = 0.0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->wall_pos = 0.0;
	ray->walldist = 0.0;
	ray->lineheight = 0;
	ray->drawstart = 0;
	ray->drawend = 0;
}

void	init_file(t_file *file)
{
	file->amt_lines = 0;
	file->fd = 0;
	file->file = NULL;
	file->filepath = NULL;
	file->map.map = NULL;
	file->map.amt_lines = 0;
	file->map.longestline = 0;
	file->map.dir = 0;
	init_mlx_empty(&file->mlx);
	init_text(&file->textures, file);
	init_player(&file->player);
	init_ray(&file->ray);
}
