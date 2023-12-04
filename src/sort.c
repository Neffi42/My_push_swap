/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/04 11:27:04 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_dlist **a)
{
	size_t	size_a;

	size_a = ft_dlstsize(*a);
	while (!is_list_sort(*a))
	{
		if (size_a == 2 || !is_node_sort(*a, (*a)->next))
			sx(a, 'a');
		else
			rrx(a, 'a');
	}
}

static void	partition_stack(t_dlist **a, t_dlist **b, size_t size_a)
{
	int		median;
	int		index;
	t_dir	dir;

	median = find_median(a);
	index = still_el_sup_median(a, median);
	while (size_a > 3 && index != -1)
	{
		dir = fastest_to_dest(*a, index);
		if (dir.up > 0)
			while (dir.mov--)
				rx(a, 'a');
		else if (!dir.up)
			while (dir.mov--)
				rrx(a, 'a');
		px(b, a, 'b');
		size_a--;
		index = still_el_sup_median(a, median);
	}
	while (size_a-- > 3)
		px(b, a, 'b');
}

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
	*da = fastest_to_dest(*a, find_biggest_near_index(*a, lowest));
}

int	sort(t_dlist **a, t_dlist **b)
{
	size_t	size_a;

	size_a = ft_dlstsize(*a);
	if (size_a > 3)
		partition_stack(a, b, size_a);
	sort_three(a);
	if (*b)
		insertion(a, b);
	return (1);
}
