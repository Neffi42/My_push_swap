/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:31:28 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/29 21:00:15 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	peek(t_dlist	*x)
{
	if (!x)
		return (-1);
	return (*(int *)x->content);
}

void	print_dlist(t_dlist *x, char c)
{
	ft_dprintf(1, "%c:\n", c);
	if (!x || !x->content)
	{
		ft_dprintf(1, "empty\n\n");
		return ;
	}
	ft_dprintf(1, "%d\n", *((int *)x->content));
	while (x->next)
	{
		x = x->next;
		if (x->content)
			ft_dprintf(1, "%d\n", *((int *)x->content));
	}
	ft_dprintf(1, "\n");
}
