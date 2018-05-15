/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel_octant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 11:28:20 by malberte          #+#    #+#             */
/*   Updated: 2018/05/13 12:40:25 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_engine.h"
#include "ft_mid_point.h"

/*
** +-----------------------+
** | X octant 1|octant 3 X |
** |  XX       |       XX  |
** |    XX     |     XX    |
** |      XX   |   XX      |
** |        XX | XX        |
** |octant 0  X|X  octant 2|
** +-----------------------+
** |octant 2  X|X  octant 0|
** |        XX | XX        |
** |      XX   |   XX      |
** |    XX     |     XX    |
** |  XX       |       XX  |
** | X octant 3|octant 1 X |
** +-----------------------+
*/

void	putpix_octant_0(t_engine *e, t_mid_point *mp)
{
	mp->pix[X] = (*mp->lower)[X];
	mp->pix[Y] = (*mp->lower)[Y];
	mlx_pixel_put(e->mlx_ptr, e->win_ptr, mp->pix[X], mp->pix[Y], e->col);
	while (mp->pix[X] < (*(mp->upper))[X])
	{
		if (mp->decision > 0)
		{
			mp->decision += mp->delta_sides[RIGHT];
			++mp->pix[X];
			++mp->pix[Y];
		}
		else
		{
			mp->decision += mp->delta_sides[LEFT];
			++mp->pix[X];
		}
		mlx_pixel_put(e->mlx_ptr, e->win_ptr, mp->pix[X], mp->pix[Y], e->col);
	}
}

void	putpix_octant_1(t_engine *e, t_mid_point *mp)
{
	mp->pix[X] = (*mp->lower)[X];
	mp->pix[Y] = (*mp->lower)[Y];
	mlx_pixel_put(e->mlx_ptr, e->win_ptr, mp->pix[X], mp->pix[Y], e->col);
	while (mp->pix[Y] < (*(mp->upper))[Y])
	{
		if (mp->decision > 0)
		{
			mp->decision += mp->delta_sides[RIGHT];
			++mp->pix[X];
			++mp->pix[Y];
		}
		else
		{
			mp->decision += mp->delta_sides[LEFT];
			++mp->pix[Y];
		}
		mlx_pixel_put(e->mlx_ptr, e->win_ptr, mp->pix[X], mp->pix[Y], e->col);
	}
}

void	putpix_octant_2(t_engine *e, t_mid_point *mp)
{
	mp->pix[X] = (*mp->lower)[X];
	mp->pix[Y] = (*mp->lower)[Y];
	mlx_pixel_put(e->mlx_ptr, e->win_ptr, mp->pix[X], mp->pix[Y], e->col);
	while (mp->pix[X] > (*(mp->upper))[X])
	{
		if (mp->decision > 0)
		{
			mp->decision += mp->delta_sides[RIGHT];
			--mp->pix[X];
			++mp->pix[Y];
		}
		else
		{
			mp->decision += mp->delta_sides[LEFT];
			--mp->pix[X];
		}
		mlx_pixel_put(e->mlx_ptr, e->win_ptr, mp->pix[X], mp->pix[Y], e->col);
	}
}

void	putpix_octant_3(t_engine *e, t_mid_point *mp)
{
	mp->pix[X] = (*mp->lower)[X];
	mp->pix[Y] = (*mp->lower)[Y];
	mlx_pixel_put(e->mlx_ptr, e->win_ptr, mp->pix[X], mp->pix[Y], e->col);
	while (mp->pix[Y] < (*(mp->upper))[Y])
	{
		if (mp->decision > 0)
		{
			mp->decision += mp->delta_sides[RIGHT];
			--mp->pix[X];
			++mp->pix[Y];
		}
		else
		{
			mp->decision += mp->delta_sides[LEFT];
			++mp->pix[Y];
		}
		mlx_pixel_put(e->mlx_ptr, e->win_ptr, mp->pix[X], mp->pix[Y], e->col);
	}
}
