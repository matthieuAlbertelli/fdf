/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 11:00:53 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/16 04:25:22 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_position.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_engine.h"
#include "ft_point_heap.h"

static void	reallocif_map3d(t_engine *e)
{
	t_point_heap *new_map;

	new_map = NULL;
	if (e->map3d == NULL)
	{
		e->map3d = (t_point_heap *) ft_memalloc(sizeof(t_point_heap) * MAP3D_SIZE);
	}
	else if (e->map3d_i == e->map3d_size)
	{
		new_map = (t_point_heap *) ft_memalloc(sizeof(t_point_heap) * (e->map3d_size + MAP3D_SIZE));
		if (new_map == NULL)
		{
			exit(0);
		}
		ft_memcpy(new_map, e->map3d, e->map3d_size * sizeof(t_point_heap));
		ft_memdel(((void **)(&(e->map3d))));
		e->map3d = new_map;
		e->map3d_size += MAP3D_SIZE;
	}
}

int			ft_read_map(t_engine *e, char *filename)
{
	char	*line;
	char	*next;
	int		gnl_status;
	int		fd;
	t_point	point;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	point[Z] = 0;
	line = NULL;
	while ((gnl_status = ft_get_next_line(fd, &line)))
	{
		if (gnl_status == -1)
		{
			ft_strdel(&line);
			return (-1);
		}
		next = line;
		if (next != NULL)
		{
			reallocif_map3d(e);
			ft_heap_init(&(e->map3d[e->map3d_i]), HEAP_SIZE);
			point[X] = 0;
			while (*next)
			{
				point[Y] = ft_atoin(&next, next);
				ft_heap_add(&(e->map3d[point[Z]]), point);
				++point[X];
			}
		}
		ft_strdel(&line);
		++e->map3d_i;
		++point[Z];
	}
	close(fd);
	return (1);
}

void		ft_print_map(t_engine *e)
{
	unsigned int y;
	unsigned int x;
	int dim;

	y = 0;
	while (y < e->map3d_i)
	{
		x = 0;
		while (x < ((e->map3d)[y]).i)
		{
			dim = X;
			ft_putstr("(");
			while (dim < 3)
			{
				ft_putnbr(e->map3d[y].tab[x][dim]);
				if (dim == 2)
					ft_putchar(')');
				else
					ft_putchar(',');
				++dim;
			}
			++x;
		}
		ft_putchar('\n');
		++y;
	}
}