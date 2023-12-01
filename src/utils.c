/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:31:28 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/01 16:51:43 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	peek(t_dlist	*x)
{
	if (!x)
		return (-1);
	return (*(int *)x->content);
}

t_dlist	*find_in_list(t_dlist *x, int index)
{
	while (x && x->index != index)
		x = x->next;
	if (!x)
		return (NULL);
	return (x);
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
		ft_dprintf(1, "\n");
	}
}
