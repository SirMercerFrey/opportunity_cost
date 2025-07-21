/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:14:23 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/21 18:26:20 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_piles_tab(t_head *pile_a, t_head *pile_b, int *tab)
{
	free_pile(pile_a);
	free_pile(pile_b);
	free(tab);
}

void	free_piles(t_head *pile_a, t_head *pile_b)
{
	free_pile(pile_a);
	free_pile(pile_b);
}

void	edge_sort(t_head *pile_a)
{
	if (pile_a->size == 1)
		return ;
	if (pile_a->first->index > pile_a->first->next->index)
		swap_a(pile_a);
}
