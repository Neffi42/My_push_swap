/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/01 16:54:47 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition_stack(t_dlist **a, t_dlist **b)
{
	int		median;
	int		index;
	size_t	size_a;
	t_dir	dir;

	median = find_median(a);
	index = still_el_sup_median(a, median);
	size_a = ft_dlstsize(*a);
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
	partition_stack(a, b);
	return (1);
}
