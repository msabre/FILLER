/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_weight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:37:18 by msabre            #+#    #+#             */
/*   Updated: 2019/12/19 21:05:37 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	weight_diagonals(t_map *map, int i, int j, int cost)
{
	int		count;

	count = 0;
	if (i - 1 >= 0 && j + 1 < map->hor_size && map->map[i - 1][j + 1] == 200)
	{
		map->map[i - 1][j + 1] = cost;
		count++;
	}
	if (i - 1 >= 0 && j - 1 >= 0 && map->map[i - 1][j - 1] == 200)
	{
		map->map[i - 1][j - 1] = cost;
		count++;
	}
	if (i + 1 < map->ver_size && j + 1 < map->hor_size
		&& map->map[i + 1][j + 1] == 200)
	{
		map->map[i + 1][j + 1] = cost;
		count++;
	}
	if (i + 1 < map->ver_size && j - 1 >= 0 && map->map[i + 1][j - 1] == 200)
	{
		map->map[i + 1][j - 1] = cost;
		count++;
	}
	return (count);
}

static int	check_weight(t_map *map, int cost, int i, int j)
{
	int		count;

	count = 0;
	if (j + 1 < map->hor_size && map->map[i][j + 1] == 200)
	{
		map->map[i][j + 1] = cost;
		count++;
	}
	if (j - 1 >= 0 && map->map[i][j - 1] == 200)
	{
		map->map[i][j - 1] = cost;
		count++;
	}
	if (i + 1 < map->ver_size && map->map[i + 1][j] == 200)
	{
		map->map[i + 1][j] = cost;
		count++;
	}
	if (i - 1 >= 0 && map->map[i - 1][j] == 200)
	{
		map->map[i - 1][j] = cost;
		count++;
	}
	count += weight_diagonals(map, i, j, cost);
	return (count);
}

int			update_weight(t_map *map, int find_to, int cost)
{
	int		count;
	int		i;
	int		j;

	count = 1;
	while (count > 0)
	{
		i = 0;
		count = 0;
		while (i < map->ver_size)
		{
			j = 0;
			while (j < map->hor_size)
			{
				if (map->map[i][j] == find_to)
					count += check_weight(map, cost, i, j);
				j++;
			}
			i++;
		}
		find_to++;
		cost++;
	}
	return (find_to);
}
