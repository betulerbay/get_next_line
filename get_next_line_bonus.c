/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berbay <berbay@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:35:06 by berbay            #+#    #+#             */
/*   Updated: 2023/02/21 18:01:20 by berbay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *str)
{
	int		rd;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (!ft_n(str) && rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		*(buffer + rd) = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*strs[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	strs[fd] = ft_read(fd, strs[fd]);
	if (!strs[fd])
		return (NULL);
	line = ft_new_line(strs[fd]);
	strs[fd] = ft_new_str(strs[fd]);
	return (line);
}
