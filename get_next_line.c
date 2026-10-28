/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didias-d <didias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 16:26:51 by didias-d          #+#    #+#             */
/*   Updated: 2026/10/24 16:26:51 by didias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 42

int main(void)
{
	int	fd;
	char	*ligne;

	fd = open("test.txt", O_RDONLY);

	ligne = get_next_line(fd);
	printf("premier appel : %s", ligne);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{

}

int	ft_strchr_newline(char *stash)
{
	int	i;

	if (stash == NULL)
		return (0);

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}


char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr_newline(stash) == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
	}
	free(buffer);
}
