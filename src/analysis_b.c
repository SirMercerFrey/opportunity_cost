/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:34:31 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/11 18:09:42 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_pos_in_b(t_head *pile_b)
{
	t_node	*tmp;
	long	pos;

	pos = 0;
	tmp = pile_b->first;
	while (tmp)
	{
		tmp->pos_b = pos;
		++pos;
		tmp = tmp->next;
	}
}

void	put_cost_in_b(t_head *pile_b)
{
	t_node	*tmp;

	tmp = pile_b->first;
	while (tmp)
	{
		tmp->cost_b = tmp->pos_b;
		tmp->flag_b = 1;
		if (tmp->pos_b > pile_b->size / 2)
		{
			tmp->cost_b = pile_b->size - tmp->pos_b;
			tmp->flag_b = -1;
		}
		tmp = tmp->next;
	}
}
