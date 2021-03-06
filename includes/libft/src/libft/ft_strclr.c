/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:18:05 by msabre            #+#    #+#             */
/*   Updated: 2019/11/01 20:50:04 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_strclr(char *s)
{
	if (s)
	{
		while (*s != 0)
		{
			*s = '\0';
			s++;
		}
	}
}
