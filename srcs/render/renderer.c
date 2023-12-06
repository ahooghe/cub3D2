/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:57:30 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/06 02:46:41 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//render_new_frame(file);
//draw_frame(file);
int	render(t_file *file)
{
	handle_movement(file);
	return (SUCCESS);
}
