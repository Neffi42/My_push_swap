/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/03 10:51:50 by abasdere         ###   ########.fr       */
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
			sx(a, "sa");
		else
			rrx(a, "rra");
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
		if (!dir.is_up)
			while (dir.move--)
				rx(a, "rx");
		else if (dir.is_up > 0)
			while (dir.move--)
				rrx(a, "rrx");
		px(b, a, "pb");
		size_a--;
		index = still_el_sup_median(a, median);
	}
	while (size_a-- > 3)
		px(b, a, "pb");
}

//sort solo three then place valid index at good place

// static int	fastest_el_to_place(t_dlist **x)
// {
// 	size_t	i;
// 	int		index;
// 	t_dlist	*tmp;

// 	i = 0;
// 	tmp = *x;
// 	while (tmp)
// 	{

// 		tmp = tmp->next
// 		i++;
// 	}
// }

int	sort(t_dlist **a, t_dlist **b)
{
	size_t	size_a;

	size_a = ft_dlstsize(*a);
	if (size_a > 3)
		partition_stack(a, b, size_a);
	sort_three(a);
	return (1);
}
