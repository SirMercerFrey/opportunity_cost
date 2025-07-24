/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:12:58 by mcharret          #+#    #+#             */
/*   Updated: 2025/07/21 16:51:19 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h" 
#include "get_next_line.h"

void	execute_instruction(char *line, t_head *pile_a, t_head *pile_b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap(pile_a);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(pile_b);
	else if (!ft_strncmp(line, "ss\n", 3))
		swap_both(pile_a, pile_b);
	else if (!ft_strncmp(line, "pa\n", 3))
		push(pile_b, pile_a);
	else if (!ft_strncmp(line, "pb\n", 3))
		push(pile_a, pile_b);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate(pile_a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(pile_b);
	else if (!ft_strncmp(line, "rr\n", 3))
		rotate_both(pile_a, pile_b);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate(pile_a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate(pile_b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		reverse_rotate_both(pile_a, pile_b);
	else
		wrong_instruction(line, pile_a, pile_b);
}

int	is_sorted(t_head *pile_a)
{
	t_node	*tmp;

	tmp = pile_a->first;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (!s1[i])
			break ;
		++i;
	}
	return (0);
}

void	checking_sort(t_head *pile_a, t_head *pile_b)
{
	if (is_sorted(pile_a) && !pile_b->size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
