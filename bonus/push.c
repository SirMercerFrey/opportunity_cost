/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:19:32 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/21 16:09:25 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	push(t_head *from, t_head *to)
{
	t_node	*node;

	if (!from || from->size == 0)
		return (0);
	node = from->first;
	from->first = node->next;
	if (from->first)
		from->first->prev = NULL;
	else
		from->last = NULL;
	from->size--;
	node->next = to->first;
	if (to->first)
		to->first->prev = node;
	else
		to->last = node;
	node->prev = NULL;
	to->first = node;
	to->size++;
	return (1);
}
