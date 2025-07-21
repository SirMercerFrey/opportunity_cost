/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:34:31 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/21 15:19:10 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hardcode_three(t_head *pile)
{
	int		f;
	int		s;
	int		t;

	f = pile->first->index;
	s = pile->first->next->index;
	t = pile->first->next->next->index;
	if (f < s && s < t)
		return ;
	if (f < t && t < s)
	{
		reverse_rotate_a(pile);
		swap_a (pile);
	}
	if (s < f && f < t)
		swap_a(pile);
	if (t < f && f < s)
		reverse_rotate_a(pile);
	if (t < s && s < f)
	{
		swap_a(pile);
		reverse_rotate_a(pile);
	}
	if (s < t && t < f)
		rotate_a(pile);
}

void	cost_sort(t_head *pile_a, t_head *pile_b)
{
	t_node	*chosen_one;
	long	size;

	size = pile_a->size;
	while (pile_a->size > 3)
	{
		push_b(pile_a, pile_b);
		if (size > 100 && pile_b->first->index <= size / 2)
			rotate_b(pile_b);
	}
	hardcode_three(pile_a);
	while (pile_b->size)
	{
		put_pos_in_b(pile_b);
		put_cost_in_b(pile_b);
		put_pos_in_a(pile_a, pile_b);
		put_cost_in_a(pile_a, pile_b);
		put_real_cost(pile_b);
		chosen_one = find_smallest_cost(pile_b);
		chose_cases(pile_a, pile_b, chosen_one);
	}
	find_and_move_index_zero(pile_a);
}

void	put_real_cost(t_head *pile_b)
{
	t_node	*tmp;

	tmp = pile_b->first;
	while (tmp)
	{
		if (tmp->flag_a != tmp->flag_b)
			tmp->real_cost = tmp->cost_a + tmp->cost_b;
		if (tmp->flag_a == tmp->flag_b && tmp->cost_a <= tmp->cost_b)
			tmp->real_cost = tmp->cost_b;
		if (tmp->flag_a == tmp->flag_b && tmp->cost_a > tmp->cost_b)
			tmp->real_cost = tmp->cost_a;
		tmp = tmp->next;
	}
}

t_node	*find_smallest_cost(t_head *pile_b)
{
	t_node	*tmp;
	t_node	*little_thumb;
	long	smallest_cost;

	tmp = pile_b->first;
	smallest_cost = LONG_MAX;
	while (tmp)
	{
		if (tmp->real_cost < smallest_cost)
		{
			little_thumb = tmp;
			smallest_cost = tmp->real_cost;
		}
		tmp = tmp->next;
	}
	return (little_thumb);
}

void	find_and_move_index_zero(t_head *pile_a)
{
	t_node	*tmp;
	long	pos;

	pos = 0;
	tmp = pile_a->first;
	while (tmp)
	{
		if (tmp->index == 0)
			break ;
		++pos;
		tmp = tmp->next;
	}
	if (pos > pile_a->size / 2)
	{
		pos = pile_a->size - pos;
		while (pos--)
			reverse_rotate_a(pile_a);
	}
	else
	{
		while (pos--)
			rotate_a(pile_a);
	}
}
