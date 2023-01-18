/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:12:17 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 13:19:39 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// FORMULA TO CALCULATE THE COLOR FOR LINES
//		plot_z = (((n_point->z - o_point->z) * (plot_x - o_point->x)) 
//									/
//			(n_point->x - o_point->x)) + o_point->z;

int	render_next_frame(t_mlx *mlx)
{
	hook_values(mlx);
	mlx->image.img = mlx_new_image(mlx->info, mlx->length, mlx->width);
	mlx->image.addr = mlx_get_data_addr(mlx->image.img,
			&mlx->image.bits_per_pixel,
			&mlx->image.line_length, &mlx->image.endian);
	mlx->image.length = mlx->length;
	mlx->image.width = mlx->width;
	mlx->image.z_buff = mlx->z_buff;
	project(mlx, mlx->attributes.type);
	fill_image(mlx, mlx->points);
	if (mlx->window)
		mlx_put_image_to_window(mlx->info, mlx->window, mlx->image.img, 0, 0);
	mlx_destroy_image(mlx->info, mlx->image.img);
	return (1);
}

void	free_coordinate(t_coordinates **stuff)
{
	t_coordinates	*current;
	t_coordinates	*temp;

	current = *(stuff);
	while (current)
	{
		temp = current->next;
		current->beside = NULL;
		current->below = NULL;
		free(current);
		current = temp;
	}
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	int		read_file_fd;

	if (ac != 2)
		return (write(2, "plz gibe nem\n", 14));
	read_file_fd = open(av[1], O_RDWR);
	if (read_file_fd == -1)
		return (write(2, "no exists file\n", 16));
	write(1, "Getting points..\n", 17);
	mlx.points = get_points(read_file_fd);
	write(1, "Linking points...\n", 18);
	link_below(mlx.points);
	mlx.length = LENGTH;
	mlx.width = WIDTH;
	mlx.info = mlx_init();
	mlx.window = mlx_new_window(mlx.info, mlx.length,
			mlx.width, "Look At These Points");
	mlx.z_buff = z_buffer(mlx);
	init_attri(mlx, &mlx.attributes, mlx.points);
	init_keys(&mlx.key_press);
	hook_me_up(&mlx);
	mlx_loop_hook(mlx.info, render_next_frame, (void *)&mlx);
	mlx_loop(mlx.info);
}
