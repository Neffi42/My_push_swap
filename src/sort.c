/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/06 16:35:14 by abasdere         ###   ########.fr       */
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

static void	partition(t_dlist **a, t_dlist **b, int size_a, int median)
{
	int	i;

	i = 0;
	while (size_a - i > 3 && i < median)
	{
		if ((*a)->index < median)
		{
			px(b, a, 'b');
			i++;
		}
		else
			rx(a, 'a');
	}
	while ((++i) <= size_a - 3)
		px(b, a, 'b');
}

int	sort(t_dlist **a, t_dlist **b)
{
	size_t	size_a;
	int		median;

	size_a = ft_dlstsize(*a);
	if (size_a > 3)
	{
		median = find_median(*a);
		partition(a, b, size_a, median);
	}
	sort_three(a);
	if (*b)
		insertion(a, b);
	return (1);
}
