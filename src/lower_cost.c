/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:32:12 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/06 09:32:15 by abasdere         ###   ########.fr       */
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

static void	cost_ab(t_dlist *a, t_dlist *b, t_dir **d, int index)
{
	int		big_i;

	calculate_cost_b(b, d, index);
	big_i = find_big_i(a, index);
	if (big_i < index)
		calculate_cost_a(a, d, big_i, 1);
	else
		calculate_cost_a(a, d, big_i, 0);
}

void	calculate_cost_a(t_dlist *a, t_dir **d, int index, int spec)
{
	t_dlist	*tmp;
	t_dir	dlast;

	tmp = ft_dlstlast(a);
	if (a->index == index)
		init_dir(d[0], 0, 0, spec);
	else if (tmp->index == index)
		init_dir(d[0], 1, 1, spec);
	else
	{
		init_dir(d[0], 0, 0, spec);
		init_dir(&dlast, 1, 1, spec);
		while (a->index != index && ++(d[0])->mov)
			a = a->next;
		while (tmp->index != index && ++dlast.mov)
			tmp = tmp->prev;
		if (d[0]->mov > dlast.mov)
			*(d[0]) = dlast;
	}
}

void	calculate_cost_b(t_dlist *b, t_dir **d, int index)
{
	t_dlist	*tmp;
	t_dir	dlast;

	tmp = ft_dlstlast(b);
	if (b->index == index)
		init_dir(d[1], 0, 0, 0);
	else if (tmp->index == index)
		init_dir(d[1], 1, 1, 0);
	else
	{
		init_dir(d[1], 0, 0, 0);
		init_dir(&dlast, 1, 1, 0);
		while (b->index != index && ++(d[1])->mov)
			b = b->next;
		while (tmp->index != index && ++dlast.mov)
			tmp = tmp->prev;
		if (d[1]->mov > dlast.mov)
			*(d[1]) = dlast;
	}
}

void	lowest_cost(t_dlist *a, t_dlist *b, t_dir *da, t_dir *db)
{
	t_dlist	*tmp;
	t_dir	*d[2];
	int		lowest;
	int		cost;

	tmp = b;
	d[0] = da;
	d[1] = db;
	cost = -1;
	while (tmp)
	{
		cost_ab(a, b, d, tmp->index);
		if (cost == -1 || cost > da->mov + db->mov)
		{
			cost = da->mov + db->mov;
			lowest = tmp->index;
		}
		tmp = tmp->next;
	}
	cost_ab(a, b, d, lowest);
}
