/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:42:16 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/28 14:55:03 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

int		error(void);
void	sx(t_list **x, char *s);
void	ss(t_list **a, t_list **b);
void	px(t_list **x, t_list **y, char *s);
void	rx(t_list **x, char *s);
void	rr(t_list **a, t_list **b);
void	rrx(t_list **x, char *s);
void	rrr(t_list **a, t_list **b);

#endif
