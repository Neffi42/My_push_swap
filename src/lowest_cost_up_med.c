/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowest_cost_up_med.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:13:15 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/06 14:37:00 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lowest_cost_up_med(t_dlist *x, t_dir *d, int median, int last)
{
	t_dlist	*tmp;
	t_dir	dlast;

	tmp = ft_dlstlast(x);
	init_dir(d, 0, 0, 0);
	init_dir(&dlast, 1, 1, 0);
	while (x && x->index < median && ++d->mov)
		x = x->next;
	if (!x)
		return (0);
	while (tmp->index < median && ++dlast.mov)
		tmp = tmp->prev;
	if ((last == -1 || last - x->index >= last - tmp->index) \
		&& d->mov >= dlast.mov)
		*d = dlast;
	return (1);
}
