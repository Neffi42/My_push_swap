/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:32:12 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/05 16:09:15 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_big_i(t_dlist *x, int index)
{
	t_dlist	*tmp;
	int		big_i;

	tmp = x;
	big_i = -1;
	while (x)
	{
		if (index < x->index && (big_i == -1 || big_i > x->index))
			big_i = x->index;
		x = x->next;
	}
	if (big_i == -1)
	{
		while (tmp)
		{
			if (big_i < tmp->index)
				big_i = tmp->index;
			tmp = tmp->next;
		}
	}
	return (big_i);
}

void	calculate_cost(t_dlist *x, t_dir *d, int index, int is_b)
{
	t_dlist	*tmp;
	t_dir	dlast;

	tmp = ft_dlstlast(x);
	if (tmp->index == index)
		init_dir(d, 0, is_b, 0);
	else if (x->index == index)
		init_dir(d, 0, 0, 1 - is_b);
	else
	{
		init_dir(d, 0, 0, 1 - is_b);
		init_dir(&dlast, 1, 1, 1 - is_b);
		while (x->index < index && ++d->mov)
			x = x->next;
		while (tmp->index < index && ++dlast.mov)
			tmp = tmp->prev;
		if (d->mov > dlast.mov)
			*d = dlast;
	}
}

void	lowest_cost(t_dlist *a, t_dlist *b, t_dir *da, t_dir *db)
{
	t_dlist	*tmp;
	int		lowest;
	int		cost;

	tmp = b;
	cost = -1;
	while (tmp)
	{
		calculate_cost(a, da, find_big_i(a, tmp->index), 0);
		calculate_cost(b, db, tmp->index, 1);
		if (cost == -1 || cost > da->mov + db->mov)
		{
			cost = da->mov + db->mov;
			lowest = tmp->index;
		}
		tmp = tmp->next;
	}
	cost = find_big_i(a, lowest);
	ft_dprintf(1, "lowest: %d big_i: %d\n", lowest, cost);
	calculate_cost(a, da, cost, 0);
	if (cost < lowest)
		calculate_cost(b, db, lowest, 0);
	else
		calculate_cost(b, db, lowest, 1);
}

int	lowest_cost_up_med(t_dlist *x, t_dir *d, int median)
{
	t_dlist	*tmp;
	t_dir	dlast;

	tmp = ft_dlstlast(x);
	init_dir(d, 0, 0, 0);
	init_dir(&dlast, 1, 1, 0);
	while (x && x->index < median && ++d->mov)
		x = x->next;
	if (!x)
		return (0);
	while (tmp->index < median && ++dlast.mov)
		tmp = tmp->prev;
	if (d->mov > dlast.mov)
		*d = dlast;
	return (1);
}
