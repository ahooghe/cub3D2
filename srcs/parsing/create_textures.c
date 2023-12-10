/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:17:42 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/10 20:02:29 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	img_setnull(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_length = 0;
	img->endian = 0;
}

static int	*init_mlx_img(t_img *img, t_file *file, char *path, int y)
{
	int	*tmp;
	int	x;
	
	img_setnull(img);
	img->img = mlx_xpm_file_to_image(file->mlx.mlx, path, \
		&file->textures.width, &file->textures.height);
	if (!img->img)
		exit_cubed(file, "mlx_xpm_file_to_image() failed\n", FAILURE);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp, \
		&img->line_length, &img->endian);
	if (!img->addr)
		exit_cubed(file, "mlx_get_data_addr() failed\n", FAILURE);
	tmp = ft_calloc(file->textures.height * file->textures.width, sizeof(int));
	if (!tmp)
		exit_cubed(file, "Malloc failure.\n", FAILURE);
	while (++y < file->textures.height)
	{
		x = 0;
		while (x < file->textures.width)
		{
			tmp[y * file->textures.width + x] = img->addr[y * (img->line_length / 4) + x];
			x++;
		}
	}
	return (tmp);
}

void	create_textures(t_file *file)
{
	t_img	img;
	
	file->textures.textures_addr = ft_calloc(5, sizeof(int *));
	if (!file->textures.textures_addr)
		exit_cubed(file, "Malloc failure.\n", FAILURE);
	file->textures.textures_addr[NORTH] = init_mlx_img(&img, file, file->textures.textures[NORTH], -1);
	mlx_destroy_image(file->mlx.mlx, img.img);
	file->textures.textures_addr[SOUTH] = init_mlx_img(&img, file, file->textures.textures[SOUTH], -1);
	mlx_destroy_image(file->mlx.mlx, img.img);
	file->textures.textures_addr[EAST] = init_mlx_img(&img, file, file->textures.textures[EAST], -1);
	mlx_destroy_image(file->mlx.mlx, img.img);
	file->textures.textures_addr[WEST] = init_mlx_img(&img, file, file->textures.textures[WEST], -1);
	mlx_destroy_image(file->mlx.mlx, img.img);
}
