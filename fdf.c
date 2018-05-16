/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:25:39 by malberte          #+#    #+#             */
/*   Updated: 2018/05/16 04:37:16 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_engine.h"
#include "ft_mid_point.h"

void	ft_translation(t_engine *e, t_point vector)
{
	unsigned int	y;
	unsigned int	x;
	int dim;

	y = 0;
	while (y < e->map3d_i)
	{
		x = 0;
		while (x < e->map3d[y].i)
		{
			dim = X;
			while (dim < 3)
			{
				e->map3d[y].tab[x][dim] += vector[dim];
				++dim;
			}
			++x;
		}
		++y;
	}
}

void	ft_draw_fdf(t_engine *e)
{
	unsigned int	y;
	unsigned int	x;
	t_pixel			pix_a;
	t_pixel			pix_b;

	y = 0;
	while (y < e->map3d_i)
	{
		x = 0;
		while (x < e->map3d[y].i - 1)
		{
			ft_perspective_projection(pix_a, e, e->map3d[y].tab[x]);
			ft_perspective_projection(pix_b, e, e->map3d[y].tab[++x]);
			ft_draw_line(e, &pix_a, &pix_b);
		}
		++y;
	}
	x = 0;
	y = 0;
	while (x < e->map3d[y].i)
	{
		y = 0;
		while (y < e->map3d_i - 1)
		{
			ft_perspective_projection(pix_a, e, e->map3d[y].tab[x]);
			ft_perspective_projection(pix_b, e, e->map3d[++y].tab[x]);
			ft_draw_line(e, &pix_a, &pix_b);
		}
		++x;
	}
}