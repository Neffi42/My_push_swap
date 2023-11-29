/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/29 14:26:18 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	parcourir toute la liste pour voir s'il est sort
	push dans b quand pas sort si on peut pas le swap ou le rotate
*/
void	sort(t_dlist **a, t_dlist **b)
{
	t_dlist	*tmp;
	int		x;
	int		y;
	// t_dlist	*la;
	// t_dlist	*lb;

	while (!is_list_sort(*a))
	{
		// if (is_node_sort(*a, (*a)->next))
		// 	rx(a, "ra");
		// else
		// {
			// la = ft_dlstlast(*a);
			tmp = (*a)->next;
			if (is_node_sort(tmp, *a))
				sx(a, "sa");
			// else if (is_node_sort(la, *a))
			// 	rx(a, "ra");
			else
				px(b, a, "pb");
		// }
	}
	while (*b)
	{
		if (!is_node_sort(*b, *a))
		{
			x = 0;
			y = 0;
			tmp = *b;
			while (*b)
			{
				tmp = tmp->prev;
				x++;
				if (is_node_sort(tmp, *a))
					break ;
			}
			tmp = *b;
			while (*b)
			{
				tmp = tmp->next;
				y++;
				if (is_node_sort(tmp, *a))
					break ;
			}
			if (x <= y)
			{
				while (x--)
					rrx(b, "rrb");
			}
			else
			{
				while (y--)
					rx(b, "rb");
			}
		}
		px(a, b, "pa");
	}
}
