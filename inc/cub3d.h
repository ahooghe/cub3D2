/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:42:15 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/11 00:09:57 by ahooghe          ###   ########.fr       */
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
#include <errno.h>
#include "../libs/get_next_line/get_next_line_bonus.h"
#include "../libs/minilibx-linux/mlx.h"

#define WIDTH 1000
#define HEIGHT 750

#define MOVESPEED 0.015
#define ROTSPEED 0.015

#define TEXWIDTH 64
#define TEXHEIGHT 64

typedef struct s_ray
{
	double	plane_x;
	double	plane_y;
	double	camera_pos;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	wall_pos;
	double	walldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
}	t_ray;

typedef struct	s_player
{
	int		move_y;
	int		move_x;
	int		rotate;
	int		sprint;
	double	dir_x;
	double	dir_y;
	double	pos_x;
	double	pos_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_map
{
	char	**map;
	char	dir;
	int		amt_lines;
	int		longestline;
}	t_map;

typedef struct	s_text
{
	char			**textures;
	char			**colors;
	int				floor[3];
	int				ceiling[3];
	unsigned long	floor_color;
	unsigned long	ceiling_color;
	int				tex_size[2];
	int				**textures_addr;
	int				**pixels;
	int				width;
	int				height;
	int				x;
	int				y;
	int				tex_index;
	double			step;
	double			pos;
}	t_text;

typedef struct	s_file
{
	int			fd;
	int			amt_lines;
	char		*filepath;
	char		**file;
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

enum e_axis
{
	TWIDTH=0,
	THEIGHT=1	
};

void	init_file(t_file *file);
void	init_mlx(t_file *file);
void	init_ray(t_ray *ray);
int		key_press(int keycode, t_file *file);
int		key_release(int keycode, t_file *file);

void	free_2dim(void **arr);
void	exit_cubed(t_file *file, char *err, int exitcode);

int		parse_file(t_file *file, char **argv);
int 	get_data_file(t_file *file, char **argv);
void	get_map_data(t_file *file, int index);
void	get_texture_data(t_file *file, char *str);
void	setcolors(t_file *file, char *str);
void	check_textures(t_file *file);
void	check_colors(t_file *file);
void	create_textures(t_file *file);

void	handle_movement(t_file *file);

int		render(t_file *file);
void	malloc_texture_pixels(t_file *file, int i);
void	draw_line(t_ray *ray, t_text *text, t_file *file, int x);
void	mlx(t_text *tex, t_file *file, int x, int y);

char	*ft_strdup(char *str1);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_isspace(char c);
int		ft_isalpha(char c);
char	**ft_split(char *s, char c);
int		ft_atoi(char *str);
void	setdir(t_file *file, char c, int i, int j);
void	*ft_calloc(size_t count, size_t size);
