/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:02:26 by malberte          #+#    #+#             */
/*   Updated: 2018/05/13 19:04:04 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_position.h"

int ft_find_color(char *color);
t_zcolor ***ft_fill_map(t_zcolor ***map, char **split, int nb_line);
t_zcolor ***ft_init_map(int fd, t_zcolor ***map);
