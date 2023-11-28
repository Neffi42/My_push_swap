/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:31:28 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/28 23:32:06 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *x)
{
	if (!x || !x->content)
	{
		ft_dprintf(1, "\nempty\n\n");
		return ;
	}
	ft_dprintf(1, "\n%d\n", *((int *)x->content));
	while (x->next)
	{
		x = x->next;
		if (x->content)
			ft_dprintf(1, "%d\n", *((int *)x->content));
	}
	ft_dprintf(1, "\n");
}
