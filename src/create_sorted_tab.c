/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sorted_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:48:50 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/01 09:10:59 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *tab, int a, int b)
{
	int	temp;

	temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}

static size_t	partition(int *tab, size_t pivot, size_t high)
{
	size_t	i;
	size_t	j;

	i = pivot;
	j = high;
	while (i < j)
	{
		while (i < high && tab[i] <= tab[pivot])
			i++;
		while (j > pivot && tab[j] > tab[pivot])
			j--;
		if (i < j)
			swap(tab, i, j);
	}
	swap(tab, pivot, j);
	return (j);
}

static void	quicksort(int *tab, size_t low, size_t high)
{
	size_t	j;

	if (low < high)
	{
		j = partition(tab, low, high);
		quicksort(tab, low, j);
		quicksort(tab, j + 1, high);
	}
}

int	*create_sorted_tab(t_dlist *x, size_t size_x)
{
	size_t	i;
	int		*tab;

	tab = malloc(size_x * sizeof(int));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < size_x)
	{
		tab[i] = peek(x);
		x = x->next;
	}
	quicksort(tab, 0, size_x - 1);
	return (tab);
}
