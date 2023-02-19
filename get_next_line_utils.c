/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berbay <berbay@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:53:51 by berbay            #+#    #+#             */
/*   Updated: 2023/02/19 19:13:52 by berbay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen (char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strjoin (char *str1, char *str2)
{
	int	i;
	int	j;
	char	*ptr;

	if (!str1)
	{
		str1 = malloc(1);
		str1[0] = '\0';
	}
	ptr = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[j])
		ptr[i++] = str1[j++];
	j = 0;
	while (str2[j])
		ptr[i++] = str2[j++];
	*(ptr + i + j) = '\0';
	system("leaks a.out");
	free(str1);
	return (ptr);
}

char	*ft_new_str(char *str)
{
	int i;
	int	j;
	static char	*new;

	i = 0;
	j = 0;
	while(*(str + i) != '\n' && *(str + i))
		i++;
	if (!str)
	{
		free(str);
		return (NULL);
	}
	new = malloc(sizeof(char) * ft_strlen(str) - i + 1);
	i++;
	if(!new)
		return (NULL);
	while (*(str + i))
	{
		*(new + j++) = *(str + i++);
	}
	*(new + j) = '\0';
	free(str);
	return(new);
}

char	*ft_line(char *ptr)
{
	int i;
	char *ptr2;

	i = 0;
	while (ptr[i] != '\n' && *(ptr + i))
		i++;
	ptr2 = malloc(sizeof(char) * (i + 2));
	if (!ptr2)
		return (NULL);
	i = 0;
	while (*(ptr + i) != '\n' && *(ptr + i))
	{
		ptr2[i] = *(ptr + i);
		i++;
	}
	if (ptr[i] == '\n')
	{
		*(ptr2 + i) = '\n';
		i++;
	}
	*(ptr2 + i) = '\0';
	return (ptr2);
}
