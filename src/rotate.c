/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:20:38 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/21 15:30:45 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rotate_a(t_head *pile_a)
{
	if (rotate(pile_a))
		printf("ra\n");
}

void	rotate_b(t_head *pile_b)
{
	if (rotate(pile_b))
		printf("rb\n");
}

void	rotate_both(t_head *pile_a, t_head *pile_b)
{
	if (rotate(pile_a) && rotate(pile_b))
		printf("rr\n");
}
