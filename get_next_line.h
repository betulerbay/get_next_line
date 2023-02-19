/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berbay <berbay@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:53:48 by berbay            #+#    #+#             */
/*   Updated: 2023/02/19 15:45:13 by berbay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

int		ft_strlen (char *str);

char	*ft_strjoin (char *str1, char *str2);

char	*ft_new_str(char *str);

char	*ft_line(char *ptr);

char	*ft_read(int fd, char *str);

char	*get_next_line(int fd);

#endif
