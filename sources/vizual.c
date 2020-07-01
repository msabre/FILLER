/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:54:58 by msabre            #+#    #+#             */
/*   Updated: 2020/06/30 20:18:23 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		print_window(int hor, int ver, int shift)
{
	int			i;

	i = 0;
	printw("%*s", shift, "");
	attron(COLOR_PAIR(5));
	printw("▛");
	while (i++ < (hor))
		printw("▀▀");
	printw("▜");
	printw("\n");
	i = 0;
	while (i++ < (ver))
	{
		printw("%*s", shift, "");
		printw("▌");
		printw("%*s", (hor * 2), "");
		printw("▐\n");
	}
	printw("%*s", shift, "");
	i = 0;
	printw("▙");
	while (i++ < (hor))
		printw("▃▃");
	printw("▟\n");
	attroff(COLOR_PAIR(5));
}

static void		output_player_name(char *player_name)
{
	int			i;
	int			len;

	i = 0;
	i = ft_strlen(player_name);
	while (player_name[i] != '/' && i > 0)
		i--;
	len = ft_strlen(player_name) - i - 2;
	i++;
	printw("%.*s", len, &(player_name[i]));
}

static void		create_header(int hor, int ver, t_vizual *viz)
{
	int			size;

	if (hor < 35)
		size = -15;
	else
		size = 5;
	print_order(hor);
	printw("\n\n");
	print_window(35, 5, SHIFT_LEFT + size);
	move(14, SHIFT_LEFT + size + 12);
	output_player_name(viz->pl_name_1);
	printw("%*s", 23, "");
	output_player_name(viz->pl_name_2);
	free(viz->pl_name_1);
	free(viz->pl_name_2);
	move(20, 0);
	printw("\n\n");
	print_window(hor + hor / 2, ver, SHIFT_LEFT);
}

static void		ft_fizual(void)
{
	t_vizual	viz;
	char		*sizes;
	int			hor;
	int			ver;

	viz.pl_name_1 = find_str_from_name(0, "$$$ exec p1");
	viz.pl_name_2 = find_str_from_name(0, "$$$ exec p2");
	sizes = find_str_from_name(0, "Plateau");
	ver = ft_atoi(&(sizes[8]));
	hor = ft_atoi(&(sizes[8 + cn_power(ver)]));
	free(sizes);
	curs_start();
	create_header(hor, ver, &viz);
	refresh();
	while (1)
	{
		if (!find_str_from_name(0, "    0123"))
			break ;
		output_score(hor, ver, &viz);
		print_map(ver, hor, &viz);
		refresh();
		system("sleep 0.08");
	}
	system("sleep 2");
	endwin();
}

int				main(void)
{
	ft_fizual();
	return (0);
}
