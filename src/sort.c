/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/01 16:23:30 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition_stack(t_dlist **a, t_dlist **b)
{
	int		median;
	int		index;
	t_dir	dir;

	median = find_median(a);
	index = still_el_sup_median(a, median);
	while (index != -1)
	{
		ft_dprintf(1, "i: %d\n", index);
		dir = fastest_to_dest(*a, index);
		ft_dprintf(1, "u: %d m: %d\n", dir.is_up, dir.move);
		if (!dir.is_up)
			while (dir.move--)
				rrx(a, "rrx");
		else if (dir.is_up > 0)
			while (dir.move--)
				rx(a, "rx");
		px(b, a, "pb");
		index = still_el_sup_median(a, median);
		print_dlist(*a, 'a');
		print_dlist(*b, 'b');
	}
}

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
	partition_stack(a, b);
	return (1);
}
