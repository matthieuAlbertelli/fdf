# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoulomb <acoulomb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 22:08:39 by acoulomb          #+#    #+#              #
#    Updated: 2018/05/13 23:55:45 by acoulomb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

#BINARIES:
CC          = /usr/bin/clang
RM          = /bin/rm
MAKE        = /usr/bin/make

#LIBFT:
LFTPATH     = libft
LIBFT       = $(LFTPATH)/libft.a

#LIBMLX
MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit

#FLAGS:
CC = clang
FLAGS = -Wall -Wextra -Werror
LDFLAGS = -L $(LFTPATH) -lft $(MLX_FLAGS)

#EXECUTABLE:
NAME = fdf

#SRCS:
SRCS =	main.c \
		ft_draw_line.c \
		ft_engine.c \
		ft_putpixel_octant.c \
		ft_read_map.c

#OBJ:
OBJS = $(SRCS:.c=.o)

#HEADERS:
HEADS =	ft_engine.h \
		ft_mid_point.h



all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c $(HEADS)
	@$(CC) -c $(FLAGS) -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(LFTPATH)

clean:
	@$(MAKE) -C $(LFTPATH) clean
	@$(RM) -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LFTPATH) fclean
	@$(RM) -rf $(NAME)

cleanlib:
	$(MAKE) clean -C $(LFTPATH)

re: fclean all

g: re $(OBJS)
	$(CC) $(FLAGS) -g $(SRCS) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

.PHONY = re all clean fclean g