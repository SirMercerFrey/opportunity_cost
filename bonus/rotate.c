/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:20:38 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/21 16:10:38 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	rotate(t_head *pile)
{
	t_node	*first;
	t_node	*second;

	if (!pile || pile->size < 2)
		return (0);
	first = pile->first;
	second = first->next;
	second->prev = NULL;
	pile->first = second;
	first->next = NULL;
	first->prev = pile->last;
	pile->last->next = first;
	pile->last = first;
	return (1);
}

void	rotate_both(t_head *pile_a, t_head *pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
}
