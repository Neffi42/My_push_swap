/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:41:58 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/03 10:48:38 by abasdere         ###   ########.fr       */
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

static int	check_dup(t_dlist *a)
{
	t_dlist	*next;
	t_dlist	*prev;

	while (a)
	{
		next = a->next;
		prev = a->prev;
		while (next)
		{
			if (*(int *)a->content == *(int *)next->content)
				return (0);
			next = next->next;
		}
		while (prev)
		{
			if (*(int *)a->content == *(int *)prev->content)
				return (0);
			prev = prev->prev;
		}
		a = a->next;
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
	return (check_dup(*a));
}

static void	init_index(t_dlist **a, size_t size_a)
{
	t_dlist	*tmp;
	int		biggest;
	size_t	i;

	i = size_a;
	while (i-- > 0)
	{
		tmp = *a;
		biggest = -1;
		while (tmp)
		{
			if (tmp->index == -1 && biggest < peek(tmp))
				biggest = peek(tmp);
			tmp = tmp->next;
		}
		tmp = *a;
		while (biggest != -1 && tmp && biggest != peek(tmp))
			tmp = tmp->next;
		if (tmp)
			tmp->index = i;
	}
}

int	main(int ac, const char **av)
{
	t_dlist	*a;
	t_dlist	*b;

	if (ac < 2)
		return (0);
	if (!init_stack(&a, &b, ac, av))
		return (free_stakcs(&a, &b), error());
	if (is_list_sort(a))
		return (free_stakcs(&a, &b), 0);
	init_index(&a, ft_dlstsize(a));
	print_dlist(a, 'a');
	print_dlist(b, 'b');
	if (!sort(&a, &b))
		return (free_stakcs(&a, &b), error());
	print_dlist(a, 'a');
	print_dlist(b, 'b');
	return (free_stakcs(&a, &b), 0);
}
