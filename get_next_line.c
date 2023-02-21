/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berbay <berbay@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:35:06 by berbay            #+#    #+#             */
/*   Updated: 2023/02/21 17:59:34 by berbay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_new_line(str);
	str = ft_new_str(str);
	return (line);
}
