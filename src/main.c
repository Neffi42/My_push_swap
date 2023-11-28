/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:41:58 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/28 16:44:47 by abasdere         ###   ########.fr       */
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

static void	print_list(t_list *x)
{
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

static int	init_stack(t_list **a, t_list **b, int ac, const char **av)
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
		ft_lstadd_back(a, ft_lstnew(p));
		if (i != ft_lstsize(*a))
			return (0);
	}
	return (1);
}

static void	bubble_sort(t_list **a, t_list **b)
{
	while (*a)
	{
		while (!(*b) || !(*b)->next)
			px(b, a, "pb");
		if (!(*b)->content < !(*b)->next->content)
			sx(b, "sb");
	}
	while (*b)
	{
		while (!(*a) || !(*a)->next)
			px(a, b, "pa");
		if (!(*a)->content < !(*a)->next->content)
			sx(a, "sa");
	}
}

int	main(int ac, const char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		return (0);
	if (!init_stack(&a, &b, ac, av))
		return (ft_lstclear(&a, &free), ft_lstclear(&b, &free), error());
	print_list(a);
	print_list(b);
	bubble_sort(&a, &b);
	print_list(a);
	print_list(b);
	return (ft_lstclear(&a, &free), ft_lstclear(&b, &free), 0);
}
