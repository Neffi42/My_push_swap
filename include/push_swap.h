/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:42:16 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/01 15:53:29 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_dir
{
	int	is_up;
	int	move;
}	t_dir;

void	sx(t_dlist **x, char *s);
void	ss(t_dlist **a, t_dlist **b);
void	px(t_dlist **x, t_dlist **y, char *s);
void	rx(t_dlist **x, char *s);
void	rr(t_dlist **a, t_dlist **b);
void	rrx(t_dlist **x, char *s);
void	rrr(t_dlist **a, t_dlist **b);
int		peek(t_dlist	*x);
t_dlist	*find_in_list(t_dlist *x, int index);
int		sort(t_dlist **a, t_dlist **b);
int		find_median(t_dlist **x);
int		still_el_sup_median(t_dlist **x, int median);
t_dir	fastest_to_dest(t_dlist *x, int dest);

int		is_node_sort(t_dlist *x, t_dlist *y);
int		is_list_sort(t_dlist *x);
void	free_stakcs(t_dlist **a, t_dlist **b);
int		error(void);

void	print_dlist(t_dlist *x, char c);

#endif
