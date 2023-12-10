/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:57:30 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/11 00:09:46 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	calculate_line(t_ray *ray, t_player *player)
{
	if (ray->side == -1)
	{
		ray->walldist = (ray->map_x - player->pos_x + \
			(1 - ray->step_x) / 2) / ray->raydir_x;
		ray->wall_pos = player->pos_y + ray->walldist * ray->raydir_y;
	}
	else
	{
		ray->walldist = (ray->map_y - player->pos_y + \
			(1 - ray->step_y) / 2) / ray->raydir_y;
		ray->wall_pos = player->pos_x + ray->walldist * ray->raydir_x;
	}
	ray->wall_pos -= floor(ray->wall_pos);
	ray->lineheight = (int)(HEIGHT / ray->walldist);
	ray->drawstart = HEIGHT / 2 - ray->lineheight / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = (ray->lineheight / 2 + HEIGHT / 2);
	if (ray->drawend >= HEIGHT)
		ray->drawend = HEIGHT - 1;
}

static void	moredda(t_ray *ray, t_file *file)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = -1;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (file->map.map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
}

static void	dda(t_ray *ray, t_player *player, t_file *file)
{
	if (player->dir_x > 0)
	{
		ray->step_x = 1;
		ray->sidedist_x = ray->deltadist_x * (ray->map_x + 1.0 - player->pos_x);
	}
	if (player->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = ray->deltadist_x * (player->pos_x - ray->map_x);
	}
	if (player->dir_y > 0)
	{
		ray->step_y = 1;
		ray->sidedist_y = ray->deltadist_y * (ray->map_y + 1.0 - player->pos_y);
	}
	if (player->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = ray->deltadist_y * (player->pos_y - ray->map_y);
	}
	moredda(ray, file);
	calculate_line(ray, player);
}

static void	raycasting(t_player *player, t_file *file, int x)
{
	t_ray	ray;

	while (x < WIDTH)
	{
		init_ray(&ray);
		ray.camera_pos = 2 * x / (double)WIDTH - 1;
		ray.raydir_x = player->dir_x + player->plane_x * ray.camera_pos;
		ray.raydir_y = player->dir_y + player->plane_y * ray.camera_pos;
		ray.deltadist_x = fabs(1 / ray.raydir_x);
		ray.deltadist_y = fabs(1 / ray.raydir_y);
		ray.map_x = (int)player->pos_x;
		ray.map_y = (int)player->pos_y;
		dda(&ray, player, file);
		draw_line(&ray, &file->textures, file, x);
		x++;
	}
}

int	render(t_file *file)
{
	handle_movement(file);
	malloc_texture_pixels(file, 0);
	raycasting(&file->player, file, 0);
	mlx(&file->textures, file, 0, 0);
	return (SUCCESS);
}
