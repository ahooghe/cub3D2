/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:52:10 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/05 17:52:44 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
	return (SUCCESS);
}
