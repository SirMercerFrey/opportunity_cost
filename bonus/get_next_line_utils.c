/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:21:05 by #+#    #+#             */
/*   Updated: 2025/05/12 15:21:05 by ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	found_endl(t_list *stash)
{
	t_list	*current;
	char	*ptr;

	if (!stash)
		return (0);
	current = ft_lst_get_last(stash);
	if (!current || !current->content)
		return (0);
	ptr = current->content;
	while (*ptr)
	{
		if (*ptr == '\n')
			return (1);
		++ptr;
	}
	return (0);
}

t_list	*ft_lst_get_last(t_list	*stash)
{
	if (!stash)
		return (NULL);
	while (stash->next)
		stash = stash->next;
	return (stash);
}

void	generate_line(char **line, t_list *stash)
{
	char	*ptr;
	int		len;

	len = 0;
	while (stash)
	{
		ptr = stash->content;
		while (*ptr)
		{
			if (*ptr == '\n')
			{
				++len;
				break ;
			}
			++len;
			++ptr;
		}
		if (ptr && *ptr == '\n')
			break ;
		stash = stash->next;
	}
	*line = (char *)(malloc(sizeof(char) * (len + 1)));
}

void	free_stash(t_list *stash)
{
	t_list	*next;

	if (!stash)
		return ;
	while (stash)
	{
		free(stash->content);
		next = stash->next;
		free(stash);
		stash = next;
	}
}

t_list	*create_leftovers_node(int len, int i)
{
	t_list	*leftovers;

	leftovers = (t_list *)(malloc(sizeof(t_list)));
	if (!leftovers)
		return (NULL);
	leftovers->content = (char *)(malloc(sizeof(char) * (len - i + 1)));
	if (!leftovers->content)
	{
		free(leftovers);
		return (NULL);
	}
	leftovers->next = NULL;
	return (leftovers);
}
