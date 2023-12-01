/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:08:11 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/01 16:33:41 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_dir(t_dir *x, int is_up, int move)
{
	x->is_up = is_up;
	x->move = move;
}

static t_dlist	*go_extrem(t_dlist *x, int go_first)
{
	if (go_first)
		while (x->prev)
			x = x->prev;
	else
		while (x->next)
			x = x->next;
	return (x);
}

static t_dlist	*go_next_to_index(t_dlist *x, int index, t_dir *dir)
{
	while (x && x->index != index && ++(dir->move))
		x = x->next;
	if (!x)
		return (NULL);
	return (x);
}

static t_dlist	*go_prev_to_index(t_dlist *x, int index, t_dir *dir)
{
	while (x && x->index != index && ++(dir->move))
		x = x->prev;
	if (!x)
		return (NULL);
	return (x);
}

t_dir	fastest_to_dest(t_dlist *x, int dest)
{
	t_dlist	*tmp;
	t_dir	dir;
	t_dir	dir2;

	init_dir(&dir, 0, 0);
	init_dir(&dir2, 1, 0);
	tmp = go_next_to_index(x, dest, &dir);
	if (!tmp && !go_next_to_index(go_extrem(x, 1), dest, &dir))
		return (init_dir(&dir, -1, -1), dir);
	tmp = go_prev_to_index(x, dest, &dir2);
	if (!tmp && !go_prev_to_index(go_extrem(x, 0), dest, &dir2))
		return (init_dir(&dir2, -1, -1), dir2);
	if (dir.move >= dir2.move)
		return (dir2);
	return (dir);
}
