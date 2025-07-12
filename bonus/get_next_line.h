/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:08:34 by #+#    #+#             */
/*   Updated: 2025/05/12 15:08:34 by ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> //REMOVE FOR PUSH
# include <stdlib.h>
# include <fcntl.h> //REMOVE FOR PUSH
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	read_and_stash(int fd, t_list **stash);
void	add_to_stash(t_list **stash, char *buf, int lectum);
void	extract_line(t_list	*stash, char **line);
void	clean_stash(t_list **stash);
void	generate_line(char **line, t_list *stash);
int		found_endl(t_list *stash);
t_list	*ft_lst_get_last(t_list *stash);
void	free_stash(t_list *stash);
t_list	*create_leftovers_node(int len, int i);

#endif
