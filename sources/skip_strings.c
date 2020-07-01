/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:51:27 by msabre            #+#    #+#             */
/*   Updated: 2019/12/19 23:04:37 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			skip_strings(int line_count)
{
	char	*ptr;
	int		size;

	size = 0;
	ptr = NULL;
	while (size < line_count)
	{
		if (get_next_line(0, &ptr) == -1)
			return (-1);
		free(ptr);
		size++;
	}
	return (1);
}
