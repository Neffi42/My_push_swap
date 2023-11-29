/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:41:58 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/29 09:40:12 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_arg(const char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static int	init_stack(t_dlist **a, t_dlist **b, int ac, const char **av)
{
	void	*p;
	int		i;

	i = 0;
	*a = NULL;
	*b = NULL;
	while (++i < ac)
	{
		if (!check_arg(av[i]))
			return (0);
		p = malloc(sizeof(int));
		if (!p)
			return (0);
		*((int *)p) = ft_atoi(av[i]);
		ft_dlstadd_back(a, ft_dlstnew(p));
		if (i != ft_dlstsize(*a))
			return (0);
	}
	return (1);
}

static void	first_and_last(t_dlist **a, t_dlist **b, t_dlist *la, t_dlist *lb)
{
	if (!is_node_sort(*a, la) && !is_node_sort(*b, lb))
		rrr(a, b);
	else if (!is_node_sort(*a, la))
		rrx(a, "rra");
	else if (!is_node_sort(*b, lb))
		rrx(b, "rrb");
}

static void	sort(t_dlist **a, t_dlist **b)
{
	size_t	size_a;
	size_t	x;
	t_dlist	*last_a;
	t_dlist	*last_b;

	size_a = ft_dlstsize(*a);
	x = 0;
	while (!is_list_sort(*a))
	{
		while (x++ < size_a / 2)
		{
			if (!is_node_sort(*a, (*a)->next))
				sx(a, "sa");
			px(b, a, "pb");
		}
		last_a = ft_dlstlast(*a);
		last_b = ft_dlstlast(*b);
		first_and_last(a, b, last_a, last_b);
		// if (is_list_sort(b))
		// 	while (*b)
		// 		px(a, b, "pa");
	}
}

int	main(int ac, const char **av)
{
	t_dlist	*a;
	t_dlist	*b;

	if (ac < 2)
		return (0);
	if (!init_stack(&a, &b, ac, av))
		return (ft_dlstclear(&a, &free), ft_dlstclear(&b, &free), error());
	print_dlist(a);
	sort(&a, &b);
	print_dlist(a);
	return (ft_dlstclear(&a, &free), ft_dlstclear(&b, &free), 0);
}

// static void	bubble_sort(t_dlist **a, t_dlist **b)
// {
// 	t_dlist	*tmp;

// 	while (*a)
// 	{
// 		tmp = *a;
// 		if (*b)
// 		{
// 			rx(a, "ra");
// 			while (*b && *(int *)(*b)->content > *(int *)tmp->content)
// 				px(a, b, "pa");
// 			rrx(a, "rra");
// 		}
// 		px(b, a, "pb");
// 	}
// 	while (*b)
// 		px(a, b, "pa");
// }
