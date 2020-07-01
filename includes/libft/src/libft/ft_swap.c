/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:47:26 by msabre            #+#    #+#             */
/*   Updated: 2019/11/26 17:43:10 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void		ft_swap(int *stack, int l, int r)
{
	int		tmp;

	tmp = stack[l];
	stack[l] = stack[r];
	stack[r] = tmp;
}
