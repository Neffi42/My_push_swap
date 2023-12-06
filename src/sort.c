/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/06 13:45:54 by abasdere         ###   ########.fr       */
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

static void	partition(t_dlist **a, t_dlist **b, size_t *size_a, int median)
{
	t_dir	d;
	int		last;

	last = -1;
	while (*size_a > 3 && lowest_cost_up_med(*a, &d, median, last))
	{
		shift_list(a, &d, 0, 'a');
		last = (*a)->index;
		px(b, a, 'b');
		(*size_a)--;
	}
}

int	sort(t_dlist **a, t_dlist **b)
{
	size_t	size_a;
	int		median;

	size_a = ft_dlstsize(*a);
	if (size_a > 3)
	{
		median = find_median(*a);
		partition(a, b, &size_a, median);
		while (size_a-- > 3)
			px(b, a, 'b');
	}
	sort_three(a);
	if (*b)
		insertion(a, b);
	return (1);
}
