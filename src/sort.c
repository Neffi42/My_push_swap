/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/01 11:35:47 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fastest_to_top(t_dlist **x, int index)
{
	t_dlist	*tmp;
	int		u;
	int		d;

	tmp = *x;
	u = 0;
	while (tmp && tmp->index != index && ++u)
		tmp = tmp->next;
	if (!tmp || !u)
		return (0);
	d = 0;
	while (tmp && --d)
		tmp = tmp->next;
	if (!d || u + d >= 0)
		return (d);
	return (u);
}

static int	find_median(t_dlist **x)
{
	t_dlist	*tmp;
	size_t	med_index;

	tmp = *x;
	med_index = ft_dlstsize(tmp) - 1;
	if (!med_index || med_index == 1)
		return (med_index);
	if (med_index % 2)
		med_index = med_index / 2 + 1;
	else
		med_index = med_index / 2;
	return (med_index);
}

// check if tmp and tmp_back are not null
static int	still_el_sup_median(t_dlist **x, int median)
{
	t_dlist	*tmp;
	t_dlist	*tmp_back;
	int		front;
	int		back;

	tmp = *x;
	front = 0;
	while (tmp && tmp->index <= median && ++front)
		tmp = tmp->next;
	if (tmp && !front)
		return (tmp->index);
	tmp_back = ft_dlstlast(*x);
	back = 0;
	while (tmp_back && tmp_back->index <= median && --back)
		tmp_back = tmp_back->prev;
	if (!back || front + back >= 0)
		return (tmp_back->index);
	return (tmp->index);
}

static void	partition_stack(t_dlist **a, t_dlist **b)
{
	int	median;
	int	index;
	int	dir;

	median = find_median(a);
	index = still_el_sup_median(a, median);
	ft_dprintf(1, "index: %d\n", index);
	while (index != -1)
	{
		dir = fastest_to_top(a, index);
		if (dir < 0)
			while (dir++)
				rrx(a, "rrx");
		else if (dir > 0)
			while (dir--)
				rx(a, "rx");
		px(b, a, "pb");
		index = still_el_sup_median(a, median);
		ft_dprintf(1, "index: %d\n", index);
	}
}

int	sort(t_dlist **a, t_dlist **b)
{
	partition_stack(a, b);
	return (1);
}
