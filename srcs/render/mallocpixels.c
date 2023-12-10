/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocpixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:39:13 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/10 17:00:35 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	malloc_texture_pixels(t_file *file, int i)
{
	if (file->textures.pixels)
		free_2dim((void **)file->textures.pixels);
	file->textures.pixels = ft_calloc(HEIGHT + 1, sizeof(int *));
	if (!file->textures.pixels)
		exit_cubed(file, "Malloc error\n", 1);
	while (i < HEIGHT)
	{
		file->textures.pixels[i] = ft_calloc(WIDTH + 1, sizeof(int));
		if (!file->textures.pixels[i])
			exit_cubed(file, "Malloc error\n", 1);
		i++;
	}
}
