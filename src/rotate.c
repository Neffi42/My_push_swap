/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:14:37 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/28 14:52:52 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_list **x, char *s)
{
	t_list	*tmp;
	t_list	*last;

	if (*x && (*x)->next)
	{
		tmp = (*x)->next;
		last = ft_lstlast(*x);
		(*x)->next = NULL;
		last->next = *x;
		*x = tmp;
	}
	ft_dprintf(1, "%s\n", s);
}

void	rr(t_list **a, t_list **b)
{
	rx(a, "ra");
	rx(b, "rb");
}
