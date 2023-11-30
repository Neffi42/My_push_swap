/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:48:50 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/30 16:21:11 by abasdere         ###   ########.fr       */
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

static int	quicksort(int *tab, size_t low, size_t high)
{
	size_t	j;

	if (low < high)
	{
		j = partition(tab, low, high);
		quicksort(tab, low, j);
		quicksort(tab, j + 1, high);
	}
	return (tab[low + ((high - low) / 2)]);
}

int	find_median(t_dlist *x)
{
	size_t	size_x;
	size_t	i;
	int		*tab;
	int		median;

	size_x = ft_dlstsize(x);
	tab = malloc(size_x * sizeof(int));
	if (!tab)
		return (-1);
	i = -1;
	while (++i < size_x)
	{
		tab[i] = peek(x);
		x = x->next;
	}
	median = quicksort(tab, 0, size_x - 1);
	return (free(tab), median);
}
