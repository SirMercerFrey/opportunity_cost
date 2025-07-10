#include "push_swap.h"

void	hardcode_three(t_head *pile)
{
	int		f;
	int		s;
	int		t;

	f = pile->first->index;
	s = pile->first->next->index;
	t = pile->first->next->next->index;
	if (f < s && s < t) 
		return ;
	if (f < t && t < s) 
	{
		reverse_rotate_a(pile);
		swap_a (pile);
	}
	if (s < f && f < t)
		swap_a(pile);
	if (t < f && f < s)
		reverse_rotate_a(pile);
	if (t < s && s < f)
	{
		swap_a(pile);
		reverse_rotate_a(pile);
	}
	if (s < t && t < f)
		rotate_a(pile);
}

void cost_sort(t_head *pile_a, t_head *pile_b)
{
	t_node	*chosen_one;
	long	size;

	size = pile_a->size;
	while (pile_a->size > 3)
	{
		push_b(pile_a, pile_b);
		if (size > 100 && pile_b->first->index <= size / 2)
			rotate_b(pile_b);
	}
//	make_chunks(pile_a, pile_b);
	hardcode_three(pile_a);
//	print_piles(pile_a, pile_b);
	while (pile_b->size)
	{
//		printf("put pos in b\n");
		put_pos_in_b(pile_b);
//		print_piles(pile_a, pile_b);
//		printf("put cost in b\n");
		put_cost_in_b(pile_b);
//		print_piles(pile_a, pile_b);
//		printf("put pos in a\n");
		put_pos_in_a(pile_a, pile_b);
//		print_piles(pile_a, pile_b);
//		printf("put cost in a\n");
		put_cost_in_a(pile_a, pile_b);
//		print_piles(pile_a, pile_b);
//		printf("real cost\n");
		put_real_cost(pile_b);
//		print_piles(pile_a, pile_b);
		chosen_one = find_smallest_cost(pile_b);
//		printf("smallest cost %ld[%ld]\n", chosen_one->val, chosen_one->index);
		chose_cases(pile_a, pile_b, chosen_one);
	}
	find_and_move_index_zero(pile_a);

}

void	put_pos_in_b(t_head *pile_b)
{
	t_node	*tmp;
	long	pos;

	pos = 0;
	tmp = pile_b->first;
	while (tmp)
	{
		tmp->pos_b = pos;
		++pos;
		tmp = tmp->next;
	}
}

void	put_cost_in_b(t_head *pile_b)
{
	t_node	*tmp;

	tmp = pile_b->first;
	while (tmp)
	{
		tmp->cost_b = tmp->pos_b;
		tmp->flag_b = 1;
		if (tmp->pos_b > pile_b->size / 2)
		{
			tmp->cost_b = pile_b->size - tmp->pos_b;
			tmp->flag_b = -1;
		}
		tmp = tmp->next;
	}
}

long	find_pos_just_bigger_in_a(t_head *pile_a, t_node *node)
{
	t_node	*tmp;
	long	index_just_bigger;
	long	pos_just_bigger;
	long	pos;

	tmp = pile_a->first;
	pos = 0;
	pos_just_bigger = -1;
	index_just_bigger = LONG_MAX;
	while (tmp)
	{
		if (tmp->index > node->index && tmp->index < index_just_bigger)
		{
			index_just_bigger = tmp->index;
			pos_just_bigger = pos;
		}
		++pos;
		tmp = tmp->next;
	}
	if (pos_just_bigger == -1)
		return (find_pos_way_smaller_in_a(pile_a));
	return (pos_just_bigger);
}

long	find_pos_way_smaller_in_a(t_head *pile_a)
{
	t_node	*tmp;
	long	index_way_smaller;
	long	pos_way_smaller;
	long	pos;

	tmp = pile_a->first;
	pos = 0;
	index_way_smaller = LONG_MAX;
	while (tmp)
	{
		if (tmp->index < index_way_smaller)
		{
			index_way_smaller = tmp->index;
			pos_way_smaller = pos;
		}
		++pos;
		tmp = tmp->next;
	}
	return (pos_way_smaller);
}

void	put_pos_in_a(t_head *pile_a, t_head *pile_b)
{
	t_node	*tmp;

	tmp = pile_b->first;
	while (tmp)
	{
		tmp->pos_a = find_pos_just_bigger_in_a(pile_a, tmp);
		tmp = tmp->next;
	}
}

void	put_cost_in_a(t_head *pile_a, t_head *pile_b)
{
	t_node	*tmp;

	tmp = pile_b->first;
	while (tmp)
	{
		tmp->cost_a = tmp->pos_a;
		tmp->flag_a = 1;
		if (tmp->pos_a > pile_a->size / 2)
		{
			tmp->cost_a = pile_a->size - tmp->pos_a;
			tmp->flag_a = -1;
		}
		tmp = tmp->next;
	}
}

void	put_real_cost(t_head *pile_b)
{
	t_node	*tmp;

	tmp = pile_b->first;
	while (tmp)
	{
		if (tmp->flag_a != tmp->flag_b)
			tmp->real_cost = tmp->cost_a + tmp->cost_b;
		if (tmp->flag_a == tmp->flag_b && tmp->cost_a <= tmp->cost_b)
			tmp->real_cost = tmp->cost_b;
		if (tmp->flag_a == tmp->flag_b && tmp->cost_a > tmp->cost_b)
			tmp->real_cost = tmp->cost_a;
		tmp = tmp->next;
	}
}

t_node	*find_smallest_cost(t_head *pile_b)
{
	t_node	*tmp;
	t_node	*little_thumb;
	long	smallest_cost;

	tmp = pile_b->first;
	smallest_cost = LONG_MAX;
	while (tmp)
	{
		if (tmp->real_cost < smallest_cost)
		{
			little_thumb = tmp;
			smallest_cost = tmp->real_cost;
		}
		tmp = tmp->next;
	}
	return (little_thumb);
}
			
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

void	find_and_move_index_zero(t_head *pile_a)
{
	t_node	*tmp;
	long	pos;

	pos = 0;
	tmp = pile_a->first;
	while (tmp)
	{
		if (tmp->index == 0)
			break;
		++pos;
		tmp = tmp->next;
	}
	if (pos > pile_a->size / 2)
	{
		pos = pile_a->size - pos;
		while (pos--)
			reverse_rotate_a(pile_a);
	}
	else
	{
		while (pos--)
			rotate_a(pile_a);
	}
}
