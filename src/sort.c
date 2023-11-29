/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/29 12:43:01 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_dlist **a, t_dlist **b)
{
	t_dlist	*tmp;
	t_dlist	*la;
	// t_dlist	*lb;

	la = ft_dlstlast(*a);
	tmp = *a;
	while (tmp != la)
	{
		if (!is_node_sort(tmp, tmp->next))
		{
			sx(a, "sa");
			tmp = *a;
		}
		if (!is_node_sort(tmp, la))
			rx(a, "ra");
		else
			px(b, a, "pb");
		tmp = *a;
	}
}
