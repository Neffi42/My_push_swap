/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 00:37:43 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/29 09:41:44 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_node_sort(t_dlist *x, t_dlist *y)
{
	if (*(int *)x->content > *(int *)y->content)
		return (0);
	return (1);
}

int	is_list_sort(t_dlist *x)
{
	while (x->next)
	{
		if (!is_node_sort(x, x->next))
			return (0);
		x = x->next;
	}
	return (1);
}
