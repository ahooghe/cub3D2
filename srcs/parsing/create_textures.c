/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:17:42 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/11 00:08:55 by ahooghe          ###   ########.fr       */
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
		x = -1;
		while (++x < file->textures.width)
		{
			tmp[y * file->textures.width + x] = \
				img->addr[y * (img->line_length / 4) + x];
		}
	}
	return (tmp);
}

static void	check_texture_sizes(t_file *file)
{
	t_img	img;
	int		oldheight;
	int		oldwidth;
	int		i;

	img.img = \
		mlx_xpm_file_to_image(file->mlx.mlx, file->textures.textures[NORTH], \
		&file->textures.width, &file->textures.height);
	oldheight = file->textures.height;
	oldwidth = file->textures.width;
	mlx_destroy_image(file->mlx.mlx, img.img);
	i = 1;
	while (i != 4)
	{
		img.img = mlx_xpm_file_to_image(file->mlx.mlx, \
			file->textures.textures[i], &file->textures.width, \
			&file->textures.height);
		if (oldheight != file->textures.height || \
			oldwidth != file->textures.width)
			exit_cubed(file, "Texture sizes do not match.\n", FAILURE);
		mlx_destroy_image(file->mlx.mlx, img.img);
		i++;
	}
}

void	create_textures(t_file *file)
{
	t_img	img;

	file->textures.textures_addr = ft_calloc(5, sizeof(int *));
	if (!file->textures.textures_addr)
		exit_cubed(file, "Malloc failure.\n", FAILURE);
	check_texture_sizes(file);
	file->textures.textures_addr[NORTH] = \
		init_mlx_img(&img, file, file->textures.textures[NORTH], -1);
	mlx_destroy_image(file->mlx.mlx, img.img);
	file->textures.textures_addr[SOUTH] = \
		init_mlx_img(&img, file, file->textures.textures[SOUTH], -1);
	mlx_destroy_image(file->mlx.mlx, img.img);
	file->textures.textures_addr[EAST] = \
		init_mlx_img(&img, file, file->textures.textures[EAST], -1);
	mlx_destroy_image(file->mlx.mlx, img.img);
	file->textures.textures_addr[WEST] = \
		init_mlx_img(&img, file, file->textures.textures[WEST], -1);
	mlx_destroy_image(file->mlx.mlx, img.img);
}
