/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:19:32 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/21 15:29:32 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_head *pile)
{
	t_node	*first;
	t_node	*second;

	if (!pile || pile->size < 2)
		return (0);
	first = pile->first;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	pile->first = second;
	if (first->next == NULL)
		pile->last = first;
	return (1);
}

void	swap_a(t_head *pile_a)
{
	if (swap(pile_a))
		printf("sa\n");
}

void	swap_b(t_head *pile_b)
{
	if (swap(pile_b))
		printf("sb\n");
}

void	swap_both(t_head *pile_a, t_head *pile_b)
{
	if (swap(pile_a) && swap(pile_b))
		printf("ss\n");
}
