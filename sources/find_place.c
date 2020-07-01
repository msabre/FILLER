/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:33:41 by msabre            #+#    #+#             */
/*   Updated: 2019/12/20 13:18:35 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	check_z(int map_value, int figure_value, int *intersection,
			int *count)
{
	if (map_value == -1 && figure_value == -1)
		(*intersection)++;
	if (map_value == 0 && figure_value == -1)
		return (-1);
	if (*intersection > 1)
		return (-1);
	if (map_value > 0 && figure_value == -1)
		(*count) += map_value;
	return (1);
}

static int	set_figure(t_map *map, int i, int j, int *intersection)
{
	int		count;
	int		ptr_j;
	int		x;
	int		y;

	y = 0;
	count = 0;
	*intersection = 0;
	ptr_j = j;
	while (i < map->ver_size && y < map->f_ver)
	{
		x = 0;
		j = ptr_j;
		while (x < map->f_width && j < map->hor_size)
		{
			if (check_z(map->map[i][j], map->figure[y][x],
				intersection, &count) == -1)
				return (-1);
			j++;
			x++;
		}
		i++;
		y++;
	}
	return (count);
}

static int	change_values(t_map *map, int i, int j, int count)
{
	map->my_x = j;
	map->my_y = i;
	return (count);
}

void		find_place(t_map *map)
{
	int		i;
	int		j;
	int		count;
	int		current;
	int		intersection;

	current = 1000000;
	i = 0;
	while (i < map->ver_size)
	{
		j = 0;
		while (j < map->hor_size)
		{
			if (((i + map->f_ver - map->ver_shift - 1) < map->ver_size)
			&& ((j + map->f_width - map->right_shift - 1 < map->hor_size)))
			{
				count = set_figure(map, i, j, &intersection);
				if (count > 0 && intersection > 0 && count < current)
					current = change_values(map, i, j, count);
			}
			j++;
		}
		i++;
	}
}
