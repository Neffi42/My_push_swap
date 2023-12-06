/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:42:16 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/06 16:34:01 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_dir
{
	int	up;
	int	mov;
	int	spec;
}	t_dir;

void	sx(t_dlist **x, char c);
void	ss(t_dlist **a, t_dlist **b);
void	px(t_dlist **x, t_dlist **y, char c);
void	rx(t_dlist **x, char c);
void	rr(t_dlist **a, t_dlist **b);
void	rrx(t_dlist **x, char c);
void	rrr(t_dlist **a, t_dlist **b);
int		peek(t_dlist	*x);
t_dlist	*find_in_list(t_dlist *x, int index);
int		sort(t_dlist **a, t_dlist **b);
int		find_median(t_dlist *x);
t_dlist	*go_to_index(t_dlist *x, int index, t_dir *d);
void	init_dir(t_dir *x, int up, int mov, int spec);
void	calculate_cost_a(t_dlist *a, t_dir **d, int index, int spec);
void	calculate_cost_b(t_dlist *b, t_dir **d, int index);
void	lowest_cost(t_dlist *a, t_dlist *b, t_dir *da, t_dir *db);
void	shift_list(t_dlist **x, t_dir *d, int end, char c);
void	insertion(t_dlist **a, t_dlist **b);

int		is_node_sort(t_dlist *x, t_dlist *y);
int		is_list_sort(t_dlist *x);
void	free_stakcs(t_dlist **a, t_dlist **b);
int		error(void);

void	print_dlist(t_dlist *x, char c);

#endif
