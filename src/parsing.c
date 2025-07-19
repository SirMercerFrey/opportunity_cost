#include "push_swap.h"

void	preambule(int argc, char **argv, t_head *pile_a)
{
	char	**split;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		split = ft_split_by_space(argv[i]);
		if (!split)
			return ;
		j = 0;
		while (split[j])
		{
			if(!is_valid_number(split[j]))
			{
				printf("Error\n");
				free_split(split);
				exit(EXIT_FAILURE);
			}
			ft_lst_add_back(&pile_a, create_element(ft_atoi(split[j])));
			++j;
		}
		free(split);
		++i;
	}
}

int	check_doublons(t_head *pile)
{
	t_node	*current;
	t_node	*runner;

	current = pile->first;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (runner->val == current->val)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_valid_number(char *str)
{
	long	num;
	int		sign;

	if (!str || *str == '\0')
		return (0);
	sign = 1;
	if (is_operator(*str))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (0);
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && -num < INT_MIN))
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
	return (1);
}
