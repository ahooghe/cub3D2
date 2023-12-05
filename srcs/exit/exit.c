/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:24:23 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/05 15:50:47 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_2dim(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	exit_cubed(t_file *file, char *err, int exitcode)
{
	if (file->file)
		free_2dim(file->file);
	if (file->textures.colors)
		free_2dim(file->textures.colors);
	if (file->textures.textures)
		free_2dim(file->textures.textures);
	if (file->map.map)
		free_2dim(file->map.map);
	if (err)
		printf("%s", err);
	exit(exitcode);
}
