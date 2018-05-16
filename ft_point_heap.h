/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_heap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 02:12:21 by malberte          #+#    #+#             */
/*   Updated: 2018/05/16 03:16:02 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_HEAP_H
# define FT_POINT_HEAP_H

# include "ft_position.h"
# define HEAP_SIZE 100

typedef struct	s_point_heap
{
	t_point			*tab;
	unsigned int	i;
	unsigned int	size;
}				t_point_heap;

int				ft_heap_init(t_point_heap *heap, unsigned int size);
int				ft_heap_realloc(t_point_heap *heap, unsigned int addsize);
int				ft_heap_add(t_point_heap *heap, t_point point);
void			ft_heap_del(t_point_heap *heap);

#endif
