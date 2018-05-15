/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:46:15 by malberte          #+#    #+#             */
/*   Updated: 2018/05/13 12:38:17 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_position.h"
#include "ft_mid_point.h"

static void	init_up_low_pix(t_mid_point *mp, const t_pixel *a, const t_pixel *b)
{
	if ((*a)[Y] > (*b)[Y])
	{
		mp->upper = (t_pixel *)a;
		mp->lower = (t_pixel *)b;
	}
	else
	{
		mp->upper = (t_pixel *)b;
		mp->lower = (t_pixel *)a;
	}
}

static void	init_octant(t_mid_point *mp)
{
	mp->delta_a_b[Y] = (*mp->upper)[Y] - (*mp->lower)[Y];
	if ((*mp->upper)[X] < (*mp->lower)[X])
	{
		mp->delta_a_b[X] = (*mp->lower)[X] - (*mp->upper)[X];
		mp->octant = 2;
	}
	else
		mp->delta_a_b[X] = (*mp->upper)[X] - (*mp->lower)[X];
	if (mp->delta_a_b[X] < mp->delta_a_b[Y])
	{
		mp->decision = 2 * mp->delta_a_b[X] - mp->delta_a_b[Y];
		mp->delta_sides[LEFT] = 2 * mp->delta_a_b[X];
		mp->delta_sides[RIGHT] = 2 * (mp->delta_a_b[X] - mp->delta_a_b[Y]);
		mp->octant |= 1;
	}
	else
	{
		mp->decision = 2 * mp->delta_a_b[Y] - mp->delta_a_b[X];
		mp->delta_sides[LEFT] = 2 * mp->delta_a_b[Y];
		mp->delta_sides[RIGHT] = 2 * (mp->delta_a_b[Y] - mp->delta_a_b[X]);
	}
}

void		ft_draw_line(t_engine *e, const t_pixel *pxa, const t_pixel *pxb)
{
	static t_mid_point	mp;
	static void			(*f_putpixel_octant[4])(t_engine *, t_mid_point *);

	f_putpixel_octant[0] = &putpix_octant_0;
	f_putpixel_octant[1] = &putpix_octant_1;
	f_putpixel_octant[2] = &putpix_octant_2;
	f_putpixel_octant[3] = &putpix_octant_3;
	init_up_low_pix(&mp, pxa, pxb);
	init_octant(&mp);
	(*f_putpixel_octant[mp.octant])(e, &mp);
}
