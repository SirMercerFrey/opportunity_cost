/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:34:31 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/21 15:17:47 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_pos_just_bigger_in_a(t_head *pile_a, t_node *node)
{
	t_node	*tmp;
	long	index_just_bigger;
	long	pos_just_bigger;
	long	pos;

	tmp = pile_a->first;
	pos = 0;
	pos_just_bigger = -1;
	index_just_bigger = LONG_MAX;
	while (tmp)
	{
		if (tmp->index > node->index && tmp->index < index_just_bigger)
		{
			index_just_bigger = tmp->index;
			pos_just_bigger = pos;
		}
		++pos;
		tmp = tmp->next;
	}
	if (pos_just_bigger == -1)
		return (find_pos_way_smaller_in_a(pile_a));
	return (pos_just_bigger);
}

long	find_pos_way_smaller_in_a(t_head *pile_a)
{
	t_node	*tmp;
	long	index_way_smaller;
	long	pos_way_smaller;
	long	pos;

	tmp = pile_a->first;
	pos = 0;
	index_way_smaller = LONG_MAX;
	while (tmp)
	{
		if (tmp->index < index_way_smaller)
		{
			index_way_smaller = tmp->index;
			pos_way_smaller = pos;
		}
		++pos;
		tmp = tmp->next;
	}
	return (pos_way_smaller);
}

void	put_pos_in_a(t_head *pile_a, t_head *pile_b)
{
	t_node	*tmp;

	tmp = pile_b->first;
	while (tmp)
	{
		tmp->pos_a = find_pos_just_bigger_in_a(pile_a, tmp);
		tmp = tmp->next;
	}
}

void	put_cost_in_a(t_head *pile_a, t_head *pile_b)
{
	t_node	*tmp;

	tmp = pile_b->first;
	while (tmp)
	{
		tmp->cost_a = tmp->pos_a;
		tmp->flag_a = 1;
		if (tmp->pos_a > pile_a->size / 2)
		{
			tmp->cost_a = pile_a->size - tmp->pos_a;
			tmp->flag_a = -1;
		}
		tmp = tmp->next;
	}
}
