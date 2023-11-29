/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:14:39 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/29 09:35:37 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_dlist **x, char *s)
{
	t_dlist	*before_last;
	t_dlist	*last;

	if (*x && (*x)->next)
	{
		before_last = (*x);
		last = (*x)->next;
		while (last->next)
		{
			before_last = before_last->next;
			last = before_last->next;
		}
		before_last->next = NULL;
		last->next = *x;
		*x = last;
	}
	ft_dprintf(1, "%s\n", s);
}

void	rrr(t_dlist **a, t_dlist **b)
{
	rrx(a, "rra");
	rrx(b, "rrb");
}
