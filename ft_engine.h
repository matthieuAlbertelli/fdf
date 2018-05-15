/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:51:56 by malberte          #+#    #+#             */
/*   Updated: 2018/05/15 21:05:09 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <mlx.h>
# include "ft_position.h"

typedef	struct	s_engine
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			col;
	int			size_x;
	int			size_y;
	int			opening_angle;
	int			camera_dist;
	t_pixel		cam_focus;
}				t_engine;
typedef enum	e_color
{
	COLOR_WHITE = 16777215
}				t_color;

void			ft_init_engine(t_engine *e, int size_x, int size_y, char *tit);
void			ft_init_camera(t_engine *engine, int opening_angle);
void			ft_perspective_projection(	t_pixel px,
											const t_engine *e,
											const t_pos_3d p);
#endif
