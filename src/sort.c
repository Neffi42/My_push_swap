/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/01 09:54:02 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fastest_to_top(t_dlist *x)
{
	t_dlist	*up;
	t_dlist	*down;
	int		u;
	int		d;

	if (!x)
		return (0);
	up = x->prev;
	down = x->next;
	u = 1;
	d = -1;
	while (up && ++u)
		up = up->prev;
	while (down && --d)
		down = down->next;
	if (u >= d)
		return (d);
	return (u);
}

static int	find_median(t_dlist **a)
{
	t_dlist	*tmp;
	size_t	med_index;

	tmp = *a;
	med_index = ft_dlstsize(tmp) - 1;
	if (!med_index || med_index == 1)
		return (med_index);
	if (med_index % 2)
		med_index = med_index / 2 + 1;
	else
		med_index = med_index / 2;
	return (med_index);
}

int	sort(t_dlist **a, t_dlist **b)
{
	int		pivot;
	t_dlist	*tmp;

	pivot = find_median(a);
	ft_dprintf(1, "median: %d\n", pivot);
	fastest_to_top(*a);
	tmp = *b;
	return (1);
}
