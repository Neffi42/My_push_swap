/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:14:35 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/04 11:23:16 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_dlist **x, t_dlist **y, char c)
{
	t_dlist	*tmp;

	if (!(*y))
		return ;
	tmp = (*y)->next;
	ft_dlstadd_front(x, *y);
	if (tmp)
		tmp->prev = NULL;
	*y = tmp;
	ft_dprintf(1, "p%c\n", c);
}
