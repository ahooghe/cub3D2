/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:52:10 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/10 23:51:52 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	initplayer(t_file *file)
{
	if (file->map.dir == 'N')
	{
		file->player.dir_y = -1;
		file->player.plane_x = 0.50;
	}
	else if (file->map.dir == 'S')
	{
		file->player.dir_y = 1;
		file->player.plane_x = -0.50;
	}
	else if (file->map.dir == 'E')
	{
		file->player.dir_x = 1;
		file->player.plane_y = 0.50;
	}
	else if (file->map.dir == 'W')
	{
		file->player.dir_x = -1;
		file->player.plane_y = -0.50;
	}
}

static void	setplayerdir(t_file *file)
{
	if (file->map.dir == 'N' || file->map.dir == 'S' || \
		file->map.dir == 'E' || file->map.dir == 'W')
		initplayer(file);
	else
		exit_cubed(file, "Invalid player direction.\n", FAILURE);
}

int	parse_file(t_file *file, char **argv)
{
	int	i;
	int	j;

	if (get_data_file(file, argv) == FAILURE)
		return (FAILURE);
	i = 0;
	while (file->file[i])
	{
		j = 0;
		while (ft_isspace(file->file[i][j]))
			j++;
		if (file->file[i][j] == '0' || file->file[i][j] == '1')
		{
			get_map_data(file, i);
			break ;
		}
		else
			get_texture_data(file, file->file[i]);
		i++;
	}
	setplayerdir(file);
	check_textures(file);
	check_colors(file);
	return (SUCCESS);
}
