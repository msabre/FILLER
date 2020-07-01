/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_vizual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:56:14 by msabre            #+#    #+#             */
/*   Updated: 2019/12/20 13:16:38 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char		*find_str_from_name(int fd, char *name)
{
	char	*ptr;

	ptr = NULL;
	while (get_next_line(fd, &ptr) == 1)
	{
		if (!ptr)
			return (NULL);
		if (ft_strncmp(ptr, name, 5) == 0)
			return (ptr);
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

void		print_order(int hor)
{
	int sp;

	if (hor >= 35)
		sp = 83;
	else if (hor < 35)
		sp = SHIFT_LEFT + 7;
	else
		sp = 40;
	printw("\n\n\n\n\n\n");
	printw("%*s", sp, "");
	attron(COLOR_PAIR(3));
	printw("███ ███ █   █   ███ ████\n");
	printw("%*s", sp, "");
	printw("█    █  █   █   █   █  █\n");
	printw("%*s", sp, "");
	printw("███  █  █   █   ███ ████\n");
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(4));
	printw("%*s", sp, "");
	printw("█    █  █   █   █   █ █\n");
	printw("%*s", sp, "");
	printw("█   ███ ███ ███ ███ █ █\n");
	printw("%*s", sp, "");
	attroff(COLOR_PAIR(4));
}

void		curs_start(void)
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	if (!initscr())
	{
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(1);
	}
	start_color();
	curs_set(0);
	init_pair(1, COLOR_WHITE, COLOR_GREEN);
	init_pair(2, COLOR_WHITE, COLOR_YELLOW);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_RED);
}
