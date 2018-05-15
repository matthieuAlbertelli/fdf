/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 11:00:53 by acoulomb          #+#    #+#             */
/*   Updated: 2018/05/14 00:08:04 by acoulomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_position.h"
#include "lib/libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include "ft_engine.h"

int ft_find_color(char *color)
{
	int i;
	int rgb;

	i = 2;
	if (color[0] != '0' && color [1] != 'x')
		return(-1);
	return (rgb = ft_atoi_base(color + i, 16));
}

t_zcolor ***ft_fill_map(t_zcolor ***map, char *split_line, int nb_line, t_engine *engine)
{
	int i;
	int j;
	int nb_col;
	char **split_col;

	i = 0;
	j = 0;
	nb_col = 0;
	split_col = ft_strsplit(split_line, ' ');
	while (split_col[nb_col])
			nb_col++;
	(*engine).size_y = nb_col;
	if (!((*map)[nb_line] = (t_zcolor*)ft_memalloc(sizeof(t_zcolor) * nb_col)))
		return (NULL);
	nb_col = 0;
	while (split_col[nb_col])
	{
		(*map)[nb_line][nb_col][Z] = ft_atoi(split_col[nb_col]);
	//	while (split[i][j] && (split[i][j] != ','))
	//		j++;
	//	if (split[i][j] && split[i][j + 1] && (split[i][j] == ','))
	//		(*map)[nb_line][i][COLOR] = ft_find_color(&split[i][j + 1]);
		nb_col++;
	//	j = 0;
	}
	return (map);
}

t_zcolor ***ft_init_map(int fd, t_zcolor ***map, t_engine *engine)
{
	char		*line;
	char		*str;
	char 		*file;
	char		**split_line;
	char		**split_col;
	int			i;
	
	int			nb_col;
	static int	nb_line;

	nb_line = 0;
	nb_col = 0;
	line = NULL;
	i = 0;
	file = ft_strnew(0);
	while (get_next_line(fd, &line))
	{
		str = ft_strjoin(file, line);
		ft_strdel(&file);
		file = ft_strjoin(str, "\n");
		ft_strdel(&str);
		ft_strdel(&line);
		nb_line++;
	}
	(*engine).size_x = nb_line;
	if (!(map = (t_zcolor***)ft_memalloc(sizeof(t_zcolor**) * 1)))
		return (NULL);
	if (!(*map = (t_zcolor**)ft_memalloc(sizeof(t_zcolor*) * nb_line + 1)))
		return (NULL);
	split_line = ft_strsplit(file, '\n');
	nb_line = 0;
	while (split_line[nb_line])
	{
		ft_fill_map(map, split_line[nb_line], nb_line, engine);
		nb_line++;
	}

	int j;
	j = 0;
	i = 0;
	while (/*(*map)[i][j][Z] &&*/ i < nb_line)
	{
		while ((*map)[i][j] && j<(*engine).size_x)
		{
			printf("%d ", (*map)[i][j][Z]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	return (map);
}


int main(int argc, char **argv)
{
	int fd;
	t_zcolor **map;
	t_engine engine;

	fd = open(argv[1], O_RDONLY);
	ft_init_map(fd, &map, &engine);
	ft_init_engine(&engine, 100, 100, "potatoe");

	return (0);
}