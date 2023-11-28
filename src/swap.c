/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:14:32 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/28 09:28:29 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_list **x, char *s)
{
	t_list	*next;
	t_list	*tmp;

	if (!(*x))
		return ;
	next = (*x)->next;
	if (!next)
		return ;
	tmp = *x;
	tmp->next = next->next;
	*x = next;
	(*x)->next = tmp;
	ft_dprintf(1, "%s\n", s);
}

void	ss(t_list **a, t_list **b)
{
	sx(a, "sa");
	sx(b, "sb");
}
