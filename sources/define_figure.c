/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:35:31 by msabre            #+#    #+#             */
/*   Updated: 2019/12/20 13:16:43 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	cut_hor_and_ver(t_map *map)
{
	int		i;
	int		j;

	i = map->f_ver - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < map->f_width && map->figure[i][j] == 200)
			j++;
		if (j != map->f_width)
			break ;
		(map->ver_shift)++;
		i--;
	}
	j = map->f_width - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < map->f_ver && map->figure[i][j] == 200)
			i++;
		if (i != map->f_ver)
			return ;
		(map->right_shift)++;
		j--;
	}
}

static int	memfigure(char *piece, t_map *map)
{
	int		i;

	i = 0;
	map->f_width = ft_atoi(&(piece[8]));
	map->f_ver = ft_atoi(&(piece[6]));
	free(piece);
	map->ver_shift = 0;
	if (!(map->figure = (int**)malloc(sizeof(int*) * (map->f_ver + 1))))
		return (-1);
	while (i < map->f_ver)
	{
		if (!(map->figure[i++] = (int*)malloc(sizeof(int) * map->f_width)))
		{
			free_doub_lvl_mass((void**)map->figure);
			return (-1);
		}
	}
	map->figure[map->f_ver] = NULL;
	return (1);
}

static int	create_figure(t_map *map)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	while (i < map->f_ver)
	{
		j = 0;
		if (!get_next_line(0, &ptr))
		{
			free_doub_lvl_mass((void**)map->figure);
			free_doub_lvl_mass((void**)map->map);
			return (-1);
		}
		while (ptr[j] != '\0')
		{
			map->figure[i][j] = (ptr[j] == '*') ? -1 : 200;
			j++;
		}
		free(ptr);
		i++;
	}
	return (1);
}

int			define_figure(char *piece, t_map *map)
{
	if (memfigure(piece, map) == -1)
		return (-1);
	if (!create_figure(map))
		return (-1);
	map->ver_shift = 0;
	map->right_shift = 0;
	cut_hor_and_ver(map);
	return (0);
}
