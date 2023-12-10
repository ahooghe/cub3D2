/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:39:09 by ahooghe           #+#    #+#             */
/*   Updated: 2023/12/06 16:17:28 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	exit_cub3d(t_file *file)
{
	exit_cubed(file, NULL, 0);
	return (0);
}

void	print_instructions(void)
{
	printf("\033[0;31m");
	printf("                                    .--,-``-.                 \n");
	printf("  ,----..                          /   /     '.      ,---,    \n");
	printf(" /   /   \\                ,---,   / ../        ;   .'  .' `\\  \n");
	printf("|   :     :         ,--,,---.'|   \\ ``\\  .`-    ',---.'     \\ \n");
	printf(".   |  ;. /       ,'_ /||   | :    \\___\\/   \\   :|   |  .`\\  |\n");
	printf(".   ; /--`   .--. |  | ::   : :         \\   :   |:   : |  '  |\n");
	printf(";   | ;    ,'_ /| :  . |:     |,-.      /  /   / |   ' '  ;  :\n");
	printf("|   : |    |  ' | |  . .|   : '  |      \\  \\   \\ '   | ;  .  |\n");
	printf(".   | '___ |  | ' |  | ||   |  / :  ___ /   :   ||   | :  |  '\n");
	printf("'   ; : .'|:  | : ;  ; |'   : |: | /   /\\   /   :'   : | /  ; \n");
	printf("'   | '/  :'  :  `--'   \\   | '/ :/ ,,/  ',-    .|   | '` ,/  \n");
	printf("|   :    / :  ,      .-./   :    |\\ ''\\        ; ;   :  .'    \n");
	printf(" \\   \\ .'   `--`----'   /    \\  /  \\   \\     .'  |   ,.'      \n");
	printf("  `---`                 `-'----'    `--`-,,-'    '---'        \n");
	printf("\n");
	printf("\033[1;34mCONTROLS:\n");
	printf("\033[0;36mW\033[0;37m: move forward\t");
	printf("\033[0;36mA\033[0;37m: move left\t");
	printf("\033[0;36mS\033[0;37m: move backward\t");
	printf("\033[0;36mD\033[0;37m: move right\n");
	printf("\033[0;36m<\033[0;37m: turn left\t");
	printf("\033[0;36m>\033[0;37m: turn right\n");
	printf("\033[0;36mShift\033[0;37m: run\n");
	printf("\033[0;36mESC\033[0;37m: quit\n");
}

int	main(int argc, char **argv)
{
	t_file	file;

	if (argc != 2)
		return (printf("You must enter a file of .cub type to execute %s\n", argv[0]) * 0);
	init_file(&file);
	if (parse_file(&file, argv) == FAILURE)
		return (FAILURE);
	init_mlx(&file);
	create_textures(&file);
	print_instructions();
	mlx_hook(file.mlx.win, ClientMessage, NoEventMask, exit_cub3d, &file);
	mlx_hook(file.mlx.win, KeyPress, KeyPressMask, key_press, &file);
	mlx_hook(file.mlx.win, KeyRelease, KeyReleaseMask, key_release, &file);
	mlx_loop_hook(file.mlx.mlx, render, &file);
	mlx_loop(file.mlx.mlx);
	exit_cubed(&file, NULL, 0);
}
