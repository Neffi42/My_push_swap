/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:04:21 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/05 12:35:01 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	two_shifts(t_dlist **a, t_dlist **b, t_dir *da, t_dir *db)
{
	if (da->up == -1 && db->mov > 1 && da->mov > da->sa && da->up == db->up)
		while (da->mov-- > da->sa && db->mov-- > 1)
			rr(a, b);
	else if (da->up == 1 && db->mov > 1 && da->mov > da->sa \
	&& da->up == db->up)
		while (da->mov-- > da->sa && db->mov-- > 1)
			rrr(a, b);
}

static void	shift_list(t_dlist **x, t_dir *d, int end, char c)
{
	if (d->up == -1)
		while (d->mov-- > end)
			rx(x, c);
	else if (d->up == 1)
		while (d->mov-- > end)
			rrx(x, c);
}

static void	shift_back(t_dlist **a, t_dir *da, char c)
{
	*da = fastest_to_dest(go_to_index(*a, 0, NULL, 0), (*a)->index, 0);
	if (da->up == 1)
		while (da->mov-- > 0)
			rx(a, c);
	else if (da->up == -1)
		while (da->mov-- > 0)
			rrx(a, c);
}

void	insertion(t_dlist **a, t_dlist **b)
{
	t_dir	da;
	t_dir	db;

	while (*b)
	{
		print_dlist(*a, 'a');
		print_dlist(*b, 'b');
		lowest_cost(a, b, &da, &db);
		ft_dprintf(1, "a: u:%d m:%d s:%d\n", da.up, da.mov, da.sa);
		ft_dprintf(1, "b: u:%d m:%d s:%d\n", db.up, db.mov, db.sa);
		two_shifts(a, b, &da, &db);
		shift_list(b, &db, 1, 'b');
		shift_list(a, &da, da.sa, 'a');
		px(a, b, 'a');
		if (da.sa)
			sx(a, 'a');
	}
	shift_back(a, &da, 'a');
	print_dlist(*a, 'a');
	print_dlist(*b, 'b');
	// ft_dprintf(1, "sizea:%d sizeb:%d\n", ft_dlstsize(*a), ft_dlstsize(*b));
}
