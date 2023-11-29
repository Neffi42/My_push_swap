/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:41:58 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/29 21:58:29 by abasdere         ###   ########.fr       */
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

static int	check_dup(t_dlist **a)
{
	t_dlist	*tmp;
	t_dlist	*next;
	t_dlist	*prev;

	tmp = *a;
	while (tmp)
	{
		next = tmp->next;
		prev = tmp->prev;
		while (next)
		{
			if (*(int *)tmp->content == *(int *)next->content)
				return (0);
			next = next->next;
		}
		while (prev)
		{
			if (*(int *)tmp->content == *(int *)prev->content)
				return (0);
			prev = prev->prev;
		}
		tmp = tmp->next;
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
		if (*((int *)p) <= 0)
			return (0);
		ft_dlstadd_back(a, ft_dlstnew(p));
		if (i != ft_dlstsize(*a))
			return (0);
	}
	return (check_dup(a));
}

int	main(int ac, const char **av)
{
	t_dlist	*a;
	t_dlist	*b;

	if (ac < 2)
		return (0);
	if (!init_stack(&a, &b, ac, av))
		return (ft_dlstclear(&a, &free), ft_dlstclear(&b, &free), error());
	print_dlist(a, 'a');
	print_dlist(b, 'b');
	find_median(a);
	// ft_dprintf(1, "\t- sort -\n");
	// sort(&a, &b);
	// ft_dprintf(1, "\t- sort -\n\n");
	// print_dlist(a, 'a');
	// print_dlist(b, 'b');
	return (ft_dlstclear(&a, &free), ft_dlstclear(&b, &free), 0);
}
