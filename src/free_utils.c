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
	free(pile_a);
	free(pile_b);
	free(tab);
}

void	free_piles(t_head *pile_a, t_head *pile_b)
{
	free(pile_a);
	free(pile_b);
}
