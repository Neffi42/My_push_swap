/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:14:37 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/30 15:35:37 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_dlist **x, char *s)
{
	t_dlist	*tmp;
	t_dlist	*last;

	if (*x && (*x)->next)
	{
		tmp = (*x)->next;
		tmp->prev = NULL;
		last = ft_dlstlast(*x);
		(*x)->next = NULL;
		(*x)->prev = last;
		last->next = *x;
		*x = tmp;
	}
	if (s)
		ft_dprintf(1, "%s\n", s);
}

void	rr(t_dlist **a, t_dlist **b)
{
	rx(a, NULL);
	rx(b, NULL);
	ft_dprintf(1, "rr\n");
}
