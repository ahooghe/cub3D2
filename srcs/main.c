/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:39:09 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/05 15:51:59 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int main(int argc, char **argv)
{
	t_file file;
	
	if (argc != 2)
		return (printf("You must enter a file of .cub type to execute %s\n", argv[0]) * 0);
	init_file(&file);
	if (parse_file(&file, argv) == FAILURE)
		return (FAILURE);
	exit_cubed(&file, NULL, 0);
}