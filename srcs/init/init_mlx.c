/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:45:23 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/06 02:36:53 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_mlx(t_file *file)
{
	file->mlx.mlx = mlx_init();
	if (!file->mlx.mlx)
		exit_cubed(file, "mlx_init() failed\n", FAILURE);
	file->mlx.win = mlx_new_window(file->mlx.mlx, WIDTH, HEIGHT, "cub3D");
	if (!file->mlx.win)
		exit_cubed(file, "mlx_new_window() failed\n", FAILURE);
}
