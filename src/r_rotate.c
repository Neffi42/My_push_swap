/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:14:39 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/03 10:47:54 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_dlist **x, char *s)
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
		*x = last;
	}
	if (s)
		ft_dprintf(1, "%s\n", s);
}

void	rrr(t_dlist **a, t_dlist **b)
{
	rrx(a, NULL);
	rrx(b, NULL);
	ft_dprintf(1, "rrr\n");
}
