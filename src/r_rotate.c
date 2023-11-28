/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:14:39 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/28 14:51:56 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_list **x, char *s)
{
	t_list	*before_last;
	t_list	*last;

	if (*x && (*x)->next)
	{
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

void	rrr(t_list **a, t_list **b)
{
	rrx(a, "rra");
	rrx(b, "rrb");
}
