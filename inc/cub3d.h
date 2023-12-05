/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:42:15 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/05 17:07:25 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../libs/get_next_line/get_next_line_bonus.h"

typedef struct	s_player
{

}	t_player;

typedef struct	s_ray
{

}	t_ray;

typedef struct s_mlx
{
	void *mlx;
	void *win;
}	t_mlx;

typedef struct	s_map
{
	char	**map;
}	t_map;

typedef struct	s_text
{
	char	**textures;
	char	**colors;
}	t_text;

typedef struct	s_file
{
	int		fd;
	int		amt_lines;
	char	*filepath;
	char	**file;
	t_text		textures;
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_mlx		mlx;
}   t_file;

typedef enum Exithandling
{
	ERROR=-1,
	SUCCESS=0,
	FAILURE=1
};

typedef enum Texturehandling
{
	NORTH=0,
	EAST=1,
	SOUTH=2,
	WEST=3	
};

typedef enum Colorhandling
{
	FLOOR=0,
	CEILING=1
};

void	init_file(t_file *file);

void	free_2dim(char **arr);
void	exit_cubed(t_file *file, char *err, int exitcode);

int		parse_file(t_file *file, char **argv);
int 	get_data_file(t_file *file, char **argv);
void	get_map_data(t_file *file, int index);
void	get_texture_data(t_file *file, char *str);

char	*ft_strdup(const char *str1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isspace(char c);
int		ft_isalpha(char c);
