/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:29:07 by msabre            #+#    #+#             */
/*   Updated: 2019/12/20 13:16:49 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	free_all(int return_val, t_map *map)
{
	free_doub_lvl_mass((void**)map->map);
	free_doub_lvl_mass((void**)map->figure);
	return (return_val);
}

static void	clear_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (j < map->hor_size)
		{
			map->map[i][j] = 200;
			j++;
		}
		i++;
	}
	free_doub_lvl_mass((void**)map->figure);
}

static int	filler(t_map *map)
{
	char	*x;
	char	*y;

	while (1)
	{
		update_weight(map, 0, 1);
		find_place(map);
		x = ft_itoa(map->my_x);
		y = ft_itoa(map->my_y);
		if (!(x && y))
			return (free_all(-1, map));
		ft_printf("%s %s\n", y, x);
		free(x);
		free(y);
		if (map->my_x < 0 || map->my_y < 0)
			break ;
		if (!skip_strings(2))
			return (free_all(-1, map));
		clear_map(map);
		if (refresh_map(map, map->ver_size) == -1)
			return (-1);
		map->my_x = -1;
		map->my_x = -1;
	}
	return (free_all(0, map));
}

int			main(void)
{
	t_map	map;

	if (create_map(&map) == -1)
		return (-1);
	filler(&map);
	return (0);
}
