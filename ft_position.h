/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:53:29 by malberte          #+#    #+#             */
/*   Updated: 2018/05/13 22:55:44 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POSITION_H
# define FT_POSITION_H

typedef enum		e_coords_2d
{
	X = 0,
	Y = 1
}					t_coords_2d;
typedef int			t_pos_2d[2];
typedef enum		e_pos_2d
{
	Z = 0,
	COLOR = 1
}					t_zcolor_var;
typedef t_pos_2d	t_zcolor;

#endif
