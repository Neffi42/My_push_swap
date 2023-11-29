/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:48:50 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/29 22:47:15 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
medianOfMedians(arr[1...n])
    if(n < 5 return Select(arr[1...n], n/2))
    Let M be an empty list
    For i from 0 to n/5 - 1:
        Let m = Select(arr[5i + 1...5i+5], 3)
        Add m to M
    Return QuickSelect(M[1...n/5], n/10)
End medianOfMedians
https://stackoverflow.com/questions/9489061/understanding-median-of-medians-algorithm
*/
static void	swap(int *tab, int a, int b)
{
	int	temp;

	temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}

static size_t	partition(int *tab, size_t pivot, size_t j)
{
	size_t	i;

	i = pivot;
	while (i < j)
	{
		while (tab[i] <= tab[pivot])
			i++;
		while (tab[j] > tab[pivot])
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

static int	median_of_medians(int *tab, size_t s_tab)
{
	int	median;

	median = 0;
	if (s_tab <= 5)
	{
		quicksort(tab, 0, s_tab - 1);
		if (s_tab % 2)
			s_tab++;
		median = s_tab / 2;
	}
	return (median);
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
	i = -1;
	while (++i < size_x)
		ft_dprintf(1, "%d ", tab[i]);
	ft_dprintf(1, "\n");
	median = median_of_medians(tab, size_x);
	i = -1;
	while (++i < size_x)
		ft_dprintf(1, "%d ", tab[i]);
	ft_dprintf(1, "%ld\n", median);
	return (free(tab), median);
}
