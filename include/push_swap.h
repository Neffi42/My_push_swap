/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:42:16 by abasdere          #+#    #+#             */
/*   Updated: 2023/12/07 09:35:12 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include "stack.h"

typedef struct s_dir
{
	int	up;
	int	mov;
	int	spec;
}	t_dir;

int		sort(t_dlist **a, t_dlist **b);
int		find_median(t_dlist *x);
t_dlist	*go_to_index(t_dlist *x, int index, t_dir *d);
void	init_dir(t_dir *x, int up, int mov, int spec);
void	calculate_cost_a(t_dlist *a, t_dir **d, int index, int spec);
void	calculate_cost_b(t_dlist *b, t_dir **d, int index);
void	lowest_cost(t_dlist *a, t_dlist *b, t_dir *da, t_dir *db);
void	shift_list(t_dlist **x, t_dir *d, int end, char c);
void	insertion(t_dlist **a, t_dlist **b);

#endif
