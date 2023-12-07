/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:14:32 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/04 11:25:08 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_dlist **x, char c)
{
	t_dlist	*next;

	if (!(*x) || !(*x)->next)
		return ;
	next = (*x)->next;
	if (next->next)
		next->next->prev = *x;
	(*x)->prev = next;
	next->prev = NULL;
	(*x)->next = next->next;
	next->next = (*x);
	(*x) = next;
	if (c)
		ft_dprintf(1, "s%c\n", c);
}

void	ss(t_dlist **a, t_dlist **b)
{
	sx(a, '\0');
	sx(b, '\0');
	ft_dprintf(1, "ss\n");
}
