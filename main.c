/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berbay <berbay@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:22:33 by berbay            #+#    #+#             */
/*   Updated: 2023/02/21 17:47:19 by berbay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;

	fd = open("main.c", O_RDONLY);

	char *str = get_next_line(fd);

	while (str)
	{
		printf ("%s", str);
		free(str);
		str = get_next_line(fd);
	}
}
