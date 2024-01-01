/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:03:14 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/05 15:19:56 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_dlist *x)
{
	size_t	med_index;

	med_index = ft_dlstsize(x) - 1;
	if (!med_index || med_index == 1)
		return (med_index);
	med_index = med_index / 2;
	return (med_index);
}
