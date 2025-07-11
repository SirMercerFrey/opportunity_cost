/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:34:31 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/11 18:15:34 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_four(t_head *pile_a, t_head *pile_b, t_node *node)
{
	while (node->cost_a--)
		rotate_a(pile_a);
	while (node->cost_b--)
		reverse_rotate_b(pile_b);
	push_a(pile_b, pile_a);
}

void	case_five(t_head *pile_a, t_head *pile_b, t_node *node)
{
	while (node->cost_a--)
		reverse_rotate_a(pile_a);
	while (node->cost_b--)
		rotate_b(pile_b);
	push_a(pile_b, pile_a);
}	
