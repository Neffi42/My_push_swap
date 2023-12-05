/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:32:12 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/05 18:57:29 by abasdere         ###   ########.fr       */
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

void	calculate_cost_a(t_dlist *a, t_dir *da, int index, int sa)
{
	t_dlist	*tmp;
	t_dir	dlast;

	tmp = ft_dlstlast(a);
	if (tmp->index == index)
		init_dir(da, 0, 0, 0);
	else if (a->index == index)
		init_dir(da, 0, 0, sa);
	else
	{
		init_dir(da, 0, 0, sa);
		init_dir(&dlast, 1, 1, sa);
		while (a->index < index && ++da->mov)
			a = a->next;
		while (tmp->index < index && ++dlast.mov)
			tmp = tmp->prev;
		if (da->mov > dlast.mov)
			*da = dlast;
	}
}

void	calculate_cost_b(t_dlist *b, t_dir *db, int index)
{
	t_dlist	*tmp;
	t_dir	dlast;

	tmp = ft_dlstlast(b);
	if (tmp->index == index)
		init_dir(db, 0, 1, 0);
	else if (b->index == index)
		init_dir(db, 0, 0, 0);
	else
	{
		init_dir(db, 0, 0, 0);
		init_dir(&dlast, 1, 1, 0);
		while (b->index < index && ++db->mov)
			b = b->next;
		while (tmp->index < index && ++dlast.mov)
			tmp = tmp->prev;
		if (db->mov > dlast.mov)
			*db = dlast;
	}
}

static t_dir	cost_ab(t_dlist *a, t_dlist *b, t_dir *da, int index)
{
	int		big_i;
	t_dir	db;

	big_i = find_big_i(a, index);
	if (big_i < index)
		calculate_cost_a(a, da, big_i, 1);
	else
		calculate_cost_a(a, da, big_i, 0);
	calculate_cost_b(b, &db, index);
	return (db);
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
		*db = cost_ab(a, b, da, tmp->index);
		if (cost == -1 || cost > da->mov + db->mov)
		{
			cost = da->mov + db->mov;
			lowest = tmp->index;
		}
		tmp = tmp->next;
	}
	cost = find_big_i(a, lowest);
	ft_dprintf(1, "lowest: %d big_i: %d\n", lowest, cost);
	*db = cost_ab(a, b, da, tmp->index);
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
