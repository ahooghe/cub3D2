/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:30:28 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/10 20:00:59 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_length = 0;
	img->endian = 0;
}

void	mlx(t_file *file, int x, int y)
{
	t_img	img;
	
	init_img(&img);
	img.img = mlx_new_image(file->mlx.mlx, WIDTH, HEIGHT);
	if (!img.img)
		exit_cubed(file, "Mlx error\n", 1);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bpp,
			&img.line_length, &img.endian);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (file->textures.pixels[y][x])
				img.addr[y * (img.line_length / 4) + x] = file->textures.pixels[y][x];
			else if (y < HEIGHT / 2)
				img.addr[y * (img.line_length / 4) + x] = file->textures.ceiling_color;
			else
				img.addr[y * (img.line_length / 4) + x] = file->textures.floor_color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(file->mlx.mlx, file->mlx.win, img.img, 0, 0);
	mlx_destroy_image(file->mlx.mlx, img.img);
}
