/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:03:14 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/01 14:36:07 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_dlist **x)
{
	size_t	med_index;

	med_index = ft_dlstsize(*x) - 1;
	if (!med_index || med_index == 1)
		return (med_index);
	med_index = med_index / 2;
	return (med_index);
}

int	still_el_sup_median(t_dlist **x, int median)
{
	t_dlist	*tmp;
	t_dlist	*tmp_back;
	int		front;
	int		back;

	tmp = *x;
	front = 0;
	while (tmp && tmp->index <= median && ++front)
		tmp = tmp->next;
	if (!tmp)
		return (-1);
	tmp_back = ft_dlstlast(*x);
	back = -1;
	while (tmp_back && tmp_back->index <= median && --back)
		tmp_back = tmp_back->prev;
	if (front + back > 0)
		return (tmp_back->index);
	return (tmp->index);
}
