/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:19:16 by malberte          #+#    #+#             */
/*   Updated: 2018/05/13 19:00:47 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
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
