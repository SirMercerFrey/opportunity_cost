/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:34:31 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/11 18:15:10 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chose_cases(t_head *pile_a, t_head*pile_b, t_node *node)
{
	if (node->flag_a == 1 && node->flag_b == 1
		&& node->cost_a <= node->cost_b)
		return (case_zero(pile_a, pile_b, node), (void)0);
	if (node->flag_a == 1 && node->flag_b == 1
		&& node->cost_a > node->cost_b)
		return (case_one(pile_a, pile_b, node), (void)0);
	if (node->flag_a == -1 && node->flag_b == -1
		&& node->cost_a <= node->cost_b)
		return (case_two(pile_a, pile_b, node), (void)0);
	if (node->flag_a == -1 && node->flag_b == -1
		&& node->cost_a > node->cost_b)
		return (case_three(pile_a, pile_b, node), (void)0);
	if (node->flag_a == 1 && node->flag_b == -1)
		return (case_four(pile_a, pile_b, node), (void)0);
	if (node->flag_a == -1 && node->flag_b == 1)
		return (case_five(pile_a, pile_b, node), (void)0);
}

void	case_zero(t_head *pile_a, t_head *pile_b, t_node *node)
{
	while (node->cost_a--)
	{
		rotate_both(pile_a, pile_b);
		node->cost_b--;
	}
	while (node->cost_b--)
		rotate_b(pile_b);
	push_a(pile_b, pile_a);
}

void	case_one(t_head *pile_a, t_head *pile_b, t_node *node)
{
	while (node->cost_b--)
	{
		rotate_both(pile_a, pile_b);
		node->cost_a--;
	}
	while (node->cost_a--)
		rotate_a(pile_a);
	push_a(pile_b, pile_a);
}

void	case_two(t_head *pile_a, t_head *pile_b, t_node *node)
{
	while (node->cost_a--)
	{
		reverse_rotate_both(pile_a, pile_b);
		node->cost_b--;
	}
	while (node->cost_b--)
		reverse_rotate_b(pile_b);
	push_a(pile_b, pile_a);
}

void    case_three(t_head *pile_a, t_head *pile_b, t_node *node)
{
	while (node->cost_b--)
	{
		reverse_rotate_both(pile_a, pile_b);
		node->cost_a--;
	}
	while (node->cost_a--)
		reverse_rotate_a(pile_a);
	push_a(pile_b, pile_a);
}
