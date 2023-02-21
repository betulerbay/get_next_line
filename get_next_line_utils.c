/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berbay <berbay@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:45:07 by berbay            #+#    #+#             */
/*   Updated: 2023/02/21 17:28:39 by berbay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i))
	{
		if (*(str + i) == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		*s1 = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (*(s1 + ++i))
		*(str + i) = *(s1 + i);
	while (*(s2 + ++j))
		*(str + i + j) = *(s2 + j);
	*(str + i + j) = '\0';
	free(s1);
	return (str);
}

char	*ft_new_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!*(str + i))
		return (NULL);
	while (*(str + i) != '\n' && *(str + i))
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (*(str + i) != '\n' && *(str + i))
	{
		*(line + i) = *(str + i);
		i ++;
	}
	if (*(str + i) == '\n')
	{
		*(line + i) = '\n';
		i ++;
	}
	*(line + i) = '\0';
	return (line);
}

char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (*(str + i) != '\n' && *(str + i))
		i++;
	if(!*(str + i))
	{
		free(str);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new)
		return (NULL);
	i++;
	while (*(str + i))
		*(new + j++) = *(str + i++);
	*(new + j) = '\0';
	free(str);
	return (new);
}
