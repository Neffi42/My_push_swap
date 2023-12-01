/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:14:32 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/01 16:52:19 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_dlist **x, char *s)
{
	t_dlist	*next;
	t_dlist	*tmp;

	if (!(*x) || !(*x)->next)
		return ;
	next = (*x)->next;
	next->prev = NULL;
	tmp = *x;
	tmp->next = next->next;
	tmp->prev = next;
	*x = next;
	(*x)->next = tmp;
	if (s)
		ft_dprintf(1, "%s\n", s);
}

void	ss(t_dlist **a, t_dlist **b)
{
	sx(a, NULL);
	sx(b, NULL);
	ft_dprintf(1, "ss\n");
}
