/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:50:24 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/10 20:01:45 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	exit_c(t_file *file, char *str, int ret, char *dir)
{
	printf("%s%s\n", dir, str);
	exit_cubed(file, NULL, ret);
}

void	check_file(char **textures, t_file *file)
{
	int	fd;

	fd = open(textures[NORTH], O_RDONLY);
	if (fd == -1)
		exit_c(file, strerror(errno), FAILURE, "North texture: ");
	close(fd);
	fd = open(textures[SOUTH], O_RDONLY);
	if (fd == -1)
		exit_c(file, strerror(errno), FAILURE, "South texture: ");
	close(fd);
	fd = open(textures[EAST], O_RDONLY);
	if (fd == -1)
		exit_c(file, strerror(errno), FAILURE, "East texture: ");
	close(fd);
	fd = open(textures[WEST], O_RDONLY);
	if (fd == -1)
		exit_c(file, strerror(errno), FAILURE, "West texture: ");
	close(fd);
}

void	check_textures(t_file *file)
{
	if (!file->textures.textures[NORTH])
		exit_cubed(file, "No north texture.\n", FAILURE);
	if (!file->textures.textures[SOUTH])
		exit_cubed(file, "No south texture.\n", FAILURE);
	if (!file->textures.textures[EAST])
		exit_cubed(file, "No east texture.\n", FAILURE);
	if (!file->textures.textures[WEST])
		exit_cubed(file, "No west texture.\n", FAILURE);
	check_file(file->textures.textures, file);
}

void	check_colors(t_file *file)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (file->textures.floor[i] < 0 || file->textures.floor[i] > 255)
			exit_cubed(file, "Invalid floor color.\n", FAILURE);
		if (file->textures.ceiling[i] < 0 || file->textures.ceiling[i] > 255)
			exit_cubed(file, "Invalid ceiling color.\n", FAILURE);
		i++;
	}
	file->textures.ceiling_color = (unsigned long) \
		((file->textures.ceiling[RED] & 0xff) \
		* 65536) + ((file->textures.ceiling[GREEN] & 0xff) * 256) + \
		(file->textures.ceiling[BLUE] & 0xff);
	file->textures.floor_color = (unsigned long) \
		((file->textures.floor[RED] & 0xff) * \
		65536) + ((file->textures.floor[GREEN] & 0xff) * 256) + \
		(file->textures.floor[BLUE] & 0xff);
}
