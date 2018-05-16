/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:51:56 by malberte          #+#    #+#             */
/*   Updated: 2018/05/16 03:03:43 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <mlx.h>
# include "ft_position.h"
# include "ft_point_heap.h"

# define MAP3D_SIZE 100

typedef	struct	s_engine
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				col;
	int				size_x;
	int				size_y;
	int				opening_angle;
	int				camera_dist;
	t_pixel			cam_focus;
	t_point_heap	*map3d;
	unsigned int	map3d_i;
	unsigned int	map3d_size;
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
int				ft_read_map(t_engine *e, char *filename);

#endif
