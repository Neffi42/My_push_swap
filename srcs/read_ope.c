/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:36:59 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/13 14:47:12 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	exec_ope(t_dlist **a, t_dlist **b, char *s)
{
	if (!ft_strncmp("ra\n", s, 3))
		rx(a, '\0');
	else if (!ft_strncmp("rb\n", s, 3))
		rx(b, '\0');
	else if (!ft_strncmp("rr\n", s, 3))
		rr(a, b, 0);
	else if (!ft_strncmp("rra\n", s, 4))
		rrx(a, '\0');
	else if (!ft_strncmp("rrb\n", s, 4))
		rrx(b, '\0');
	else if (!ft_strncmp("rrr\n", s, 4))
		rrr(a, b, 0);
	else if (!ft_strncmp("sa\n", s, 3))
		sx(a, '\0');
	else if (!ft_strncmp("sb\n", s, 3))
		sx(b, '\0');
	else if (!ft_strncmp("ss\n", s, 3))
		ss(a, b, 0);
	else if (!ft_strncmp("pa\n", s, 3))
		px(a, b, '\0');
	else if (!ft_strncmp("pb\n", s, 3))
		px(b, a, '\0');
	else
		return (error());
	return (1);
}

int	read_ope(t_dlist **a, t_dlist **b)
{
	char	*s;

	s = ft_get_next_line(0);
	if (!s && is_list_sort(*a))
		return (1);
	else if (!s)
		return (ko());
	while (s)
	{
		if (exec_ope(a, b, s) == -1)
			return (0);
		s = ft_get_next_line(0);
	}
	if (!is_list_sort(*a) || ft_dlstsize(*b))
		return (ko());
	return (1);
}
