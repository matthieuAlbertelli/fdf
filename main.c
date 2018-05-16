/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 08:49:45 by malberte          #+#    #+#             */
/*   Updated: 2018/05/16 03:05:41 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_position.h"
#include "ft_engine.h"
#include "ft_mid_point.h"

int main(int argc, char **argv)
{
	t_engine engine;
	ft_init_engine(&engine, 1024, 1024, "FDF");
	ft_init_camera(&engine, 90);
	ft_read_map(&engine, argv[1]);
	(void)argc;
	// t_engine engine;
	// t_pixel px[3];
	// // t_pixel b;
	// t_point point[3];
	
	// set_pos3d(point[0], -5, 0, 20);
	// set_pos3d(point[1], 0, 10, 20);
	// set_pos3d(point[2], 5, 0, 20);
	// (void)argc;
	// (void)argv;
	// // a[X] = atoi(argv[1]);
	// // a[Y] = atoi(argv[2]);
	// // b[X] = atoi(argv[3]);
	// // b[Y] = atoi(argv[4]);

	// ft_perspective_projection(px[0], &engine, point[0]);
	// ft_perspective_projection(px[1], &engine, point[1]);
	// ft_perspective_projection(px[2], &engine, point[2]);
	// ft_draw_line(&engine, &px[0], &px[2]);
	// ft_draw_line(&engine, &px[0], &px[1]);
	// ft_draw_line(&engine, &px[1], &px[2]);
	// mlx_loop(engine.mlx_ptr);
	return (0);
}