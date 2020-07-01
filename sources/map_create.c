/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:50:01 by msabre            #+#    #+#             */
/*   Updated: 2019/12/20 13:11:30 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	ft_bzero_for_filler(int *s, int n)
{
	int i;

	i = 0;
	while (i < n)
		s[i++] = 200;
}

static int	ft_mem_map(t_map *map)
{
	char	*ptr;

	if (get_next_line(0, &ptr) == -1)
		return (-1);
	map->my_num = ptr[10] - 48;
	free(ptr);
	if (get_next_line(0, &ptr) == -1)
		return (-1);
	map->ver_size = (int)ft_atoi(&(ptr[8]));
	map->hor_size = (int)ft_atoi(&(ptr[8 + (cn_power(map->ver_size) + 1)]));
	if (!(map->map = (int**)malloc(sizeof(int*) * (map->ver_size + 1))))
		return (-1);
	map->map[map->ver_size] = NULL;
	free(ptr);
	return (0);
}

int			create_map(t_map *map)
{
	int		size;

	size = 0;
	ft_mem_map(map);
	while (size < map->ver_size)
	{
		if (!(map->map[size] = (int*)malloc(sizeof(int) * map->hor_size)))
		{
			free_doub_lvl_mass((void**)map->map);
			return (-1);
		}
		ft_bzero_for_filler(map->map[size++], map->hor_size);
	}
	if (!skip_strings(1))
		return (-1);
	refresh_map(map, map->ver_size);
	return (0);
}
