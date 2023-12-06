/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:31:54 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/06 02:47:33 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	mallocmaplines(t_file *file, int index)
{
	int	i;

	i = 0;
	while (file->file[index + i])
		i++;
	file->map.map = malloc(sizeof(char *) * (i + 1));
	if (!file->map.map)
		exit_cubed(file, "Malloc error.\n", FAILURE);
	file->map.map[i] = NULL;
}

int	checkwalls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if ((i == 0 || i == map->amt_lines || j == 0 || \
				j == ((int)ft_strlen(map->map[i]))) && \
				map->map[i][j] && map->map[i][j] != '1')
				return (FAILURE);
			if (map->map[i][j] == '0' && i > 0 && i < map->amt_lines && \
				j > 0 && j < (int)(ft_strlen(map->map[i])))
				if ((map->map[i + 1][j] == '\0') || \
				(map->map[i - 1][j] == '\0') || \
				(map->map[i][j + 1] == '\0') || \
				(map->map[i][j - 1] == '\0')) 
					return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	checkmap(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] && \
				(map->map[i][j] != '0' && map->map[i][j] != '1' && \
				map->map[i][j] != 'W' && map->map[i][j] != 'N' && \
				map->map[i][j] != 'S' && map->map[i][j] != 'E'))
				return (FAILURE);
			j++;
		}
		i++;
	}
	map->amt_lines = i - 1;
	if (checkwalls(map) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

void	fill_map(t_file *file, int index, int i, int j)
{
	while (file->file[index + i])
	{
		j = 0;
		while (j < file->map.longestline - 1)
		{
			if (file->file[index + i][j] == 'N' || \
				file->file[index + i][j] == 'S' || \
				file->file[index + i][j] == 'E' || \
				file->file[index + i][j] == 'W')
			{
				if (file->map.dir == 0)
					setdir(file, file->file[index + i][j], i, j);
				else
					exit_cubed(file, "The map has more than one player.\n", FAILURE);
			}
			if (file->file[index + i][j] && file->file[index + i][j] == ' ')
				file->map.map[i][j] = '1';
			else if (file->file[index + i][j] != '\n')
				file->map.map[i][j] = file->file[index + i][j];
			else
				file->map.map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

void	get_map_data(t_file *file, int index)
{
	int	i;

	mallocmaplines(file, index);
	i = index - 1;
	while (++i < file->amt_lines)
		if ((int)ft_strlen(file->file[i]) > file->map.longestline)
			file->map.longestline = ft_strlen(file->file[i]);
	i = 0;
	while (file->file[index + i])
	{
		file->map.map[i] = malloc(sizeof(char) * file->map.longestline + 1);
		if (!file->map.map[i])
			exit_cubed(file, "Malloc error.\n", FAILURE);
		file->map.map[i][file->map.longestline] = '\0';
		i++;
	}
	fill_map(file, index, 0, 0);
	if (checkmap(&file->map) == FAILURE)
		exit_cubed(file, "The map is not valid.\n", FAILURE);
}
