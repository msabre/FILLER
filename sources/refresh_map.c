/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:36:15 by msabre            #+#    #+#             */
/*   Updated: 2019/12/19 21:05:23 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	map_change(t_map *map, int size)
{
	char	*time_buf;
	int		str_cheked;
	int		i;

	str_cheked = 0;
	while (str_cheked < size)
	{
		if (get_next_line(0, &time_buf) == -1)
		{
			free_doub_lvl_mass((void**)map->map);
			return (-1);
		}
		i = 0;
		while (i < map->hor_size)
		{
			if (ft_memchr("oO", time_buf[i + 4], 2))
				map->map[str_cheked][i] = (map->my_num == 1) ? -1 : 0;
			else if (ft_memchr("xX", time_buf[i + 4], 2))
				map->map[str_cheked][i] = (map->my_num == 1) ? 0 : -1;
			i++;
		}
		free(time_buf);
		str_cheked++;
	}
	return (1);
}

int			refresh_map(t_map *map, int size)
{
	char	*time_buf;

	if (map_change(map, size) == -1)
		return (-1);
	if (get_next_line(0, &time_buf) == -1)
	{
		free_doub_lvl_mass((void**)map->map);
		return (-1);
	}
	if (define_figure(time_buf, map) == -1)
		return (-1);
	return (1);
}
