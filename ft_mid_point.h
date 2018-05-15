/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mid_point.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 12:20:50 by malberte          #+#    #+#             */
/*   Updated: 2018/05/13 12:53:11 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MID_POINT_H
# define FT_MID_POINT_H
# include "ft_position.h"
# include "ft_engine.h"

typedef t_pos_2d	t_pixel;
typedef enum		e_side
{
	LEFT = 0,
	RIGHT = 1
}					t_side;
typedef t_pos_2d	t_delta;
typedef struct		s_mid_point
{
	t_delta		delta_a_b;
	int			decision;
	t_delta		delta_sides;
	t_pixel		pix;
	t_pixel		*lower;
	t_pixel		*upper;
	short int	octant;
}					t_mid_point;

void				ft_draw_line(t_engine *e, const t_pixel *a,
												const t_pixel *b);
void				putpix_octant_0(t_engine *e, t_mid_point *md);
void				putpix_octant_1(t_engine *e, t_mid_point *md);
void				putpix_octant_2(t_engine *e, t_mid_point *md);
void				putpix_octant_3(t_engine *e, t_mid_point *md);

#endif
