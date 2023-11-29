/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:42:16 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/29 21:50:57 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

void	sx(t_dlist **x, char *s);
void	ss(t_dlist **a, t_dlist **b);
void	px(t_dlist **x, t_dlist **y, char *s);
void	rx(t_dlist **x, char *s);
void	rr(t_dlist **a, t_dlist **b);
void	rrx(t_dlist **x, char *s);
void	rrr(t_dlist **a, t_dlist **b);
void	sort(t_dlist **a, t_dlist **b);
int		is_node_sort(t_dlist *x, t_dlist *y);
int		is_list_sort(t_dlist *x);
int		peek(t_dlist	*x);
void	print_dlist(t_dlist *x, char c);
int		error(void);

int		find_median(t_dlist *x);

#endif
