/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:14:37 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/07 10:21:35 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_dlist **x, char c)
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
	if (c)
		ft_dprintf(1, "r%c\n", c);
}

void	rr(t_dlist **a, t_dlist **b, int print)
{
	rx(a, '\0');
	rx(b, '\0');
	if (print)
		ft_dprintf(1, "rr\n");
}
