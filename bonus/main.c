/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:22:46 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/21 16:54:02 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	t_head	*pile_a;
	t_head	*pile_b;
	char	*line;

	pile_a = create_pile();
	pile_b = create_pile();
	if (argc < 2)
	{
		free_piles(pile_a, pile_b);
		return (printf("\n"));
	}
	preambule(argc, argv, pile_a, pile_b);
	if (!pile_a->size)
	{
		free_piles(pile_a, pile_b);
		return (printf("Error\n"));
	}
	if (check_doublons(pile_a))
	{
		free_piles(pile_a, pile_b);
		return (printf("Error\n"));
	}
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execute_instruction(line, pile_a, pile_b);
		free(line);
	}
	checking_sort(pile_a, pile_b);
	free_piles(pile_a, pile_b);
	return (0);
}
