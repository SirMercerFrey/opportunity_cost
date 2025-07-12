/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:15:49 by #+#    #+#             */
/*   Updated: 2025/05/12 15:15:49 by ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

//Read from file descriptor and add to linked list
//Extract from stash to line
//Clean up stash
char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_and_stash(fd, &stash);
	if (!stash)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (!line || !*line)
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

//Uses read() to add characters to the stash
void	read_and_stash(int fd, t_list **stash)
{
	char	*buf;
	int		lectum;

	lectum = 1;
	while (!found_endl(*stash) && lectum)
	{
		buf = (char *)(malloc(sizeof(char) * (BUFFER_SIZE + 1)));
		if (!buf)
			return ;
		lectum = (int)read(fd, buf, BUFFER_SIZE);
		if (lectum <= 0)
		{
			free(buf);
			if (lectum == -1)
			{
				free_stash(*stash);
				*stash = NULL;
			}
			return ;
		}
		buf[lectum] = '\0';
		add_to_stash(stash, buf, lectum);
		free(buf);
	}
}

//Adds the content of buffer to the end of stash
void	add_to_stash(t_list **stash, char *buf, int lectum)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = (t_list *)(malloc(sizeof(t_list)));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = (char *)(malloc(sizeof(char) * (lectum + 1)));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < lectum)
	{
		new_node->content[i] = buf[i];
		++i;
	}
	new_node->content[i] = '\0';
	if (!*stash)
	{
		*stash = new_node;
		return ;
	}
	last = ft_lst_get_last(*stash);
	last->next = new_node;
}

//Extract stash to line until \n
void	extract_line(t_list	*stash, char **line)
{
	int		i;
	int		j;

	if (!stash)
		return ;
	generate_line(line, stash);
	if (!line || !*line)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				(*line)[j] = '\0';
				return ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

// Clears the stash so only characters that have not been returned at the
// end of get_nest_line remain in our static stash
void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*leftovers;
	char	*ptr;
	int		i;
	int		len;

	if (!stash)
		return ;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		++i;
	if (last->content[i] && last->content[i] == '\n')
		++i;
	len = 0;
	while (last->content[len])
		++len;
	leftovers = create_leftovers_node(len, i);
	ptr = leftovers->content;
	while (last->content[i])
		*ptr++ = last->content[i++];
	*ptr = '\0';
	free_stash(*stash);
	*stash = leftovers;
}
