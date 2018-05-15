/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:53:29 by malberte          #+#    #+#             */
/*   Updated: 2018/05/15 20:13:46 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POSITION_H
# define FT_POSITION_H

typedef enum		e_coords_3d
{
	X = 0,
	Y = 1,
	Z = 2
}					t_coords_3d;
typedef int			t_pos_2d[2];
typedef int			t_pos_3d[3];
typedef t_pos_3d	t_point;
typedef enum		e_zcolor_var
{
	ALT = 0,
	COLOR = 1
}					t_zcolor_var;
typedef t_pos_2d	t_zcolor;
typedef t_pos_2d	t_pixel;

void set_pos3d(t_pos_3d pos, int x, int y, int z);

#endif
