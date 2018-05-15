/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:19:16 by malberte          #+#    #+#             */
/*   Updated: 2018/05/15 21:32:40 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "ft_engine.h"

void	ft_init_engine(t_engine *engine, int size_x, int size_y, char *title)
{
	if (engine == NULL)
	{
		perror("You have to supply an engine pointer to initialize it");
		exit(0);
	}
	if (size_x <= 0 || size_y <= 0)
	{
		perror("You have to supply positive sizes to initalize the window");
		exit(0);
	}
	if (title == NULL)
	{
		perror("You have to supply a title name to initialize the window");
		exit(0);
	}
	engine->mlx_ptr = mlx_init();
	if (engine->mlx_ptr == NULL)
	{
		perror("Failed to initialize mlx_ptr. Abort.");
		exit(0);
	}
	engine->win_ptr = mlx_new_window(engine->mlx_ptr, size_x, size_y, title);
	if (engine->win_ptr == NULL)
	{
		perror("Failed to initialize the window. Abort.");
		exit(0);
	}
	engine->col = COLOR_WHITE;
	engine->size_x = size_x;
	engine->size_y = size_y;
}

void ft_init_camera(t_engine *engine, int opening_angle)
{
	engine->opening_angle = opening_angle;
	engine->camera_dist = engine->size_x / (2 * tan(opening_angle / 2));
	engine->cam_focus[X] = engine->size_x / 2;
	engine->cam_focus[Y] = engine->size_y / 2;
}

void ft_perspective_projection(t_pixel pix, const t_engine *e, const t_pos_3d point)
{
	pix[X] = e->cam_focus[X] + point[X] * (e->camera_dist / point[Z]);
	pix[Y] = e->cam_focus[Y] - (point[Y] * (e->camera_dist / point[Z]));
}
