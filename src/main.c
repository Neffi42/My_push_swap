/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:41:58 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/28 23:18:29 by abasdere         ###   ########.fr       */
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

// static void	print_list(t_list *x)
// {
// 	if (!x || !x->content)
// 	{
// 		ft_dprintf(1, "\nempty\n\n");
// 		return ;
// 	}
// 	ft_dprintf(1, "\n%d\n", *((int *)x->content));
// 	while (x->next)
// 	{
// 		x = x->next;
// 		if (x->content)
// 			ft_dprintf(1, "%d\n", *((int *)x->content));
// 	}
// 	ft_dprintf(1, "\n");
// }

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

static void	sort(t_list **a, t_list **b)
{
	t_list	*tmp;

	while (*a)
	{
		tmp = *a;
		if (*b)
		{
			rx(a, "ra");
			while (*b && *(int *)(*b)->content > *(int *)tmp->content)
				px(a, b, "pa");
			rrx(a, "rra");
		}
		px(b, a, "pb");
	}
	while (*b)
		px(a, b, "pa");
}

int	main(int ac, const char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		return (0);
	if (!init_stack(&a, &b, ac, av))
		return (ft_lstclear(&a, &free), ft_lstclear(&b, &free), error());
	sort(&a, &b);
	return (ft_lstclear(&a, &free), ft_lstclear(&b, &free), 0);
}
