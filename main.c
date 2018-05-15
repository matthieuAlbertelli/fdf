/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 08:49:45 by malberte          #+#    #+#             */
/*   Updated: 2018/05/13 11:34:57 by malberte         ###   ########.fr       */
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
	t_pixel a;
	t_pixel b;

	(void)argc;
	a[X] = atoi(argv[1]);
	a[Y] = atoi(argv[2]);
	b[X] = atoi(argv[3]);
	b[Y] = atoi(argv[4]);

	ft_init_engine(&engine, 1024, 1024, "FDF");
	ft_draw_line(&engine, &a, &b);
	mlx_loop(engine.mlx_ptr);
	return (0);
}