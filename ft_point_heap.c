/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_heap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 02:09:22 by malberte          #+#    #+#             */
/*   Updated: 2018/05/16 03:16:17 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "ft_point_heap.h"

int	ft_heap_init(t_point_heap *heap, unsigned int size)
{
	if (heap == NULL)
	{
		return (-1);
	}
	if (heap->tab != NULL)
	{
		ft_memdel(((void **)(&(heap->tab))));
	}
	heap->i = 0;
	heap->tab = (t_point*)ft_memalloc(sizeof(t_point) * size);
	if (heap->tab == NULL)
	{
		heap->size = 0;
		return (-1);
	}
	heap->size = size;
	return (heap->size);
}

int	ft_heap_realloc(t_point_heap *heap, unsigned int addsize)
{
	t_point *new_tab;

	if (heap == NULL)
	{
		return (-1);
	}
	new_tab = (t_point*)ft_memalloc(sizeof(t_point) * (heap->size + addsize));
	if (new_tab == NULL)
	{
		return (-1);
	}
	if (heap->tab != NULL)
	{
		ft_memcpy(new_tab, heap->tab, heap->size * sizeof(t_point));
		ft_memdel(((void**)(&(heap->tab))));
	}
	heap->tab = new_tab;
	heap->size += addsize;
	return (heap->size);
}

int	ft_heap_add(t_point_heap *heap, t_point point)
{
	if (heap->i == heap->size)
		ft_heap_realloc(heap, HEAP_SIZE);
	set_pos3d(heap->tab[heap->i], point[X], point[Y], point[Z]);
	++heap->i;
	return (1);
}

void ft_heap_del(t_point_heap *heap)
{
	if (heap != NULL)
	{
		ft_memdel(((void **)heap->tab));
		heap->i = 0;
		heap->size = 0;
	}
}