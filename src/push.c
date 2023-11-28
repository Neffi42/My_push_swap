/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:14:35 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/28 14:46:46 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_list **x, t_list **y, char *s)
{
	t_list	*tmp;

	if (!(*y))
		return ;
	tmp = (*y)->next;
	ft_lstadd_front(x, *y);
	*y = tmp;
	ft_dprintf(1, "%s\n", s);
}
