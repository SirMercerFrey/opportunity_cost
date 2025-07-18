#include "push_swap_bonus.h"

int	rotate(t_head *pile)
{
	t_node	*first;
	t_node	*second;

	if (!pile || pile->size < 2)
		return (0);
	first = pile->first;
	second = first->next;
	second->prev = NULL;
	pile->first = second;
	first->next = NULL;
	first->prev = pile->last;
	pile->last->next = first;
	pile->last = first;
	return (1);
}

void	rotate_a(t_head *pile_a)
{
	if (rotate(pile_a))
		printf("ra\n");
}

void	rotate_b(t_head *pile_b)
{
	if (rotate(pile_b))
		printf("rb\n");
}

void	rotate_both(t_head *pile_a, t_head *pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
}

int	reverse_rotate(t_head *pile)
{
	t_node	*last;
	t_node	*before_last;

	if (!pile || pile->size < 2)
		return (0);

	last = pile->last;
	before_last = last->prev;
	before_last->next = NULL;
	pile->last = before_last;
	last->next = pile->first;
	last->prev = NULL;
	pile->first->prev = last;
	pile->first = last;
	return (1);
}

void	reverse_rotate_a(t_head *pile_a)
{
	if (reverse_rotate(pile_a))
		printf("rra\n");
}

void	reverse_rotate_b(t_head *pile_b)
{
	if (reverse_rotate(pile_b))
		printf("rrb\n");
}

void	reverse_rotate_both(t_head *pile_a, t_head *pile_b)
{
	reverse_rotate(pile_a);
	reverse_rotate(pile_b);
}
