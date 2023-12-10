/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:24:23 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/10 17:02:14 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_2dim(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_map(t_map *map)
{
	if (map->map)
		free_2dim((void **)map->map);
}

void	free_tex(t_text *tex)
{
	if (tex->colors)
		free_2dim((void **)tex->colors);
	if (tex->textures)
		free_2dim((void **)tex->textures);
	if (tex->textures_addr)
		free_2dim((void **)tex->textures_addr);
	if (tex->pixels)
		free_2dim((void **)tex->pixels);
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
}

void	exit_cubed(t_file *file, char *err, int exitcode)
{
	(void)(file);
	/*if (file->file)
		free_2dim((void **)file->file);
	if (file->filepath)
		free(file->filepath);
	free_map(&file->map);
	free_tex(&file->textures);
	free_mlx(&file->mlx);*/
	if (err)
		printf("%s", err);
	exit(exitcode);
}
