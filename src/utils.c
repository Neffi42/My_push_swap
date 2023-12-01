/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:31:28 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/01 09:54:55 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	peek(t_dlist	*x)
{
	if (!x)
		return (-1);
	return (*(int *)x->content);
}

void	free_stakcs(t_dlist **a, t_dlist **b)
{
	ft_dlstclear(a, &free);
	ft_dlstclear(b, &free);
}

void	print_dlist(t_dlist *x, char c)
{
	ft_dprintf(1, "%c: ", c);
	if (!x || !x->content)
		ft_dprintf(1, "empty\n");
	else
	{
		ft_dprintf(1, "%d(%d) ", *((int *)x->content), x->index);
		while (x->next)
		{
			x = x->next;
			if (x->content)
				ft_dprintf(1, "%d(%d) ", *((int *)x->content), x->index);
		}
	}
	ft_dprintf(1, "\n");
}

void	print_tab(int *tab, size_t s_tab)
{
	size_t	i;

	i = 0;
	while (i < s_tab)
		ft_dprintf(1, "%d ", tab[i++]);
	ft_dprintf(1, "\n");
}
