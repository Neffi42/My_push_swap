/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:08:11 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/05 15:54:30 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_dir(t_dir *x, int up, int mov, int sa)
{
	x->up = up;
	x->mov = mov;
	x->sa = sa;
}

t_dlist	*go_to_index(t_dlist *x, int index, t_dir *d)
{
	if (!d)
		while (x && x->index != index)
			x = x->next;
	else
	{
		if (!d->up)
			while (x && x->index != index && ++(d->mov))
				x = x->next;
		else if (d->up)
			while (x && x->index != index && ++(d->mov))
				x = x->prev;
		if (!x)
			return (NULL);
	}
	return (x);
}
