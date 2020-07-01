# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msabre <msabre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/19 20:55:18 by msabre            #+#    #+#              #
#    Updated: 2019/12/20 13:20:18 by msabre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = msabre.filler

VIZ = vizual

CFLAGS  = -g -Wall -Wextra -Werror

SRC_FILLER = define_figure.c filler.c find_place.c map_create.c refresh_map.c skip_strings.c  update_weight.c \

SRC_VIZUAL = vizual.c output_score.c other_vizual.c print_map.c \

OBJSFD  = temporary

SRCS    = sources

OBJS1    = $(addprefix $(OBJSFD)/,$(SRC_FILLER:.c=.o))

OBJS2    = $(addprefix $(OBJSFD)/,$(SRC_VIZUAL:.c=.o))

HDR     = -I ./includes

LIBFT_HDR   = -I ./includes/libft/headers

LIB_BINARY  = -L ./includes/libft -lft

LIBFT       = ./includes/libft/libft.a

all: $(LIBFT) $(NAME) $(VIZ)

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: $(SRCS)/%.c | $(OBJSFD)
	gcc $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(LIBFT):
	make -C ./includes/libft

$(NAME): $(OBJS1)
	gcc $(OBJS1) $(LIB_BINARY) -o $@

$(VIZ): $(OBJS2)
	gcc $(OBJS2) $(LIB_BINARY) -o $@ -lcurses

clean:
	/bin/rm -f $(OBJS)
	rm -rf $(OBJSFD)
	make -C ./includes/libft clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(VIZ)
	make -C ./includes/libft fclean

re: fclean all
