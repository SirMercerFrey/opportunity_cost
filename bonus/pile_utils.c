/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:14:27 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/21 16:15:09 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_head	*create_pile(void)
{
	t_head	*pile;

	pile = malloc(sizeof(t_head));
	if (!pile)
		return (NULL);
	pile->first = NULL;
	pile->last = NULL;
	pile->size = 0;
	return (pile);
}

t_node	*create_element(int val)
{
	t_node	*elem;

	elem = malloc(sizeof(t_node));
	if (!elem)
		return (NULL);
	elem->next = NULL;
	elem->prev = NULL;
	elem->val = val;
	elem->index = -1;
	elem->pos_a = -1;
	elem->pos_b = -1;
	elem->cost_a = -1;
	elem->cost_b = -1;
	elem->real_cost = -1;
	elem->flag_a = 0;
	elem->flag_b = 0;
	return (elem);
}

void	ft_lst_add_back(t_head **pile, t_node *elem)
{
	if ((*pile)->size == 0)
	{
		(*pile)->first = elem;
		(*pile)->last = elem;
		++(*pile)->size;
		return ;
	}
	(*pile)->last->next = elem;
	elem->prev = (*pile)->last;
	(*pile)->last = elem;
	++(*pile)->size;
}

void	free_pile(t_head *pile)
{
	t_node	*tmp;

	if (!pile)
		return ;
	while (pile->first)
	{
		tmp = pile->first;
		pile->first = pile->first->next;
		free(tmp);
	}
	free(pile);
}
