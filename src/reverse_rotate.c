/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:20:38 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/21 15:31:08 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_head *pile)
{
	t_node	*last;
	t_node	*before_last;

	if (!pile || pile->size < 2)
		return (0);
	last = pile->last;
	before_last = last->prev;
	before_last->next = NULL;
	pile->last = before_last;
	last->next = pile->first;
	last->prev = NULL;
	pile->first->prev = last;
	pile->first = last;
	return (1);
}

void	reverse_rotate_a(t_head *pile_a)
{
	if (reverse_rotate(pile_a))
		printf("rra\n");
}

void	reverse_rotate_b(t_head *pile_b)
{
	if (reverse_rotate(pile_b))
		printf("rrb\n");
}

void	reverse_rotate_both(t_head *pile_a, t_head *pile_b)
{
	if (reverse_rotate(pile_a) && reverse_rotate(pile_b))
		printf("rrr\n");
}
