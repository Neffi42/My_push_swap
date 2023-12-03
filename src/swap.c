/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:14:32 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/03 10:47:51 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_dlist **x, char *s)
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
	if (s)
		ft_dprintf(1, "%s\n", s);
}

void	ss(t_dlist **a, t_dlist **b)
{
	sx(a, NULL);
	sx(b, NULL);
	ft_dprintf(1, "ss\n");
}
