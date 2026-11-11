/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didias-d <didias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:29:45 by didias-d          #+#    #+#             */
/*   Updated: 2026/11/10 15:29:45 by didias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_to_stash(int fd, char *stash);
size_t	ft_strlen(const char *s);
char	*ft_clean_stash(char *stash);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_newline(char *stash);
char	*ft_extract_line(char *stash);

#endif