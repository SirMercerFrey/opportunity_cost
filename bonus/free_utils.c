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
