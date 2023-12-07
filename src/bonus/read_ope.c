/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:36:59 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/07 10:11:06 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	exec_ope(t_dlist **a, t_dlist **b, char *s, size_t len)
{
	if (!ft_strncmp("ra", s, len))
		rx(a, 'a');
	else if (!ft_strncmp("rb", s, len))
		rx(b, 'b');
	else if (!ft_strncmp("rr", s, len))
		rr(a, b);
	else if (!ft_strncmp("rra", s, len))
		rrx(a, 'a');
	else if (!ft_strncmp("rrb", s, len))
		rrx(b, 'b');
	else if (!ft_strncmp("rr", s, len))
		rrr(a, b);
	else if (!ft_strncmp("sa", s, len))
		sx(a, 'a');
	else if (!ft_strncmp("sb", s, len))
		sx(b, 'b');
	else if (!ft_strncmp("ss", s, len))
		ss(a, b);
	else if (!ft_strncmp("pa", s, len))
		px(a, b, 'a');
	else if (!ft_strncmp("pb", s, len))
		px(b, a, 'b');
	else
		return (error());
	return (1);
}

int	read_ope(t_dlist **a, t_dlist **b)
{
	char	*s;
	size_t	len;

	s = get_next_line(0);
	if (!s)
		return (ko());
	len = ft_strlen(s) - 1;
	while (s)
	{
		if (exec_ope(a, b, s, len) == -1)
			return (0);
		s = get_next_line(0);
	}
	if (!is_list_sort(*a) || ft_dlstsize(*b))
		return (ko());
	return (1);
}
