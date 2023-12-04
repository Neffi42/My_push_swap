/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:04:21 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/04 11:37:53 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_list(t_dlist **x, t_dir *d, int end, char c)
{
	if (d->up)
		while (d->mov-- > end)
			rx(x, c);
	else if (!d->up)
		while (d->mov-- > end)
			rrx(x, c);
}

static void	shift_back(t_dlist **a, t_dir *d, int x, char c)
{
	if (d->up == -1)
		rx(a, c);
	if (d->up)
		while (x-- > 0)
			rrx(a, c);
	else if (!d->up)
		while (1 + x-- > 0)
			rx(a, c);
}

void	insertion(t_dlist **a, t_dlist **b)
{
	int		x;
	t_dir	da;
	t_dir	db;

	while (*b)
	{
		lowest_cost(a, b, &da, &db);
		x = da.mov;
		if (da.up > 0 && db.mov > 1 && da.mov > 0 && da.up == db.up)
			while (da.mov-- > 0 && db.mov-- > 1)
				rr(a, b);
		else if (!da.up && db.mov > 1 && da.mov > 0 && da.up == db.up)
			while (da.mov-- > 0 && db.mov-- > 1)
				rrr(a, b);
		shift_list(b, &db, 1, 'b');
		shift_list(a, &da, 0, 'a');
		px(a, b, 'a');
		shift_back(a, &da, x, 'a');
	}
}
