/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:42:15 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/06 02:41:10 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "../libs/get_next_line/get_next_line_bonus.h"
#include "../libs/minilibx-linux/mlx.h"

#define WIDTH 1000
#define HEIGHT 750

#define MOVESPEED 0.015
#define ROTSPEED 0.015

typedef struct	s_player
{
	int	move_y;
	int	move_x;
	int	rotate;
	int	sprint;
	double	dir_x;
	double	dir_y;
	double	pos_x;
	double	pos_y;
	double	plane_x;
	double	plane_y;
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
	char	dir;
	int		amt_lines;
	int		longestline;
}	t_map;

typedef struct	s_text
{
	char	**textures;
	char	**colors;
	int		floor[3];
	int		ceiling[3];
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

enum e_exit
{
	ERROR=-1,
	SUCCESS=0,
	FAILURE=1
};

enum e_texture
{
	NORTH=0,
	EAST=1,
	SOUTH=2,
	WEST=3	
};

enum e_color
{
	FLOOR=0,
	CEILING=1
};

enum e_colorcode
{
	RED=0,
	GREEN=1,
	BLUE=2
};

void	init_file(t_file *file);
void	init_mlx(t_file *file);
int		key_press(int keycode, t_file *file);
int		key_release(int keycode, t_file *file);

void	free_2dim(char **arr);
void	exit_cubed(t_file *file, char *err, int exitcode);

int		parse_file(t_file *file, char **argv);
int 	get_data_file(t_file *file, char **argv);
void	get_map_data(t_file *file, int index);
void	get_texture_data(t_file *file, char *str);
void	setcolors(t_file *file, char *str);

void	handle_movement(t_file *file);

int		render(t_file *file);

char	*ft_strdup(char *str1);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_isspace(char c);
int		ft_isalpha(char c);
char	**ft_split(char *s, char c);
int		ft_atoi(char *str);
void	setdir(t_file *file, char c, int i, int j);
