/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:23:53 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/06 00:36:35 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	validate_file(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 4] == '.' && str[i - 3] == 'c' && \
		str[i - 2] == 'u' && str[i - 1] == 'b')
		return (SUCCESS);
	return (FAILURE);
}

int	count_lines(t_file *file)
{
	char	*tmp;
	int		i;
	int		fd;

	i = 1;
	fd = open(file->filepath, O_RDONLY);
	if (fd == -1)
		exit_cubed(file, "Failed to open file.\n", FAILURE);
	tmp = get_next_line(fd);
	while (tmp)
	{
		i++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (tmp)
		free(tmp);
	return (i - 1);
}

void	readfile(t_file *file)
{
	char	*tmp;
	int		i;

	i = 0;
	file->amt_lines = count_lines(file);
	if (file->amt_lines == 0)
		exit_cubed(file, "The entered file is empty.\n", FAILURE);
	file->file = malloc(sizeof(char *) * (file->amt_lines + 1));
	if (!file->file)
		exit_cubed(file, "Malloc failure.\n", FAILURE);
	file->file[file->amt_lines] = NULL;
	file->fd = open(file->filepath, O_RDONLY);
	if (file->fd == -1)
		exit_cubed(file, "Failed to open file.\n", FAILURE);
	while (i < file->amt_lines)
	{
		tmp = get_next_line(file->fd);
		file->file[i] = tmp;
		i++;
	}
	if (close(file->fd) == -1)
		exit_cubed(file, "Failed to close the file.\n", FAILURE);
}

int	get_data_file(t_file *file, char **argv)
{
	if (validate_file(argv[1]) == FAILURE)
		return (printf("The file does not have the .cub suffix.\n"), FAILURE);
	if (open(argv[1], O_RDONLY) == -1)
		return (printf("The entered argument cannot be opened.\n"), FAILURE);
	file->filepath = argv[1];
	readfile(file);
	return (SUCCESS);
}
