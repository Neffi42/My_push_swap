/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:08:11 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/05 12:39:43 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_dir(t_dir *x, int up, int mov, int sa)
{
	x->up = up;
	x->mov = mov;
	x->sa = sa;
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

t_dlist	*go_to_index(t_dlist *x, int index, t_dir *dir, int up)
{
	if (!up)
		while (x && x->index != index)
			x = x->next;
	else
	{
		if (up == -1)
			while (x && x->index != index && ++(dir->mov))
				x = x->next;
		else if (up == 1)
			while (x && x->index != index && ++(dir->mov))
				x = x->prev;
		if (!x)
			return (NULL);
	}
	return (x);
}

t_dir	fastest_to_dest(t_dlist *x, int dest, int offset)
{
	t_dlist	*tmp;
	t_dir	dir;
	t_dir	dir2;

	init_dir(&dir, -1, offset, offset);
	init_dir(&dir2, 1, offset, offset);
	tmp = go_to_index(x, dest, &dir, -1);
	if (!tmp && !go_to_index(go_extrem(x, 1), dest, &dir, -1))
		return (init_dir(&dir, 0, 0, 0), dir);
	tmp = go_to_index(x, dest, &dir2, 1);
	if (!tmp && !go_to_index(go_extrem(x, 0), dest, &dir2, 1))
		return (init_dir(&dir2, 0, 0, 0), dir2);
	// ft_dprintf(1, "1: %d %d %d\n", dir.up, dir.mov, dir.sa);
	// ft_dprintf(1, "2: %d %d %d\n", dir2.up, dir2.mov, dir2.sa);
	if (dir.mov >= dir2.mov)
		return (dir2);
	return (dir);
}
