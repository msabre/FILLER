/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:54:28 by msabre            #+#    #+#             */
/*   Updated: 2019/12/20 13:01:02 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	print_score(int score, int square, int position, char *icon)
{
	float	procent;
	int		proc_ptr;
	int		i;

	i = 0;
	move(16, position);
	procent = ((float)score / (float)square) * 100.0;
	proc_ptr = (int)procent;
	while (i < 20)
	{
		if (proc_ptr / 5 > 0)
		{
			printw("#");
			proc_ptr = proc_ptr - 5;
		}
		else
			printw(".");
		i++;
	}
	move(18, position);
	printw("%s ", icon);
	printw("%d", (int)procent);
	printw("%% ");
}

void		output_score(int hor, int ver, t_vizual *viz)
{
	int		size;

	if (hor < 35)
		size = -7;
	else
		size = 15;
	print_score(viz->o_score, (hor * ver), SHIFT_LEFT + size, "🍍");
	attron(COLOR_PAIR(6));
	printw("%d", viz->o_score);
	attroff(COLOR_PAIR(6));
	print_score(viz->x_score, (hor * ver), SHIFT_LEFT + size + 30, "🍌");
	attron(COLOR_PAIR(6));
	printw("%d", viz->x_score);
	attroff(COLOR_PAIR(6));
}
