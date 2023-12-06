/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:33:45 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/06 00:42:16 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	settexture(t_text *text, char *str, int index, int i)
{
	int	start;

	if (str[i] && !ft_isspace(str[i]))
		return (FAILURE);
	while (str[i] && ft_isspace(str[i]))
		i++;
	start = i;
	while (str[i] && (ft_isalpha(str[i]) || str[i] == '.'))
		i++;
	text->textures[index] = ft_substr(str, start, i - start);
	return (SUCCESS);
}

void	validate_texture(t_file *file, char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	i += 3;
	while (str[i] && (ft_isalpha(str[i]) || str[i] == '.'))
		i++;
	if (!(str[i - 4] == '.' && str[i - 3] == 'x' && \
		str[i - 2] == 'p' && str[i - 1] == 'm'))
		exit_cubed(file, "A file does not have the .xpm suffix.\n", FAILURE);
}

void	settexturepath(t_file *file, char *str)
{
	int	i;
	int	code;

	i = 0;
	code = FAILURE;
	validate_texture(file, str);
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && str[i] == 'N' && str[i + 1] == 'O' && \
		!file->textures.textures[NORTH])
		code = settexture(&file->textures, str, NORTH, i + 2);
	else if (str[i] && str[i] == 'S' && str[i + 1] == 'O' && \
		!file->textures.textures[SOUTH])
		code = settexture(&file->textures, str, SOUTH, i + 2);
	else if (str[i] && str[i] == 'E' && str[i + 1] == 'A' && \
		!file->textures.textures[EAST])
		code = settexture(&file->textures, str, EAST, i + 2);
	else if (str[i] && str[i] == 'W' && str[i + 1] == 'E' && \
		!file->textures.textures[WEST])
		code = settexture(&file->textures, str, WEST, i + 2);
	if (code == FAILURE)
		exit_cubed(file, "The format of the textures is wrong.\n", FAILURE);
}

void	get_texture_data(t_file *file, char *str)
{
	int	j;

	j = 0;
	while (str[j] && str[j + 1])
	{
		if (ft_isspace(str[j]))
			j++;
		else if (ft_isalpha(str[j]) && ft_isalpha(str[j + 1]))
		{
			settexturepath(file, str);
			break ;
		}
		else if (ft_isalpha(str[j]) && ft_isspace(str[j + 1]))
		{
			setcolors(file, str);
			break ;
		}
		else
			exit_cubed(file, "The file is not structured correctly.\n", FAILURE);
		j++;
	}
}
