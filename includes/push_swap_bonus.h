/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:09:25 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/01 16:26:54 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include "stack.h"

int		read_ope(t_dlist **a, t_dlist **b);
int		error(void);
void	free_stakcs(t_dlist **a, t_dlist **b);
int		peek(t_dlist	*x);
int		is_node_sort(t_dlist *x, t_dlist *y);
int		is_list_sort(t_dlist *x);
int		ok(void);
int		ko(void);

#endif
