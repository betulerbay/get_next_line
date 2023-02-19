/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berbay <berbay@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:21:05 by berbay            #+#    #+#             */
/*   Updated: 2023/02/19 19:14:07 by berbay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char *ft_read(int fd, char *str)
{
	int rd;
	char *buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		*(buffer + rd) = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

char *get_next_line(int fd)
{
	char *line;
	static char *str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_new_str(str);
	return (line);
}

int main()
{
	int fd;
	fd = open("d.txt", O_RDONLY);
	printf("%s", get_next_line(fd));


}