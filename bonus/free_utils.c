#include "push_swap_bonus.h"

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

void	wrong_instruction(char *line, t_head *pile_a, t_head *pile_b)
{
	free(line);
	write(1, "Error\n", 6);
	free_piles(pile_a, pile_b);
	exit(EXIT_FAILURE);
}
