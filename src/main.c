/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:41:58 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/04 17:04:55 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_arg(const char *s, void	*p)
{
	int		x;
	char	*tmp;

	x = ft_atoi(s);
	tmp = ft_itoa(x);
	if (!tmp)
		return (0);
	if (strncmp(s, tmp, ft_strlen(s)))
		return (free(tmp), 0);
	*(int *)p = x;
	return (free(tmp), 1);
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

static int	init_stack(t_dlist **a, int ac, char **av, int offset)
{
	void	*p;
	int		i;

	i = -1 + offset;
	*a = NULL;
	while (++i < ac)
	{
		p = malloc(sizeof(int));
		if (!p)
			return (0);
		if (!check_arg(av[i], p))
			return (free(p), 0);
		ft_dlstadd_back(a, ft_dlstnew(p));
		if ((!offset && i + 1 != ft_dlstsize(*a)) || \
		(offset && i != ft_dlstsize(*a)))
			return (free(p), 0);
	}
	return (check_dup(*a));
}

static void	init_index(t_dlist **a, size_t size_a)
{
	t_dlist	*tmp;
	int		found_new;
	int		biggest;
	size_t	i;

	i = size_a;
	while (i-- > 0)
	{
		tmp = *a;
		found_new = 0;
		while (tmp && tmp->index != -1)
			tmp = tmp->next;
		while (tmp)
		{
			if (tmp->index == -1 && (!found_new++ || peek(tmp) > biggest))
				biggest = peek(tmp);
			tmp = tmp->next;
		}
		tmp = *a;
		while (found_new && tmp && biggest != peek(tmp))
			tmp = tmp->next;
		if (tmp)
			tmp->index = i;
	}
}

int	main(int ac, char **av)
{
	t_dlist	*a;
	t_dlist	*b;

	if (ac < 2)
		return (0);
	b = NULL;
	if (ac == 2)
	{
		ac = count_words(av[1], ' ');
		av = ft_split(av[1], ' ');
		if (!av)
			return (error());
		if (!init_stack(&a, ac, av, 0))
			return (free_split(av), free_stakcs(&a, &b), error());
		free_split(av);
	}
	else if (!init_stack(&a, ac, av, 1))
		return (free_stakcs(&a, &b), error());
	if (is_list_sort(a))
		return (free_stakcs(&a, &b), 0);
	init_index(&a, ft_dlstsize(a));
	if (!sort(&a, &b))
		return (free_stakcs(&a, &b), error());
	return (free_stakcs(&a, &b), 0);
}
