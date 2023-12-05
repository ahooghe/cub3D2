/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:31:54 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/05 16:32:04 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int		countmaplines(t_file *file, int index)
{
	int	i;

	i = 0;
	while(file->file[index])
	{
		index++;
		i++;
	}
	return (i);
}

void	get_map_data(t_file *file, int index)
{
	int	i;
	int	j;
	int	lines;

	i = 0;
	lines = countmaplines(file, index);
	file->map.map = malloc(sizeof(char *) * lines + 1);
	if (!file->map.map)
		exit_cubed(file, "Malloc error.\n", FAILURE);
	file->map.map[lines] = NULL;
	while (index < file->amt_lines)
	{
		j = 0;
		file->map.map[i] = ft_strdup(file->file[index]);
		while (ft_isspace(file->map.map[i][j]))
			j++;
		if (file->map.map[i][j] != '1' && file->map.map[i][j] != '0')
			exit_cubed(file, "The map is not at the end of the file.\n", FAILURE);
		i++;
		index++;
	}
}