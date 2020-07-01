/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:31:49 by msabre            #+#    #+#             */
/*   Updated: 2019/12/20 12:59:17 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/headers/libft.h"
# include <ncurses.h>
# include <locale.h>

# define SHIFT_LEFT 55

typedef struct	s_map
{
	int			**figure;
	int			**map;
	int			vz;
	int			my_num;
	int			hor_size;
	int			ver_size;
	int			my_x;
	int			my_y;
	int			f_ver;
	int			f_width;
	int			ver_shift;
	int			right_shift;
}				t_map;

typedef struct	s_vizual
{
	char		*pl_name_1;
	char		*pl_name_2;
	int			o_score;
	int			x_score;
}				t_vizual;

int				skip_strings(int line_count);
int				update_weight(t_map *map, int find_to, int cost);
void			find_place(t_map *map);
int				refresh_map(t_map *map, int size);
int				create_map(t_map *map);
int				define_figure(char *piece, t_map *map);
void			print_map(int ver_size, int hor_size, t_vizual *viz);
char			*find_str_from_name(int fd, char *name);
void			curs_start();
void			print_order(int hor);
char			*find_str_from_name(int fd, char *name);
void			output_score(int hor, int ver, t_vizual *viz);

#endif
