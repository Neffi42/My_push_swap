/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:32:12 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/04 22:46:26 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_biggest_near_index(t_dlist *x, int index)
{
	while (x && x->index < index)
		x = x->next;
	if (!x)
		return (-1);
	return (x->index);
}

void	lowest_cost(t_dlist **a, t_dlist **b, t_dir *da, t_dir *db)
{
	t_dlist	*tmp;
	int		lowest;
	int		sum_dir;

	tmp = *b;
	sum_dir = -1;
	while (tmp)
	{
		*db = fastest_to_dest(tmp, (*b)->index);
		db->mov++;
		*da = fastest_to_dest(*a, find_biggest_near_index(*a, tmp->index));
		if (sum_dir == -1 || sum_dir > da->mov + db->mov)
		{
			sum_dir = da->mov + db->mov;
			lowest = tmp->index;
		}
		tmp = tmp->next;
	}
	tmp = go_to_index(*b, lowest, NULL, 0);
	*db = fastest_to_dest(tmp, (*b)->index);
	db->mov++;
	ft_dprintf(1, "l: %d bi: %d\n", lowest, find_biggest_near_index(*a, lowest));
	*da = fastest_to_dest(*a, find_biggest_near_index(*a, lowest));
}
