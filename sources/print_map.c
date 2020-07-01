/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:52:27 by msabre            #+#    #+#             */
/*   Updated: 2019/12/20 13:14:54 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		printw_color(char *str, int pair_num)
{
	attron(COLOR_PAIR(pair_num));
	printw("%s", str);
	attroff(COLOR_PAIR(pair_num));
}

static void		define_asc(char *line, t_vizual *viz)
{
	if (*line == '.')
		printw("🔲 ");
	else if (*line == 'O')
	{
		printw("🍍 ");
		(viz->o_score)++;
	}
	else if (*line == 'o')
	{
		printw_color("🍍 ", 1);
		(viz->o_score)++;
	}
	else if (*line == 'X')
	{
		printw("🍌 ");
		(viz->x_score)++;
	}
	else if (*line == 'x')
	{
		printw_color("🍌 ", 2);
		(viz->x_score)++;
	}
}

void			print_map(int ver_size, int hor_size, t_vizual *viz)
{
	char		*line;
	int			i;
	int			j;

	i = 0;
	viz->x_score = 0;
	viz->o_score = 0;
	move(23, SHIFT_LEFT + 1);
	while (i < ver_size)
	{
		j = 0;
		get_next_line(0, &line);
		while (j < hor_size)
		{
			define_asc(&(line[j + 4]), viz);
			j++;
		}
		free(line);
		i++;
		move(23 + i, SHIFT_LEFT + 1);
	}
}
