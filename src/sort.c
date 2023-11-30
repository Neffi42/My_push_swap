/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/30 14:25:56 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_dlist **a, t_dlist **b, int median)
{
	int		is_smallest;
	int		nbr_rx;
	int		nbr_rrx;
	t_dlist	*tmp;

	while (*a)
	{
		is_smallest = 1;
		nbr_rx = 0;
		nbr_rrx = 0;
		if (is_node_sort((*a)->next, *a))
			sx(a, "sa");
		if (*b)
		{
			if (!is_node_sort(*b, *a))
			{
				tmp = (*b)->next;
				while (tmp)
				{
					nbr_rx++;
					if (is_node_sort(tmp, *a))
						is_smallest = 0;
					tmp = (*b)->next;
				}
				tmp = (*b)->prev;
				while (tmp)
				{
					nbr_rrx++;
					if (is_node_sort(tmp, *a) && is_smallest)
						is_smallest = 0;
					tmp = (*b)->prev;
				}
				if (!is_smallest)
				{
					if (nbr_rx <= nbr_rrx)
						while (nbr_rx--)
							rx(b, "rb");
					else
						while (nbr_rrx--)
							rrx(b, "rrx");
				}
			}
			if (is_node_sort(*b, *a) || is_smallest)
				px(b, a, "pb");
		}
		else
			px(b, a, "pb");
	}
	while (*b)
		px(a, b, "pa");
}
