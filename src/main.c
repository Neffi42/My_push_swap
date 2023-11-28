/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:41:58 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/28 09:29:21 by abasdere         ###   ########.fr       */
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
	if (!x)
		return ;
	ft_dprintf(1, "%d\n", *((int *)x->content));
	while (x->next)
	{
		x = x->next;
		ft_dprintf(1, "%d\n", *((int *)x->content));
	}
}

static int	init_stacks(t_list **a, t_list **b, int ac, const char **av)
{
	void	*p;
	int		i;

	i = 0;
	*a = NULL;
	*b = ft_lstnew(NULL);
	if (!(*b))
		return (0);
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

int	main(int ac, const char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		return (0);
	if (!init_stacks(&a, &b, ac, av))
		return (ft_lstclear(&a, &free), ft_lstclear(&b, &free), error());
	print_list(a);
	ss(&a, &b);
	print_list(a);
	return (ft_lstclear(&a, &free), ft_lstclear(&b, &free), 0);
}
