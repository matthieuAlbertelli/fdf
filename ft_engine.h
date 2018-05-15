/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:51:56 by malberte          #+#    #+#             */
/*   Updated: 2018/05/13 23:39:55 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <mlx.h>

typedef	struct	s_engine
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		col;
	int		size_x;
	int		size_y;
}				t_engine;
typedef enum	e_color
{
	COLOR_WHITE = 16777215
}				t_color;
void			ft_init_engine(t_engine *e, int size_x, int size_y, char *tit);

#endif
