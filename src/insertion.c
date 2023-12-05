/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:04:21 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/05 22:27:21 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	two_shifts(t_dlist **a, t_dlist **b, t_dir *da, t_dir *db)
// {
// 	if (!da->up && da->up == db->up)
// 	{
// 		while (da->mov-- > 0 && db->mov-- > 0)
// 		{
// 			rr(a, b);
// 			da->mov--;
// 			db->mov--;
// 		}
// 	}
// 	else if (da->up && da->up == db->up)
// 	{
// 		while (da->mov-- > 0 && db->mov-- > 0)
// 		{
// 			rrr(a, b);
// 			da->mov--;
// 			db->mov--;
// 		}
// 	}
// }

static void	shift_back(t_dlist **a, t_dir *da, char c)
{
	calculate_cost_a(*a, da, 0, 0);
	if (!da->up)
		while (da->mov-- > 0)
			rx(a, c);
	else if (da->up)
		while (da->mov-- > 0)
			rrx(a, c);
}

void	shift_list(t_dlist **x, t_dir *d, int end, char c)
{
	if (!d->up)
		while (d->mov-- > end)
			rx(x, c);
	else if (d->up)
		while (d->mov-- > end)
			rrx(x, c);
}

void	insertion(t_dlist **a, t_dlist **b)
{
	t_dir	da;
	t_dir	db;

	while (*b)
	{
		lowest_cost(*a, *b, &da, &db);
		shift_list(b, &db, 0, 'b');
		shift_list(a, &da, 0, 'a');
		px(a, b, 'a');
		if (da.sa)
			sx(a, 'a');
	}
	shift_back(a, &da, 'a');
}
