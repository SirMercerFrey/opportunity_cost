#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
#include <unistd.h>

typedef struct s_head
{
	struct s_node	*first;
	struct s_node	*last;
	long			size;
}				t_head;

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	long			val;
	long			index;
	long			pos_a;
	long			pos_b;
	long			cost_a;
	long			cost_b;
	long			real_cost;
	int				flag_a;
	int				flag_b;
}				t_node;

t_head	*create_pile(void);
t_node	*create_element(int val);
void	ft_lst_add_back(t_head **pile, t_node *elem);
void	print_piles(t_head *pile_a, t_head *pile_b);
void	free_pile(t_head *pile);
int	is_spaces(char c);
int is_operator(char c);
int ft_atoi(char *str);
int	count_words(char *str);
char	*extract_word(char *str);
void	free_words(char **split, int i);
char    **ft_split_by_space(char *str);
void    free_split(char **split);  
int is_valid_number(char *str);
void	preambule(int argc, char **argv, t_head *pile_a);
void	swap_int(int *a, int *b);
int	partition(int *tab, int start, int end);
void	quick_sort(int *tab, int start, int end);
int	*create_tab(t_head *pile);
void give_index(t_head *pile, int *tab);
int	check_doublons(t_head *pile);
int    swap(t_head *pile);
void    swap_a(t_head *pile_a);
void    swap_b(t_head *pile_b);
void    swap_both(t_head *pile_a, t_head *pile_b);
int    push(t_head *from, t_head *to);
void    push_a(t_head *pile_b, t_head *pile_a);
void    push_b(t_head *pile_a, t_head *pile_b);
int	rotate(t_head *pile);
void	rotate_a(t_head *pile_a);
void	rotate_b(t_head *pile_b);
void	rotate_both(t_head *pile_a, t_head *pile_b);
int    reverse_rotate(t_head *pile);
void    reverse_rotate_a(t_head *pile_a);
void    reverse_rotate_b(t_head *pile_b);
void    reverse_rotate_both(t_head *pile_a, t_head *pile_b);


void    hardcode_three(t_head *pile);
void	cost_sort(t_head *pile_a, t_head *pile_b);
void    put_pos_in_b(t_head *pile_b);
void    put_cost_in_b(t_head *pile_b);
long	find_pos_just_bigger_in_a(t_head *pile_a, t_node *node);
long	find_pos_way_smaller_in_a(t_head *pile_a);
void    put_pos_in_a(t_head *pile_a, t_head *pile_b);
void    put_cost_in_a(t_head *pile_a, t_head *pile_b);
void    put_real_cost(t_head *pile_b);
t_node  *find_smallest_cost(t_head *pile_b);
void    chose_cases(t_head *pile_a, t_head*pile_b, t_node *node);
void    case_zero(t_head *pile_a, t_head *pile_b, t_node *node);
void    case_one(t_head *pile_a, t_head *pile_b, t_node *node);
void    case_two(t_head *pile_a, t_head *pile_b, t_node *node);
void    case_three(t_head *pile_a, t_head *pile_b, t_node *node);
void    case_four(t_head *pile_a, t_head *pile_b, t_node *node);
void    case_five(t_head *pile_a, t_head *pile_b, t_node *node);
void    find_and_move_index_zero(t_head *pile_a);

void    execute_instruction(char *line, t_head *pile_a, t_head *pile_b);
int is_sorted(t_head *pile_a);
int ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
