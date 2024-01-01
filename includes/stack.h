/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:33:13 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/01 16:27:08 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

void	sx(t_dlist **x, char c);
void	ss(t_dlist **a, t_dlist **b, int print);
void	px(t_dlist **x, t_dlist **y, char c);
void	rx(t_dlist **x, char c);
void	rr(t_dlist **a, t_dlist **b, int print);
void	rrx(t_dlist **x, char c);
void	rrr(t_dlist **a, t_dlist **b, int print);
int		peek(t_dlist	*x);
t_dlist	*find_in_list(t_dlist *x, int index);
int		is_node_sort(t_dlist *x, t_dlist *y);
int		is_list_sort(t_dlist *x);
void	free_stakcs(t_dlist **a, t_dlist **b);
int		error(void);
void	print_dlist(t_dlist *x, char c);

#endif
