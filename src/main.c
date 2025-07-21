/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:45:31 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/21 15:54:19 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_head	*pile_a;
	t_head	*pile_b;
	int		*tab;

	pile_a = create_pile();
	pile_b = create_pile();
	if (argc < 2)
		return (printf("\n"));
	preambule(argc, argv, pile_a);
	tab = create_tab(pile_a);
	quick_sort(tab, 0, pile_a->size - 1);
	give_index(pile_a, tab);
	if (check_doublons(pile_a))
		return (printf("Error\n"));
//	print_piles(pile_a, pile_b);
	cost_sort(pile_a, pile_b);
//	print_piles(pile_a, pile_b);
	free_pile(pile_a);
	free_pile(pile_b);
	return (0);
}
