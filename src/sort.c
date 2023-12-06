/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:23 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/06 15:19:27 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_dlist **a)
{
	size_t	size_a;

	size_a = ft_dlstsize(*a);
	while (!is_list_sort(*a))
	{
		if (size_a == 2 || !is_node_sort(*a, (*a)->next))
			sx(a, 'a');
		else
			rrx(a, 'a');
	}
}

static void	partition(t_dlist **a, t_dlist **b, size_t *size_a, int median)
{
	t_dir	d;
	int		last;

	last = -1;
	while (*size_a > 3 && lowest_cost_up_med(*a, &d, median, last))
	{
		shift_list(a, &d, 0, 'a');
		last = (*a)->index;
		px(b, a, 'b');
		(*size_a)--;
	}
}

static void	find_biggest_sorted(t_dlist *a, t_dlist	*ori, int *s, int *biggest)
{
	t_dlist	*tmp;
	int	s_biggest[2];

	*biggest = a->index;
	*s = 1;
	s_biggest[1] = 0;
	while (!s_biggest[1] && a)
	{
		tmp = a;
		s_biggest[0] = 1;
		while (tmp && tmp->next && is_node_sort(tmp, tmp->next))
		{
			if (!tmp->next->next && is_node_sort(tmp->next, ori) \
				&& ++(s_biggest[0]) && (s_biggest[1])++)
				tmp = ori;
			(s_biggest[0])++;
			tmp = tmp->next;
		}
		if (s_biggest[0] > *s)
		{
			*biggest = a->index;
			*s = s_biggest[0];
		}
		a = a->next;
	}
}

int	sort(t_dlist **a, t_dlist **b)
{
	size_t	size_a;
	int		s_biggest_sorted;
	int		biggest;
	int		median;

	size_a = ft_dlstsize(*a);
	find_biggest_sorted(*a, *a, &s_biggest_sorted, &biggest);
	ft_dprintf(1, "biggest:%d s_big%d\n", biggest, s_biggest_sorted);
	print_dlist(*a, 'a');
	print_dlist(*b, 'b');
	if (size_a > 3)
	{
		median = find_median(*a);
		partition(a, b, &size_a, median);
		while (size_a-- > 3)
			px(b, a, 'b');
	}
	sort_three(a);
	if (*b)
		insertion(a, b);
	return (1);
}
