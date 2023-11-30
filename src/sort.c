/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/30 16:35:47 by abasdere         ###   ########.fr       */
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

static int	partition_list(t_dlist **a, t_dlist **b, int low, int high)
{
	int	pivot;

	//update find median to add start and end point
	pivot = find_median();
}

int	sort(t_dlist **a, t_dlist **b, int low, int high)
{
	int		pivot;
	t_dlist	*tmp;

	if (low < high)
	{
		pivot = partition_list(a, b, low, high);
		if (pivot == -1)
			return (0);
		tmp = *a;
		while (peek(tmp) != pivot)
			tmp = tmp->next;
		tmp = tmp->next;
		if (!sort(a, b, low, pivot) || !sort(a, b, peek(tmp), high))
			return (0);
	}
	return (1);
}
