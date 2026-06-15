/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:27:52 by mvignes           #+#    #+#             */
/*   Updated: 2026/01/30 13:52:07 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_read_and_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr_gnl(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*ft_extract_line(char *stash)
{
	int	len;

	len = ft_strlen_i(stash);
	return (ft_substr_gnl(stash, 0, len + 1));
}

char	*ft_update_stash(char *stash)
{
	char	*newline_pos;
	char	*new_stash;
	int		start_index;

	if (!stash)
		return (NULL);
	newline_pos = ft_strchr_gnl(stash, '\n');
	if (!newline_pos || newline_pos[1] == '\0')
		return (free(stash), NULL);
	start_index = newline_pos - stash + 1;
	new_stash = ft_substr_gnl(stash, start_index, ft_strlen_gnl(newline_pos
				+ 1));
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_and_stash(fd, stash);
	if (!stash || stash[0] == '\0')
		return (free(stash), stash = NULL, NULL);
	line = ft_extract_line(stash);
	if (!line || line[0] == '\0')
		return (free(line), NULL);
	stash = ft_update_stash(stash);
	return (line);
}
