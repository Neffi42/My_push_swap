/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:14:39 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/07 10:21:34 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_dlist **x, char c)
{
	t_dlist	*prev;
	t_dlist	*last;

	if (*x && (*x)->next)
	{
		last = ft_dlstlast(*x);
		prev = last->prev;
		last->prev = NULL;
		last->next = *x;
		prev->next = NULL;
		(*x)->prev = last;
		*x = last;
	}
	if (c)
		ft_dprintf(1, "rr%c\n", c);
}

void	rrr(t_dlist **a, t_dlist **b, int print)
{
	rrx(a, '\0');
	rrx(b, '\0');
	if (print)
		ft_dprintf(1, "rrr\n");
}
