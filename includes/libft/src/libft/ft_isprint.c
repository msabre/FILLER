/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:39:37 by msabre            #+#    #+#             */
/*   Updated: 2019/10/30 22:50:22 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
