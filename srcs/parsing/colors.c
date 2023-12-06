/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:26:32 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/06 00:34:47 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	setcolorstring(t_text *text, char *str, int index, int i)
{
	int	start;

	while (str[i] && ft_isspace(str[i]))
		i++;
	start = i;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	text->colors[index] = ft_substr(str, start, i - start);
	return (SUCCESS);
}

void	checkcolors(char **str, t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			while (ft_isspace(str[i][j]))
				j++;
			if (str[i][j] && (str[i][j] < '0' || str[i][j] > '9'))
			{
				free_2dim(str);
				exit_cubed(file, "The color is not formatted correctly.\n", FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	setcolorssimple(t_file *file, int index)
{
	char	**tmp;

	tmp = ft_split(file->textures.colors[index], ',');
	if (!tmp)
		exit_cubed(file, "Malloc failure.\n", FAILURE);
	if (!tmp[RED] || !tmp[GREEN] || !tmp[BLUE])
		exit_cubed(file, "The color is not formatted correctly.\n", FAILURE);
	checkcolors(tmp, file);
	if (index == FLOOR)
	{
		file->textures.floor[RED] = ft_atoi(tmp[RED]);
		file->textures.floor[GREEN] = ft_atoi(tmp[GREEN]);
		file->textures.floor[BLUE] = ft_atoi(tmp[BLUE]);
	}
	else if (index == CEILING)
	{
		file->textures.ceiling[RED] = ft_atoi(tmp[RED]);
		file->textures.ceiling[GREEN] = ft_atoi(tmp[GREEN]);
		file->textures.ceiling[BLUE] = ft_atoi(tmp[BLUE]);
	}
	free_2dim(tmp);
}

void	setcolors(t_file *file, char *str)
{
	int	i;
	int	code;

	i = 0;
	code = FAILURE;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && str[i] == 'C' && !file->textures.colors[CEILING])
	{
		code = setcolorstring(&file->textures, str, CEILING, i + 2);
		setcolorssimple(file, CEILING);
	}
	else if (str[i] && str[i] == 'F' && !file->textures.colors[FLOOR])
	{
		code = setcolorstring(&file->textures, str, FLOOR, i + 2);
		setcolorssimple(file, FLOOR);
	}
	if (code == FAILURE)
		exit_cubed(file, "Hex formatting wrong.\n", FAILURE);
}
