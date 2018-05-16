/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 08:49:45 by malberte          #+#    #+#             */
/*   Updated: 2018/05/16 15:07:13 by malberte         ###   ########.fr       */
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
	t_point vector = {-10, -15, 10};
	(void)argc;
	t_engine engine;
	ft_init_engine(&engine, 1048, 1048, "FDF");
	ft_init_camera(&engine, 90);
	ft_read_map(&engine, argv[1]);
	ft_translation(&engine, vector);
	ft_draw_fdf(&engine);
	mlx_loop(engine.mlx_ptr);
	return (0);
}