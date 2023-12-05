/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:32:12 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/05 12:41:27 by abasdere         ###   ########.fr       */
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

static t_dir	calculate_cost(t_dlist *a, t_dlist *b, t_dlist *tmp, t_dir *db)
{
	int		big_i;
	int		offset;

	big_i = find_big_i(a, tmp->index);
	offset = 0;
	if (big_i < tmp->index)
		offset++;
	*db = fastest_to_dest(tmp, b->index, 0);
	db->mov++;
	// ft_dprintf(1, "tmpi:%d bigi:%d o:%d\n", tmp->index, big_i, offset);
	return (fastest_to_dest(a, big_i, offset));
}

void	lowest_cost(t_dlist **a, t_dlist **b, t_dir *da, t_dir *db)
{
	t_dlist	*tmp;
	int		lowest;
	int		x;

	tmp = *b;
	x = -1;
	while (tmp)
	{
		*da = calculate_cost(*a, *b, tmp, db);
		if (x == -1 || x > da->mov + db->mov)
		{
			x = da->mov + db->mov;
			lowest = tmp->index;
		}
		tmp = tmp->next;
	}
	ft_dprintf(1, "lowest:%d btop:%d\n", go_to_index(*b, lowest, NULL, 0)->index, (*b)->index);
	*da = calculate_cost(*a, *b, go_to_index(*b, lowest, NULL, 0), db);
}
